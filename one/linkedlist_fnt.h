/**
 * 创建空节点
 * */
linkedlist_t *ll_create(int content);

/**
 * 末尾追加 返回尾节点
 * */
linkedlist_t *ll_append(int content);

/**
 * 队首加入 返回头节点
 * */
linkedlist_t *ll_insert(int content);

/**
 * 顺序输出全部节点
 * */
void ll_print(linkedlist_t *l);

/**
 * 清空链表
 * */
void ll_free(linkedlist_t *l);

/**
 * 静态链表
 * */
linkedlist_t *static_linkedlist();

/**
 * 动态链表
 * */
linkedlist_t *dynamic_linkedlist();