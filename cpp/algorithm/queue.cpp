#include "queue.h"

// 类成员_queueSize是const 必须在执行构造函数前初始化
// 类成员如果是引用 也必须在执行构造函数前初始化
Queue::Queue(int queueSize) : _queueSize(queueSize) {
    _front = _rear = nullptr;
    _size = 0;
}

Queue::~Queue() {
    Node *tmp;
    while(nullptr != _front) {
        tmp = _front;
        _front = _front->_next;
        delete tmp;
    }
}

bool Queue::isEmpty() const {
    return 0 == _size;
}

bool Queue::isFull() const {
    return _queueSize == _size;
}

int Queue::getQueueSize() const {
    return _size;
}

bool Queue::push(const Item &item) {
    if (isFull()) {
        return false;
    }
    Node *node = new Node{._item = item, ._next=nullptr};
    if (nullptr == _front) {
        _front = node;
    } else {
        _rear->_next = node;
    }
    _rear = node;
    _size++;
    return true;
}

bool Queue::pop(Item &item) {
    if (isEmpty()) {
        return false;
    }
    item = _front->_item;
    Node *tmp = _front;
    _front = _front->_next;
    delete tmp;
    _size--;
    if (isEmpty()) {
        _rear = nullptr;
    }
    return true;
}
