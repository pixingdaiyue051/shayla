#include <stdio.h>
#include <stdlib.h>
#include "stack_data_def.h"

/**
 * 创建节点
 * */
stack_data_t *dd_create(double data)
{
    stack_data_t *e = (stack_data_t *)malloc(sizeof(stack_data_t));
    e->data = data;
    e->next = NULL;
    return e;
}

/**
 * 入栈
 * */
void dd_push(double data)
{
    if (!dd_top)
    {
        dd_top = dd_create(data);
    }
    else
    {
        stack_data_t *e = dd_create(data);
        e->data = data;
        e->next = dd_top;
        dd_top = e;
    }
}

/**
 * 读栈顶元素
 * */
double dd_peek()
{
    if (!dd_top)
    {
        return 0.0;
    }
    return dd_top->data;
}

/**
 * 出栈
 * */
double dd_pop()
{
    if (!dd_top)
    {
        return 0.0;
    }
    double d = dd_top->data;
    stack_data_t *p = dd_top;
    dd_top = dd_top->next;
    free(p);
    return d;
}

/**
 * 清空栈
 * */
void dd_free(stack_data_t *e)
{
    if (e && e->next)
    {
        dd_free(e->next);
    }
    free(e);
}