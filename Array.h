//
// Created by sfedu on 3/25/22.
//

#ifndef SFEDU_ICTIS_AP_DSA_ARRAY_H
#define SFEDU_ICTIS_AP_DSA_ARRAY_H

template <typename TYPE> struct Array{
    TYPE *array;
    int size;
};

namespace ArrayNS {
    template <typename TYPE> Array<TYPE> *newArray(int size);
    template <typename TYPE> void insertToArray(Array<TYPE> *arr, TYPE value, int index);
    template <typename TYPE> TYPE &find(Array<TYPE> *arr, TYPE value);
    template <typename TYPE> void deleteArray(Array<TYPE> *arr);
};

#endif //SFEDU_ICTIS_AP_DSA_ARRAY_H
