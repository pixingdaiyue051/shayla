#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 结构体
typedef struct BOOK
{
    char title[50];
    char author[50];
    char subject[50];
    int id;
} book_t;

// 位域
typedef struct BITAREA
{
    unsigned int a : 1;
    unsigned int b : 4;
} bitarea_t;

// 共同体
typedef union DATA
{
    int i;
    float j;
    double k;
    char z[20];
} data_t;

void print_book(book_t book)
{
    printf("title %s\n", book.title);
    printf("author %s\n", book.author);
    printf("subject %s\n", book.subject);
    printf("id %d\n", book.id);
}

void print_book2(book_t *book)
{
    printf("title %s\n", book->title);
    printf("author %s\n", book->author);
    printf("subject %s\n", book->subject);
    printf("id %d\n", book->id);
}

// 使用结构体构建静态双向链表
typedef struct LINKEDLIST
{
    struct LINKEDLIST *pre;
    int content;
    struct LINKEDLIST *next;
} linkedlist_t;

void print_linkedlist(linkedlist_t *l)
{
    printf("%d\n", l->content);
    if (NULL != l->next)
    {
        print_linkedlist(l->next);
    }
}

/**
 * 静态链表
 * */
linkedlist_t *static_linkedlist()
{
    linkedlist_t *l1 = malloc(sizeof(linkedlist_t));
    linkedlist_t *l2 = malloc(sizeof(linkedlist_t));
    linkedlist_t *l3 = malloc(sizeof(linkedlist_t));
    l1->pre = NULL;
    l1->content = 1;
    l1->next = l2;

    l2->pre = l1;
    l2->content = 2;
    l2->next = l3;

    l3->pre = l2;
    l3->content = 3;
    l3->next = NULL;
    return l1;
}

/**
 * 动态链表
 * */
linkedlist_t *dynamic_linkedlist()
{
    int i;
    int n = 1;
    linkedlist_t *head, *pre1;

    do
    {
        scanf("%d", &i);
        if (1 == n++)
        {
            linkedlist_t *e = malloc(sizeof(linkedlist_t));
            e->content = i;
            e->pre = NULL;
            pre1 = e;
            head = e;
            continue;
        }
        if (0 == i)
        {
            pre1->next = NULL;
            break;
        }
        linkedlist_t *e = malloc(sizeof(linkedlist_t));
        e->content = i;
        e->pre = pre1;
        pre1->next = e;
        pre1 = e;

    } while (1);

    return head;
}

int main()
{
    // char str[] = "do not go gentle into that good night";
    // printf("%p %s\n", &str, str);
    // printf("%lu %lu\n", strlen(str), sizeof(str));

    // book_t book1, book2;

    // strcpy(book1.title, "once upon a time in China");
    // strcpy(book1.author, "kiki");
    // strcpy(book1.subject, "once");
    // book1.id = 12222;
    // print_book(book1);

    // strcpy(book2.title, "once upon a time in China");
    // strcpy(book2.author, "kiki");
    // strcpy(book2.subject, "once");
    // book2.id = 442523;
    // print_book2(&book2);

    // data_t data1, data2;

    // data1.i = 10;
    // printf("data1.i : %d\n", data1.i);

    // data1.j = 220.5;
    // printf("data1.j : %f\n", data1.j);

    // data1.k = 220.5;
    // printf("data1.k : %f\n", data1.k);

    // strcpy(data1.z, "C Programming");
    // printf("data1.z : %s\n", data1.z);

    // bitarea_t b1, b2;

    // b1.a = 0;
    // b1.b = 2;
    // printf("%d\n", b1.a);

    // printf("%lu %lu %lu\n", sizeof(book1), sizeof(data1), sizeof(b1));

    linkedlist_t *head = static_linkedlist();
    print_linkedlist(head);

    linkedlist_t *head1 = dynamic_linkedlist();
    print_linkedlist(head1);

    return 0;
}
