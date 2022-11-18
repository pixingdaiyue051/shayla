/**
 * 链式栈 无需设定栈的大小
 **/
#ifndef _HEAD_LINKED_STACK
#define _HEAD_LINKED_STACK

typedef int ls_dt;

typedef struct STACK_NODE
{
    ls_dt data;
    struct STACK_NODE *next;
} sn_t;

typedef struct LINKED_STACK
{
    sn_t *top;
    int size;
} ls_t;

/**
 * 初始化栈
 **/
ls_t *ls_init();

/**
 * 判断栈是否空
 **/
int ls_is_empty(ls_t *stack);

/**
 * 入栈
 **/
int ls_push(ls_t *stack, ls_dt data);

/**
 * 读栈顶元素
 **/
int ls_peek(ls_t *stack, ls_dt *pm);

/**
 * 出栈
 **/
int ls_pop(ls_t *stack, ls_dt *pm);

/**
 * 清空栈
 **/
void ls_free(ls_t *stack);

/**
 * 输出栈内元素 不清数据
 **/
void ls_print(ls_t *stack);

#endif