/**
 * This is Stack Data Structure implementation. Student must implement all functions from StackNS namespace.
 * Please check the description of each function before function prototype. 
 * THe implementation must be located in file Stack.cpp
 */

#ifndef SFEDU_ICTIS_AP_DSA_STACK_H
#define SFEDU_ICTIS_AP_DSA_STACK_H

template<typename TYPE>
struct StackNode {
    TYPE key;
    StackNode *next;
};


template<typename TYPE>
struct Stack {
    StackNode<TYPE> *head;
};

namespace StackNS {
    /**
     * TODO Implement function that initialize new @Stack.
     * @tparam TYPE the type of stored in stack information. 
     * @return the pointer to the newly created @Stack structure.
     */
    template<typename TYPE>
    Stack<TYPE> *newStack();

    /**
     * TODO implement function that insert @value to the head of @stack
     * @tparam TYPE the type of stored in stack information.
     * @param stack the pointer to stack where we should push @value
     * @param value  the value that we should insert to the head of @stack
     * @return 0 - if value was not inserted or 1 - if push was succeed
     */
    template<typename TYPE>
    int push(Stack<TYPE> *stack, TYPE value);

    /**
     * TODO implement function that get @value from the head of @stack
     * @tparam TYPE the type of stored in stack information.
     * @param stack the pointer to stack where we should push @value
     * @return address (pointer) to the @StackNode from the head or null if the @stack is empty.
     */
    template<typename TYPE>
    StackNode<TYPE> *pop(Stack<TYPE> *stack);

    /**
     * TODO function should properly delete @stack. Firstly the structure members must be deleted and after @stack inself should be deleted.
     * @tparam TYPE the type of stored in stack information
     * @param stack the pointer to the stack which should be properly deleted.
     */
    template<typename TYPE>
    void deleteStack(Stack<TYPE> *stack);
};

#endif SFEDU_ICTIS_AP_DSA_STACK_H
