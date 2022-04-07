/**
 * This is Queue Data Structure implementation. Student must implement all functions from QueueNS namespace.
 * Please check the description of each function before function prototype.
 * THe implementation must be located in file Queue.cpp
 */



#include "Queue.h"


/**
 * TODO Implement function that initialize new @Queue.
 * @tparam TYPE the type of stored in queue information.
 * @return the pointer to the newly created @Queue structure.
 */
template<typename TYPE>
Queue<TYPE> *QueueNS::newQueue() {
    auto *q = new Queue<TYPE>;
    q->tail = nullptr;
    q->head = nullptr;
    return q;
}

/**
 * TODO implement function that insert @value to the  @queue
 * @tparam TYPE the type of stored in queue information.
 * @param queue the pointer to queue where we should enqueue @value
 * @param value  the value that we should insert to the head of @queue
 * @return 0 - if value was not inserted or 1 - if enqueue was succeed
 */
template<typename TYPE>
int QueueNS::enqueue(Queue<TYPE> *queue, TYPE value) {
    if (queue == nullptr) {
        return 0;
    }
    auto *newNode = new QueueNode<TYPE>;
    newNode->key = value;
    newNode->next = nullptr;

    if (queue->tail != nullptr) {
        queue->tail->next = newNode;
    }
    queue->tail = newNode;
    if (queue->head == nullptr) {
        queue->head = queue->tail;
    }
}

/**
 * TODO implement function that get @value from the head of @queue
 * @tparam TYPE the type of stored in queue information.
 * @param queue the pointer to queue from where we should dequeue @value
 * @return address (pointer) to the @QueueNode from the head or null if the @queue is empty.
 */
template<typename TYPE>
QueueNode<TYPE> *QueueNS::dequeue(Queue<TYPE> *queue) {
    if (queue == nullptr || queue->head == nullptr) {
        return nullptr;
    }
    auto *node = queue->head;
    queue->head = queue->head->next;
    return node;
}

/**
 * TODO function should properly delete @queue. Firstly the structure members must be deleted and after @queue itself should be deleted.
 * @tparam TYPE the type of stored in queue information
 * @param queue the pointer to the queue which should be properly deleted.
 */
template<typename TYPE>
void QueueNS::deleteQueue(Queue<TYPE> *queue) {
    while (queue->head != nullptr) {
        delete dequeue(queue);
    }
    delete queue;
}


