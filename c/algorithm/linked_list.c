// #include <stdio.h>
// #include <stdlib.h>

// typedef int ll_dt;

// /**
//  * 单向链表
//  **/
// typedef struct LINKED_LIST
// {
//     ll_dt data;
//     struct LINKED_LIST *next;
// } ll_t;

// static ll_t *__ll_create(ll_dt data)
// {
//     ll_t *e = (ll_t *)malloc(sizeof(ll_t));
//     e->data = data;
//     e->next = NULL;
//     return e;
// }

// /**
//  * 查询尾节点
//  **/
// static ll_t *__ll_tail(ll_t *pos)
// {
//     ll_t *p = pos;
//     while (p->next != NULL)
//     {
//         p = p->next;
//     }
//     return p;
// }

// /**
//  * 从头节点开始
//  * 查询curr前继节点
//  **/
// static ll_t *__ll_pre(ll_t *head, ll_t *curr)
// {
//     ll_t *p = head;
//     while (p->next != curr)
//     {
//         p = p->next;
//     }
//     return p;
// }

// ll_t *ll_init(ll_dt data)
// {
//     return __ll_create(data);
// }

// ll_t *ll_add(ll_t *tail, ll_dt data)
// {
//     ll_t *e = __ll_create(data);
//     tail->next = e;
//     return e;
// }

// void *ll_del(ll_t *head, ll_t *curr)
// {
//     ll_t *pre = __ll_pre(head, curr);
//     pre->next = curr->next;
//     free(curr);
// }

// /**
//  * 清空链表
//  **/
// void ll_free(ll_t *head)
// {
//     if (head->next != NULL)
//     {
//         ll_free(head->next);
//     }
//     free(head);
// }

// /**
//  * 顺序输出全部节点
//  **/
// void ll_print(ll_t *head)
// {
//     ll_t *p = head;
//     printf("%d\n", p->data);
//     if (p->next != NULL)
//     {
//         ll_print(p->next);
//     }
// }