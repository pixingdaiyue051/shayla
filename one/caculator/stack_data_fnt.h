#include "stack_data_def.h"

/**
 * 创建节点
 * */
stack_data_t *dd_create(double data);

/**
 * 入栈
 * */
void dd_push(double data);

/**
 * 读栈顶元素
 * */
double dd_peek();

/**
 * 出栈
 * */
double dd_pop();

/**
 * 清空栈
 * */
void dd_free(stack_data_t *e);