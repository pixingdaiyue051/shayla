/**
 * 顺序栈 预先设定好栈大小
 **/
#ifndef _HEAD_SEQ_STACK
#define _HEAD_SEQ_STACK

typedef int ss_dt;

typedef struct SEQ_STACK
{
    ss_dt *data;
    int capacity;
    int top;
} ss_t;

/**
 * 初始化栈
 **/
ss_t *ss_init(int capacity);

/**
 * 判断栈是否已满
 */
int ss_is_full(ss_t *stack);

/**
 * 判断栈是否空
 **/
int ss_is_empty(ss_t *stack);

/**
 * 入栈
 **/
int ss_push(ss_t *stack, ss_dt d);

/**
 * 读栈顶元素
 **/
int ss_peek(ss_t *stack, ss_dt *pm);

/**
 * 出栈
 **/
int ss_pop(ss_t *stack, ss_dt *pm);

/**
 * 清空栈
 **/
void ss_free(ss_t *stack);

/**
 * 输出栈内元素 不清数据
 **/
void ss_print(ss_t *stack);

#endif