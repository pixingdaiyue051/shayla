#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "obj.h"

int obj_init(void *self)
{
    return 1;
}

void obj_describe(void *self)
{
    Object *obj = self;
    printf("%s\n", obj->description);
}

void obj_destroy(void *self)
{
    Object *obj = self;
    if (!obj)
    {
        return;
    }
    if (obj->description)
    {
        free(obj->description);
    }
    free(obj);
}

void *obj_move(void *self, Direction direction)
{
    printf("You can't go that direction.\n");
    return NULL;
}

int obj_attack(void *self, int damage)
{
    printf("You can't attack that.\n");
    return 0;
}

void *obj_new(int size, Object proto, char *description)
{
    if (!proto.init)
    {
        proto.init = obj_init;
    }
    if (!proto.describe)
    {
        proto.describe = obj_describe;
    }
    if (!proto.destroy)
    {
        proto.destroy = obj_destroy;
    }
    if (!proto.move)
    {
        proto.move = obj_move;
    }
    if (!proto.attack)
    {
        proto.attack = obj_attack;
    }

    Object *el = calloc(1, size);
    *el = proto;
    el->description = strdup(description);
    if (el->init(el))
    {
        return el;
    }
    el->destroy(el);
    return NULL;
}