// 使用结构体构建静态双向链表
typedef struct LINKEDLIST
{
    struct LINKEDLIST *pre;
    int content;
    struct LINKEDLIST *next;
} linkedlist_t;

// 头节点指针
linkedlist_t *ll_head;
// 尾节点指针
linkedlist_t *ll_tail;