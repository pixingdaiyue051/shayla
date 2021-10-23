#include <stdio.h>
#include <stdlib.h>

// 使用结构体构建静态双向链表
typedef struct LINKEDLIST
{
    struct LINKEDLIST *pre;
    int content;
    struct LINKEDLIST *next;
} linkedlist_t;

void print_linkedlist(linkedlist_t *l)
{
    printf("%d\n", l->content);
    if (NULL != l->next)
    {
        print_linkedlist(l->next);
    }
}

/**
 * 动态链表
 * */
linkedlist_t *dynamic_linkedlist()
{
    int i;
    int n = 1;
    linkedlist_t *head, *pre1;

    do
    {
        scanf("%d", &i);
        if (1 == n++)
        {
            linkedlist_t *e = malloc(sizeof(linkedlist_t));
            e->content = i;
            e->pre = NULL;
            pre1 = e;
            head = e;
            continue;
        }
        if (0 == i)
        {
            pre1->next = NULL;
            break;
        }
        linkedlist_t *e = malloc(sizeof(linkedlist_t));
        e->content = i;
        e->pre = pre1;
        pre1->next = e;
        pre1 = e;

    } while (1);

    return head;
}