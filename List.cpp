//
// Created by elpil on 07.04.2022.
//

#include "List.h"
#include <iostream>

/**
* TODO Implement function that initialize new @DoublyList.
* @tparam TYPE the type of stored in list information.
* @return the pointer to the newly created @DoublyList structure.
*/
template<typename TYPE>
DoublyList<TYPE> *ListNS::newList() {
    auto *l = new DoublyList<TYPE>;
    l->head = nullptr;
    l->tail = nullptr;
    return l;
}

/**
* TODO Implement function that add new values to the head of @DoublyList.
* @tparam TYPE the type of stored in list information.
* @param list - the target list to where we should add value
* @param value - the value that we should add to the @list
* @return The number of insert items.
*/
template<typename TYPE>
int ListNS::addAsAFirst(DoublyList<TYPE> *list, TYPE value) {
    if (list == nullptr) {
        return 0;
    }
    auto *node = new DoublyListNode<TYPE>;
    node->key = value;
    node->next = nullptr;
    node->previous = nullptr;
    if (list->head != nullptr) {
        list->head->previous = node;
    }
    node->next = list->head;
    list->head = node;
    if (list->tail == nullptr) {
        list->tail = list->head;
    }
}

/**
* TODO Implement function that add new values to the tail of @DoublyList.
* @tparam TYPE the type of stored in list information.
* @param list - the target list to where we should add value
* @param value - the value that we should add to the @list
* @return The number of insert items.
*/
template<typename TYPE>
int ListNS::addAsALast(DoublyList<TYPE> *list, TYPE value) {
    if (list == nullptr) {
        return 0;
    }
    auto *node = new DoublyListNode<TYPE>;
    node->key = value;
    node->next = nullptr;
    node->previous = nullptr;
    if (list->tail != nullptr) {
        list->tail->next = node;
    }
    node->previous = list->tail;
    list->tail = node;
    if (list->head == nullptr) {
        list->head = list->tail;
    }
}

/**
* TODO Implement function that add new value after given node of @DoublyList.
* @tparam TYPE the type of stored in list information.
* @param list - the target list to where we should add value
* @param value - the value that we should add to the @list
* @return The number of insert items.
*/
template<typename TYPE>
int ListNS::insertAfterNode(DoublyList<TYPE> *list, DoublyListNode<TYPE> *node, TYPE value) {
    if (list == nullptr || node == nullptr) {
        return 0;
    }

    auto *newNode = new DoublyListNode<TYPE>;
    newNode->key = value;
    newNode->next = nullptr;
    newNode->previous = nullptr;
    newNode->next = node->next;
    newNode->previous = node;
    node->next = newNode;

    return 1;

}

/**
* TODO Implement function that find node by value in @DoublyList.
* @tparam TYPE the type of stored in list information.
* @param list - the target list to where we should add value
* @param value - the value that we should  find in the @list
* @return the pointer to the found node or nullptr if no such node.
*/
template<typename TYPE>
DoublyListNode<TYPE> *ListNS::find(DoublyList<TYPE> *list, TYPE value) {

    auto *left = list->head;
    auto *right = list->tail;

    while (left != nullptr && right != nullptr) {
        if (left->key == value) {
            return left;
        }
        if (right->key == value) {
            return right;
        }
        left = left->next;
        right = right->previous;
    }
    return nullptr;
}

/**
 * TODO function should properly delete @list. Firstly the structure members must be deleted and after @list itself should be deleted.
 * @tparam TYPE the type of stored in queue information
 * @param lsit the pointer to the list which should be properly deleted.
 */
template<typename TYPE>
void ListNS::deleteList(DoublyList<TYPE> *list) {
    while (list->head != nullptr) {
        auto *n = list->head->next;
        delete list->head;
        list->head = n;
    }
    delete list;
}