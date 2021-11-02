#include "stack_ope_def.h"

/**
 * 创建节点
 * */
stack_ope_t *ope_create(char ope);

/**
 * 入栈
 * */
void ope_push(char ope);

/**
 * 读栈顶元素
 * */
char ope_peek();

/**
 * 出栈
 * */
char ope_pop();

/**
 * 清空栈
 * */
void ope_free(stack_ope_t *e);