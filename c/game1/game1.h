#ifndef _HEAD_GAME1
#define _HEAD_GAME1

#define INIT_POINTS 10
#include "obj.h"


typedef struct {
    Object proto;
    int hit_points;
} Monster;

int monster_init(void *self);
int monster_attack(void *self, int damage);

typedef struct ROOM {
    Object proto;
    Monster *bad_guy;

    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
} Room;

int room_init(void *self);
void *room_move(void *self, Direction direction);
int room_attack(void *self, int damage);

typedef struct {
    Object proto;
    Room *start;
    Room *location;
} Map;

int map_init(void *self);
void *map_move(void *self, Direction direction);
int map_attack(void *self, int damage);

#endif