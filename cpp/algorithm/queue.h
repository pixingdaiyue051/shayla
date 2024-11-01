#ifndef SHAYLA_QUEUE_H
#define SHAYLA_QUEUE_H

typedef int Item;

class Queue {
private:
    static const int Q_SiZE = 10;
    struct Node {
        Item _item;
        Node *_next;
    };
    Node *_front;
    Node *_rear;
    int _size; // 队列内当前元素数量
    const int _queueSize; // 队列初始化大小 最大容量
public:
    explicit Queue(int queueSize = Q_SiZE);

    ~Queue();

    bool isEmpty() const;

    bool isFull() const;

    int getQueueSize() const;

    bool push(const Item &item);

    bool pop(Item &item);
};

#endif