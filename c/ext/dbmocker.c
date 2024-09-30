/**
 * 仿db
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

typedef struct ADDRESS
{
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
} address;

typedef struct DATABASE
{
    address rows[MAX_ROWS];
} database;

typedef struct CONNECTION
{
    FILE *file;
    database *db;
} connection;

void die(const char *msg)
{
    if (errno)
    {
        perror(msg);
    }
    else
    {
        printf("error:%s\n", msg);
    }
    exit(1);
}

void address_show(address *addr)
{
    printf("id %d\n", addr->id);
    printf("name %s\n", addr->name);
    printf("email %s\n", addr->email);
}

connection *database_open(const char *filename, const char mode)
{
    connection *conn = malloc(sizeof(connection));
    if (conn == NULL)
    {
        die("memory error");
    }
    database *db = malloc(sizeof(database));
    if (db == NULL)
    {
        die("memory error");
    }
    conn->db = db;

    FILE *file;
    if (mode == 'c')
    {
        file = fopen(filename, "w");
    }
    else
    {
        file = fopen(filename, "r+");
        if (file != NULL)
        {
            int rc = fread(db, sizeof(database), 1, file);
            // if (rc != 1)
            // {
            //     die("failed to load database");
            // }
        }
    }
    if (file == NULL)
    {
        die("failed to open file");
    }
    conn->file = file;
}

void database_close(connection *conn)
{
    if (conn == NULL)
    {
        return;
    }
    if (conn->file != NULL)
    {
        fclose(conn->file);
    }
    if (conn->db != NULL)
    {
        free(conn->db);
    }
    free(conn);
}

void database_write(connection *conn)
{
    rewind(conn->file);
    int rc = fwrite(conn->db, sizeof(database), 1, conn->file);
    if (rc != 1)
    {
        die("failed to write database");
    }
    rc = fflush(conn->file);
    if (rc == -1)
    {
        die("cannot flush database");
    }
}

void database_crt(connection *conn)
{

    int i;
    for (i = 0; i < MAX_ROWS; i++)
    {
        address addr = {.id = i, .set = 0};
        conn->db->rows[i] = addr;
    }
}

void database_set(connection *conn, int id, const char *name,const char *email)
{
    address *addr = &conn->db->rows[id];
    if (addr->set == 1)
    {
        die("already set");
    }
    addr->set = 1;
    char *res = strcpy(addr->name, name);
    if (res == NULL)
    {
        die("name copy failed");
    }
    res = strcpy(addr->email, email);
    if (res == NULL)
    {
        die("email copy failed");
    }
}

void database_get(connection *conn, int id)
{
    address *addr = &conn->db->rows[id];
    if (addr->set == 0)
    {
        die("id not set");
    }
    address_show(addr);
}

void database_del(connection *conn, int id)
{
    address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void database_list(connection *conn)
{
    int i;
    address *addr;
    database *db = conn->db;
    for (i = 0; i < MAX_ROWS; i++)
    {
        addr = &db->rows[i];
        if (addr->set == 1)
        {
            address_show(addr);
        }
    }
}

int main()
{
    if (argc < 3)
    {
        die("bad arguments");
    }
    const char *filename = argv[1];
    const char mode = argv[2][0];
    connection *conn = database_open(filename, mode);

    int id = 0;
    if (argc > 3)
    {
        id = atoi(argv[3]);
    }

    if (id >= MAX_ROWS)
    {
        die("too many records");
    }

    switch (mode)
    {
    case 'c':
        database_crt(conn);
        database_write(conn);
        break;
    case 'g':
        if (argc != 4)
        {
            die("no id");
        }
        database_get(conn, id);
        break;
    case 's':
        if (argc != 6)
        {
            die("no id, name, email");
        }
        database_set(conn, id, argv[4], argv[5]);
        database_write(conn);
        break;
    case 'd':
        if (argc != 4)
        {
            die("no id");
        }
        database_del(conn, id);
        database_write(conn);
        break;
    case 'l':
        database_list(conn);
        break;
    default:
        die("bad arguments");
        break;
    }
    database_close(conn);

    return 0;
}