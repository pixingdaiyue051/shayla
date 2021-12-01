#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ls_dt;

/**
 * 链式栈节点
 * */
typedef struct STACK_NODE
{
    ls_dt data;
    struct STACK_NODE *next;
} sn_t;

/**
 * 链式栈栈顶
 * */
typedef struct LINKED_STACK
{
    sn_t *top;
    int size;
} ls_t;

ls_t *ls_init()
{
    ls_t *stack = (ls_t *)malloc(sizeof(ls_t));
    stack->size = 0;
    stack->top = NULL;
    return stack;
}

bool ls_is_empty(ls_t *stack)
{
    return stack->size == 0;
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
 * */
bool ls_push(ls_t *stack, ls_dt data)
{
    sn_t *node = __ls_create(data);
    // 新节点后继节点指向当前栈顶
    node->next = stack->top;
    // 栈顶指向新节点
    stack->top = node;
    ++stack->size;
    return true;
}

/**
 * 读栈顶元素
 * */
bool ls_peek(ls_t *stack, ls_dt *pm)
{
    if (ls_is_empty(stack))
    {
        return false;
    }
    *pm = stack->top->data;
    return true;
}

/**
 * 出栈
 * */
bool ls_pop(ls_t *stack, ls_dt *pm)
{
    if (ls_peek(stack, pm))
    {
        sn_t *s = stack->top;
        // 栈顶向下移到下一个节点
        stack->top = s->next;
        free(s);
        --stack->size;
        return true;
    }
    return false;
}

/**
 * 清空节点
 * */
static inline void __sn_free(sn_t *s)
{
    if (s->next != NULL)
    {
        __sn_free(s->next);
    }
    free(s);
}

/**
 * 清空栈
 * */
void ls_free(ls_t *stack)
{
    if (!ls_is_empty(stack))
    {
        __sn_free(stack->top);
    }
    free(stack);
}

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