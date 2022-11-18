#ifndef _HEAD_GAME1_OBJ
#define _HEAD_GAME1_OBJ

typedef enum
{
    NORTH,
    SOUTH,
    EAST,
    WEST
} Direction;

typedef struct OBJECT
{
    char *description;
    int (*init)(void *self);
    void (*describe)(void *self);
    void (*destroy)(void *self);
    void *(*move)(void *self, Direction direction);
    int (*attack)(void *self, int damage);
} Object;

int obj_init(void *self);
void obj_describe(void *self);
void obj_destroy(void *self);
void *obj_move(void *self, Direction direction);
int obj_attack(void *self, int damage);
void *obj_new(int size, Object proto, char *description);

// T##Proto语法表示“将Proto连接到T的末尾” NEW(Room, "Hello.")=>RoomProto
#define NEW(T,N) obj_new(sizeof(T), T##Proto, N)
// 利用宏定义实现语法糖 将obj->proto.blah简化为obj->_(blah)
#define _(N) proto.N

#endif