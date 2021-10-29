#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_def.h"

/**
 * 创建空节点
 * */
linkedlist_t *ll_create(int content)
{
    linkedlist_t *e = malloc(sizeof(linkedlist_t));
    e->content = content;
    e->pre = NULL;
    e->next = NULL;
    return e;
}

/**
 * 末尾追加,返回尾节点
 * */
linkedlist_t *ll_append(int content)
{
    // 如果没有头节点则创建头节点
    if (!ll_head)
    {
        ll_head = ll_create(content);
        return ll_head;
    }
    // 如果没有尾节点则创建尾节点
    if (!ll_tail)
    {
        ll_tail = ll_create(content);
        ll_head->next = ll_tail;
        ll_tail->pre = ll_head;
        return ll_tail;
    }
    // 正常在末尾追加新节点
    linkedlist_t *e = ll_create(content);
    ll_tail->next = e;
    e->pre = ll_tail;
    // 指针指向新的尾节点
    ll_tail = e;
    return ll_tail;
}

/**
 * 队首加入,返回头节点
 * */
linkedlist_t *ll_insert(int content)
{
    // 如果没有头节点则创建头节点
    if (!ll_head)
    {
        ll_head = ll_create(content);
        return ll_head;
    }
    // 正常队首加入新的头节点
    linkedlist_t *e = ll_create(content);
    ll_head->pre = e;
    e->next = ll_head;
    // 如果没有尾节点则将原头节点设为尾节点
    if (!ll_tail)
    {
        ll_tail = ll_head;
    }
    // 指针指向新的头节点
    ll_head = e;
    return ll_head;
}

/**
 * 清空链表
 * */
void ll_free(linkedlist_t *e)
{
    if (e->next)
    {
        ll_free(e->next);
    }
    free(e);
}

/**
 * 顺序输出全部节点
 * */
void ll_print(linkedlist_t *e)
{
    printf("%d\n", e->content);
    if (e->next)
    {
        ll_print(e->next);
    }
}

/**
 * 静态链表
 * */
linkedlist_t *static_linkedlist()
{
    linkedlist_t *l1 = malloc(sizeof(linkedlist_t));
    linkedlist_t *l2 = malloc(sizeof(linkedlist_t));
    linkedlist_t *l3 = malloc(sizeof(linkedlist_t));
    l1->pre = NULL;
    l1->content = 1;
    l1->next = l2;

    l2->pre = l1;
    l2->content = 2;
    l2->next = l3;

    l3->pre = l2;
    l3->content = 3;
    l3->next = NULL;
    return l1;
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