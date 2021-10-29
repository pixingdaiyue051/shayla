/**
 * 创建节点
 * */
stack_t *ss_create(double d);

/**
 * 入栈
 * */
void ss_push(double d);

/**
 * 读栈顶元素
 * */
double ss_read();

/**
 * 出栈
 * */
double ss_pop();

/**
 * 清空栈
 * */
void ss_free(stack_t *e);

/**
 * 先进后出 输出所有数据
 * */
void ss_print(stack_t *e);