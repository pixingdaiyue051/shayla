/**
 * 顺序栈 预先设定好栈大小
 **/
#include <stdio.h>
#include <stdlib.h>
#include "seq_stack.h"

/**
 * 初始化栈
 **/
ss_t *ss_init(int capacity)
{
    ss_t *stack = (ss_t *)malloc(sizeof(ss_t));
    // 分配capacity个大小为ss_dt的连续内存
    stack->data = (ss_dt *)calloc(capacity, sizeof(ss_dt));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

/**
 * 判断栈是否已满
 **/
int ss_is_full(ss_t *stack)
{
    return stack->top == stack->capacity - 1;
}

/**
 * 判断栈是否空
 **/
int ss_is_empty(ss_t *stack)
{
    return stack->top == -1;
}

/**
 * 入栈
 **/
int ss_push(ss_t *stack, ss_dt d)
{
    if (ss_is_full(stack))
    {
        return 1;
    }
    // 栈顶索引自增
    ++stack->top;
    // 赋值栈顶
    stack->data[stack->top] = d;
    return 0;
}

/**
 * 读栈顶元素
 **/
int ss_peek(ss_t *stack, ss_dt *pm)
{
    if (ss_is_empty(stack))
    {
        return 0;
    }
    *pm = stack->data[stack->top];
    return 1;
}

/**
 * 出栈
 **/
int ss_pop(ss_t *stack, ss_dt *pm)
{
    if (ss_peek(stack, pm))
    {
        // 栈顶索引自减
        --stack->top;
        return 1;
    }
    return 0;
}

/**
 * 清空栈
 **/
void ss_free(ss_t *stack)
{
    free(stack->data);
    free(stack);
}

void ss_print(ss_t *stack)
{
    if (ss_is_empty(stack))
    {
        return;
    }
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d\t", stack->data[i]);
    }
    printf("\n");
}