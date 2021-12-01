#include <stdio.h>
#include <stdlib.h>

typedef int cl_dt;

/**
 * 双向循环链表
 * */
typedef struct CIRCLE_LIST
{
    struct CIRCLE_LIST *pre;
    cl_dt data;
    struct CIRCLE_LIST *next;
} cl_t;

static inline cl_t *__cl_create(cl_dt data)
{
    cl_t *e = (cl_t *)malloc(sizeof(cl_t));
    e->data = data;
    e->pre = e->next = e;
    return e;
}

cl_t *cl_init(cl_dt data)
{
    return __cl_create(data);
}

cl_t *cl_append(cl_t *pos, cl_dt data)
{
    cl_t *e = __cl_create(data);
    e->next = pos->next;
    pos->next->pre = e;
    e->pre = pos;
    pos->next = e;
    return e;
}

cl_t *cl_insert(cl_t *pos, cl_dt data)
{
    cl_t *e = __cl_create(data);
    e->pre = pos->pre;
    pos->pre->next = e;
    e->next = pos;
    pos->pre = e;
    return e;
}

void cl_del(cl_t *pos)
{
    pos->next->pre = pos->pre;
    pos->pre->next = pos->next;
    free(pos);
}

static inline void __cl_free(cl_t *pos, cl_t *pos1)
{
    if (pos != pos1)
    {
        __cl_free(pos, pos1->next);
    }
    free(pos1);
}

/**
 * 从任意节点开始清空链表
 * */
void cl_free(cl_t *pos)
{
    __cl_free(pos, pos->next);
}

/**
 * 从任意节点开始顺序输出全部节点
 * */
void cl_next_print(cl_t *pos)
{
    printf("%d\n", pos->data);
    for (cl_t *e = pos->next; e != pos; e = e->next)
    {
        printf("%d\n", e->data);
    }
}

/**
 * 从任意节点开始倒序输出全部节点
 * */
void cl_pre_print(cl_t *pos)
{
    printf("%d\n", pos->data);
    for (cl_t *e = pos->pre; e != pos; e = e->pre)
    {
        printf("%d\n", e->data);
    }
}