/**
 * 链式栈 无需设定栈的大小
 **/
#include <stdio.h>
#include <stdlib.h>
#include "linked_stack.h"

/**
 * 初始化栈
 **/
ls_t *ls_init()
{
    ls_t *stack = (ls_t *)malloc(sizeof(ls_t));
    stack->size = 0;
    stack->top = NULL;
    return stack;
}

/**
 * 判断栈是否空
 **/
int ls_is_empty(ls_t *stack)
{
    return stack == NULL || stack->size == 0;
}

static inline sn_t *__ls_create(ls_dt data)
{
    sn_t *node = (sn_t *)malloc(sizeof(sn_t));
    node->data = data;
    node->next = NULL;
    return node;
}

/**
 * 入栈
 **/
int ls_push(ls_t *stack, ls_dt data)
{
    sn_t *node = __ls_create(data);
    // 新节点后继节点指向当前栈顶
    node->next = stack->top;
    // 栈顶指向新节点
    stack->top = node;
    ++stack->size;
    return 1;
}

/**
 * 读栈顶元素
 **/
int ls_peek(ls_t *stack, ls_dt *pm)
{
    if (ls_is_empty(stack))
    {
        return 0;
    }
    *pm = stack->top->data;
    return 1;
}

/**
 * 出栈
 **/
int ls_pop(ls_t *stack, ls_dt *pm)
{
    if (ls_peek(stack, pm))
    {
        sn_t *s = stack->top;
        // 栈顶向下移到下一个节点
        stack->top = s->next;
        free(s);
        --stack->size;
        return 1;
    }
    return 0;
}

static inline void __ls_free(sn_t *s)
{
    if (s->next != NULL)
    {
        __ls_free(s->next);
    }
    free(s);
}

/**
 * 清空栈
 **/
void ls_free(ls_t *stack)
{
    if (!ls_is_empty(stack))
    {
        __ls_free(stack->top);
    }
    free(stack);
}

/**
 * 输出栈内元素 不清数据
 **/
void ls_print(ls_t *stack)
{
    if (ls_is_empty(stack))
    {
        return;
    }
    sn_t *p = stack->top;
    do
    {
        printf("%d\t", p->data);
        // 栈底的后继结点一定为空
    } while ((p = p->next) != NULL);
    printf("\n");
}