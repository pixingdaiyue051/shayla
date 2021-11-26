#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ss_dt;

/**
 * 顺序栈
 * */
typedef struct SEQ_STACK
{
    ss_dt *data;
    int capacity;
    int top;
} ss_t;

ss_t *ss_init(int capacity)
{
    ss_t *stack = (ss_t *)malloc(sizeof(ss_t));
    // 分配capacity个大小为ss_dt的连续内存
    stack->data = (ss_dt *)calloc(capacity, sizeof(ss_dt));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

bool ss_is_full(ss_t *stack)
{
    return stack->top == stack->capacity - 1;
}

bool ss_is_empty(ss_t *stack)
{
    return stack->top == -1;
}

/**
 * 入栈
 * */
bool ss_push(ss_t *stack, ss_dt d)
{
    if (ss_is_full(stack))
    {
        return false;
    }
    // 栈顶索引自增
    ++stack->top;
    // 赋值栈顶
    stack->data[stack->top] = d;
    return true;
}

/**
 * 读栈顶元素
 * */
bool ss_peek(ss_t *stack, ss_dt *pm)
{
    if (ss_is_empty(stack))
    {
        return false;
    }
    *pm = stack->data[stack->top];
    return true;
}

/**
 * 出栈
 * */
bool ss_pop(ss_t *stack, ss_dt *pm)
{
    if (ss_peek(stack, pm))
    {
        // 栈顶索引自减
        --stack->top;
        return true;
    }
    return false;
}

/**
 * 清空栈
 * */
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