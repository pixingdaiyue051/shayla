#include <stdio.h>
#include <stdlib.h>
#include "stack_def.h"

/**
 * 创建节点
 * */
stack_t *ss_create(double d)
{
    stack_t *e = malloc(sizeof(stack_t));
    e->data = d;
    e->next = NULL;
    return e;
}

/**
 * 入栈
 * */
void ss_push(double d)
{
    if (!ss_top)
    {
        ss_top = ss_create(d);
    }
    else
    {
        stack_t *e = ss_create(d);
        e->data = d;
        e->next = ss_top;
        ss_top = e;
    }
}

/**
 * 读栈顶元素
 * */
double ss_read()
{
    if (!ss_top)
    {
        return 0.0;
    }
    return ss_top->data;
}

/**
 * 出栈
 * */
double ss_pop()
{
    if (!ss_top)
    {
        return 0.0;
    }
    double d = ss_top->data;
    stack_t *p = ss_top;
    ss_top = ss_top->next;
    free(p);
    return d;
}

/**
 * 清空栈
 * */
void ss_free(stack_t *e)
{
    if (e->next)
    {
        ss_free(e->next);
    }
    free(e);
}

/**
 * 先进后出 输出所有数据
 * */
void ss_print(stack_t *e)
{
    printf("%.3f\n", e->data);
    if (e->next)
    {
        ss_print(e->next);
    }
}