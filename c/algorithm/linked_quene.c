#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int lq_dt;

/**
 * 链式队列节点
 **/
typedef struct QUENE_NODE
{
    lq_dt data;
    struct QUENE_NODE *next;
} qn_t;

/**
 * 链式队列
 **/
typedef struct LINKED_QUENE
{
    qn_t *front;
    qn_t *rear;
    int size;
} lq_t;

lq_t *lq_init()
{
    lq_t *quene = (lq_t *)malloc(sizeof(lq_t));
    quene->front = quene->rear = NULL;
    quene->size = 0;
    return quene;
}

bool lq_is_empty(lq_t *quene)
{
    return quene->size == 0;
}

static inline qn_t *__lq_create(lq_dt data)
{
    qn_t *node = (qn_t *)malloc(sizeof(qn_t));
    node->data = data;
    node->next = NULL;
    return node;
}

/**
 * 入队-在队尾追加
 **/
bool lq_add(lq_t *quene, lq_dt data)
{
    qn_t *node = __lq_create(data);
    if (lq_is_empty(quene))
    {
        // 添加第一个元素
        // 队首队尾指针都指向第一个节点
        quene->front = quene->rear = node;
    }
    else
    {
        // 从第二个节点开始添加
        // 当前队尾后继节点指向新节点
        quene->rear->next = node;
        // 队尾指向新节点
        quene->rear = node;
    }
    quene->size++;
    return true;
}

/**
 * 读队首元素
 **/
bool lq_peek(lq_t *quene, lq_dt *pm)
{
    if (lq_is_empty(quene))
    {
        return false;
    }
    *pm = quene->front->data;
    return true;
}

/**
 * 出队-读队首
 **/
bool lq_poll(lq_t *quene, lq_dt *pm)
{
    if (lq_peek(quene, pm))
    {
        // 队首指向顺序后移
        qn_t *p = quene->front;
        quene->front = p->next;
        free(p);
        quene->size--;
        return true;
    }
    return false;
}

static inline void __lq_free(qn_t *node)
{
    if (node->next != NULL)
    {
        __lq_free(node->next);
    }
    free(node);
}

/**
 * 清空队列
 **/
void lq_free(lq_t *quene)
{
    if (!lq_is_empty(quene))
    {
        __lq_free(quene->front);
    }
    free(quene);
}

// /**
//  * 先进先出输出所有数据,不出队
//  **/
// void lq_print(lq_t *quene)
// {
//     if (lq_is_empty(quene))
//     {
//         return;
//     }
//     qn_t *node = quene->front;
//     do
//     {
//         printf("%d\t", node->data);
//         // 队尾节点的后继节点一定为空
//     } while ((node = node->next) != NULL);
//     printf("\n");
// }