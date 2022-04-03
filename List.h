//
// Created by elpil on 03.04.2022.
//

#ifndef SFEDU_ICTIS_AP_DSA_LIST_H
#define SFEDU_ICTIS_AP_DSA_LIST_H

template<typename TYPE>
struct DoublyListNode {
    TYPE key;
    DoublyListNode<TYPE> *next;
    DoublyListNode<TYPE> *previous;
};

template<typename TYPE>
struct DoublyList {
    DoublyListNode<TYPE> *head;
    DoublyListNode<TYPE> *tail;
};

namespace ListNS {
    template<typename TYPE>
    DoublyList<TYPE> *newList();

    template<typename TYPE>
    int addAsAFirst(DoublyList<TYPE> *list, TYPE value);

    template<typename TYPE>
    int addAsALast(DoublyList<TYPE> *list, TYPE value);

    template<typename TYPE>
    int insertAfterNode(DoublyList<TYPE> *list, DoublyListNode<TYPE> node, TYPE value);

    template<typename TYPE>
    int deleteList(DoublyList<TYPE> *list);

}

#endif //SFEDU_ICTIS_AP_DSA_LIST_H
