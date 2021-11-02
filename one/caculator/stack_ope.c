#include <stdio.h>
#include <stdlib.h>
#include "stack_ope_def.h"

/**
 * 创建节点
 * */
stack_ope_t *ope_create(char ope)
{
    stack_ope_t *e = (stack_ope_t *)malloc(sizeof(stack_ope_t));
    e->ope = ope;
    e->next = NULL;
    return e;
}

/**
 * 入栈
 * */
void ope_push(char ope)
{
    if (!ope_top)
    {
        ope_top = ope_create(ope);
    }
    else
    {
        stack_ope_t *e = ope_create(ope);
        e->ope = ope;
        e->next = ope_top;
        ope_top = e;
    }
}

/**
 * 读栈顶元素
 * */
char ope_peek()
{
    if (!ope_top)
    {
        return '_';
    }
    return ope_top->ope;
}

/**
 * 出栈
 * */
char ope_pop()
{
    if (!ope_top)
    {
        return '_';
    }
    char d = ope_top->ope;
    stack_ope_t *p = ope_top;
    ope_top = ope_top->next;
    free(p);
    return d;
}

/**
 * 清空栈
 * */
void ope_free(stack_ope_t *e)
{
    if (e && e->next)
    {
        ope_free(e->next);
    }
    free(e);
}