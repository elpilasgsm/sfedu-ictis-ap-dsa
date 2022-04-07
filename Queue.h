/**
 * This is Queue Data Structure implementation. Student must implement all functions from QueueNS namespace.
 * Please check the description of each function before function prototype.
 * THe implementation must be located in file Queue.cpp
 */

#ifndef SFEDU_ICTIS_AP_DSA_QUEUE_H
#define SFEDU_ICTIS_AP_DSA_QUEUE_H


template<typename TYPE>
struct QueueNode {
    TYPE key;
    QueueNode *next;
};


template<typename TYPE>
struct Queue {
    QueueNode<TYPE> *head;
    QueueNode<TYPE> *tail;
};

namespace QueueNS {
    /**
     * TODO Implement function that initialize new @Queue.
     * @tparam TYPE the type of stored in queue information. 
     * @return the pointer to the newly created @Queue structure.
     */
    template<typename TYPE>
    Queue<TYPE> *newQueue();

    /**
     * TODO implement function that insert @value to the  @queue
     * @tparam TYPE the type of stored in queue information.
     * @param queue the pointer to queue where we should enqueue @value
     * @param value  the value that we should insert to the head of @queue
     * @return 0 - if value was not inserted or 1 - if enqueue was succeed
     */
    template<typename TYPE>
    int enqueue(Queue<TYPE> *queue, TYPE value);

    /**
     * TODO implement function that get @value from the head of @queue
     * @tparam TYPE the type of stored in queue information.
     * @param queue the pointer to queue from where we should dequeue @value
     * @return address (pointer) to the @QueueNode from the head or null if the @queue is empty.
     */
    template<typename TYPE>
    QueueNode<TYPE> *dequeue(Queue<TYPE> *queue);

    /**
     * TODO function should properly delete @queue. Firstly the structure members must be deleted and after @queue itself should be deleted.
     * @tparam TYPE the type of stored in queue information
     * @param queue the pointer to the queue which should be properly deleted.
     */
    template<typename TYPE>
    void deleteQueue(Queue<TYPE> *queue);
};


#endif //SFEDU_ICTIS_AP_DSA_QUEUE_H
