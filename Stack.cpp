/**
 * This is Stack Data Structure implementation. Student must implement all functions from StackNS namespace.
 * Please check the description of each function before function prototype.
 * THe implementation must be located in file Stack.cpp
 */



#include "Stack.h"


/**
 * TODO Implement function that initialize new @Stack.
 * @tparam TYPE the type of stored in Stack information.
 * @return the pointer to the newly created @Stack structure.
 */
template<typename TYPE>
Stack<TYPE> *StackNS::newStack() {
    auto *stack = new Stack<TYPE>;
    stack->head = nullptr;
    return stack;
}

/**
 * TODO implement function that insert @value to the  @Stack
 * @tparam TYPE the type of stored in stack information.
 * @param stack the pointer to stack where we should enStack @value
 * @param value  the value that we should insert to the head of @Stack
 * @return 0 - if value was not inserted or 1 - if enStack was succeed
 */
template<typename TYPE>
int StackNS::push(Stack<TYPE> *stack, TYPE value) {
    if (stack == nullptr) {
        return 0;
    }
    auto *newNode = new StackNode<TYPE>;
    newNode->key = value;
    newNode->next = stack->head;
    stack->head = newNode;
    return 1;
}

/**
 * TODO implement function that get @value from the head of @Stack
 * @tparam TYPE the type of stored in stack information.
 * @param stack the pointer to stack from where we should deStack @value
 * @return address (pointer) to the @StackNode from the head or null if the @Stack is empty.
 */
template<typename TYPE>
StackNode<TYPE> *StackNS::pop(Stack<TYPE> *stack) {
    if (stack == nullptr || stack->head== nullptr) {
        return nullptr;
    }
    auto *node = stack->head;
    stack->head = stack->head->next;
    return node;
}

/**
 * TODO function should properly delete @Stack. Firstly the structure members must be deleted and after @Stack itself should be deleted.
 * @tparam TYPE the type of stored in stack information
 * @param stack the pointer to the stack which should be properly deleted.
 */
template<typename TYPE>
void StackNS::deleteStack(Stack<TYPE> *stack) {
    while (stack->head != nullptr) {
        delete pop(stack);
    }
    delete stack;
}


