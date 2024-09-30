#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game1.h"

int monster_init(void *self)
{
    Monster *monster = self;
    monster->hit_points = INIT_POINTS;
    return 1;
}

int monster_attack(void *self, int damage)
{
    Monster *monster = self;
    printf("you attack %s\n", monster->_(description));
    monster->hit_points -= damage;
    if (monster->hit_points > 0)
    {
        printf("it is still alive \n");
        return monster->hit_points;
    }
    else
    {
        printf("it is dead \n");
        return 0;
    }
}

Object MonsterProto = {.init = monster_init, .attack = monster_attack};

void *room_move(void *self, Direction direction)
{
    Room *room = self;
    Room *next = NULL;

    if (direction == NORTH && room->north)
    {
        printf("you go north, into:\n");
        next = room->north;
    }
    else if (direction == SOUTH && room->south)
    {
        printf("you go south, into:\n");
        next = room->south;
    }
    else if (direction == EAST && room->east)
    {
        printf("you go east, into:\n");
        next = room->east;
    }
    else if (direction == WEST && room->west)
    {
        printf("you go west, into:\n");
        next = room->west;
    }
    else
    {
        printf("you cannot go that direction\n");
        next = NULL;
    }

    if (next)
    {
        next->_(describe)(next);
    }
    return next;
}

int room_attack(void *self, int damage)
{
    Room *room = self;
    Monster *monster = room->bad_guy;
    if (monster)
    {
        return monster->_(attack)(monster, damage);
    }
    else
    {
        printf("you flail in the air at nothing \n");
        return INIT_POINTS;
    }
}

Object RoomProto = {.move = room_move, .attack = room_attack};

int map_init(void *self)
{
    Map *map = self;
    Room *hall = NEW(Room, "The great Hall");
    Room *throne = NEW(Room, "The throne room");
    Room *arena = NEW(Room, "The arena with minotaur");
    Room *kitchen = NEW(Room, "The kitchen with knife");

    arena->bad_guy = NEW(Monster, "The evil minotaur");
    hall->north = throne;

    throne->west = arena;
    throne->east = kitchen;
    throne->south = hall;

    arena->east = throne;

    kitchen->west = throne;

    map->start = hall;
    map->location = hall;

    return 1;
}

void *map_move(void *self, Direction direction)
{
    Map *map = self;
    Room *location = map->location;
    Room *next = location->_(move)(location, direction);
    if (next)
    {
        map->location = next;
    }
    return next;
}

int map_attack(void *self, int damage)
{
    Map *map = self;
    Room *location = map->location;
    return location->_(attack)(location, damage);
}

Object MapProto = {.init = map_init, .move = map_move, .attack = map_attack};

int process_input(Map *map)
{
    printf("\n> ");

    char ch = getchar();
    // 清空缓冲区
	while (getchar() != '\n')
		;

    int damage = rand() % 4; // 随机数 随机伤害值

    switch (ch)
    {
    case 'q':
        printf("you give up\n");
        printf("Game Over\n");
        return 0;
        break;
    case 'n':
        map->_(move)(map, NORTH);
        break;
    case 's':
        map->_(move)(map, SOUTH);
        break;
    case 'e':
        map->_(move)(map, EAST);
        break;
    case 'w':
        map->_(move)(map, WEST);
        break;
    case 'a':
    {
        int low = map->_(attack)(map, damage);
        if (low == 0)
        {
            printf("you killed the monster\n");
            printf("Congraduation\n");
            return 0;
        }
        break;
    }
    case 'l':
        printf("you can go:\n");
        if (map->location->north)
        {
            printf("NORTH\n");
        }
        if (map->location->south)
        {
            printf("SOUTH\n");
        }
        if (map->location->east)
        {
            printf("EAST\n");
        }
        if (map->location->west)
        {
            printf("WEST\n");
        }
        break;
    default:
        printf("what?: %d\n", ch);
        break;
    }
    return 1;
}

int main()
{
    srand(time(NULL)); // 每次启动都按时间戳重新生成随机数种子保证不会重复

    Map *map = NEW(Map, "The hall of minotaur");
    printf("you enter ");
    map->location->_(describe)(map->location);
    // printf("");
    while (process_input(map))
    {
    }
    return 0;
}