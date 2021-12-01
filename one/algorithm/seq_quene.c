#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int sq_dt;

/**
 * 顺序队列 循环队列
 * */
typedef struct SEQ_QUENE
{
    sq_dt *data;
    int front;
    int rear;
    int capacity;
} sq_t;

sq_t *sq_init(int capacity)
{
    sq_t *quene = (sq_t *)malloc(sizeof(sq_t));
    // 分配capacity个大小为sq_dt的连续内存
    quene->data = (sq_dt *)calloc(capacity, sizeof(sq_dt));
    // 初始指定队首队尾索引均为0(其实只要在capacity索引范围内均可)
    quene->front = quene->rear = 0;
    quene->capacity = capacity;
    return quene;
}

bool sq_is_empty(sq_t *quene)
{
    // 队首追上了队尾表示队列已空
    return quene->front == quene->rear;
}

bool sq_is_full(sq_t *quene)
{
    // 队首刚好在队尾前面一位表示队列已满
    return (quene->front - quene->rear == 1) || (quene->front - quene->rear + quene->capacity == 1);
}

static inline int __step_next(int p, int capacity)
{
    // 步长自增,如果超过capacity就置0
    return (p + 1 == capacity) ? 0 : p + 1;
}

/**
 * 入队-在队尾追加
 * */
bool sq_add(sq_t *quene, sq_dt data)
{
    if (sq_is_full(quene))
    {
        return false;
    }
    quene->data[quene->rear] = data;
    quene->rear = __step_next(quene->rear, quene->capacity);
    return true;
}

/**
 * 读队首元素
 * */
bool sq_peek(sq_t *quene, sq_dt *pm)
{
    if (sq_is_empty(quene))
    {
        return false;
    }
    *pm = quene->data[quene->front];
    return true;
}

/**
 * 出队-读队首
 * */
bool sq_poll(sq_t *quene, sq_dt *pm)
{
    if (sq_peek(quene, pm))
    {
        quene->front = __step_next(quene->front, quene->capacity);
        return true;
    }
    return false;
}

/**
 * 先进先出输出所有数据,不出队
 * */
void sq_print(sq_t *quene)
{
    if (sq_is_empty(quene))
    {
        return;
    }
    if (quene->front > quene->rear)
    {
        int i;
        for (i = quene->front; i < quene->capacity; i++)
        {
            printf("%d\t", quene->data[i]);
        }
        for (i = 0; i < quene->rear; i++)
        {
            printf("%d\t", quene->data[i]);
        }
    }
    else
    {
        for (int i = quene->front; i < quene->rear; i++)
        {
            printf("%d\t", quene->data[i]);
        }
    }
    printf("\n");
}

/**
 * 清空队列
 * */
void sq_free(sq_t *quene)
{
    free(quene->data);
    free(quene);
}