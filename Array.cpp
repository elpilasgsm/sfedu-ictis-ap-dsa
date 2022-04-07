//
// Created by elpil on 07.04.2022.
//

#include "Array.h"

/**
 * TODO Implement function that initialize new @Array with provided @size.
 * The function must create a pointer to new structure @Array. The size and *array members must be initialized properly.
 * @tparam TYPE the type of stored in array information.
 * @param size - the size of newly created array
 * @return  - the pointer to newly created array of @TYPE elements with provided @size
 */
template<typename TYPE>
Array<TYPE> *ArrayNS::newArray(int size) {
    auto *arr = new Array<TYPE>;
    arr->array = new TYPE[size];
    arr->size = size;
    return arr;
}

/**
 * TODO Implement function that add value to the Array structure by provided index.
 * function must insert given @value to given @arr by given index.
 * @tparam TYPE the type of stored in array information.
 * @param arr the pointer to the array to which we should insert value
 * @param value - the value that we should insert to the array @arr
 * @param index - the index of the @arr element where value must be inserted.
 * @return 0 - if this is not possible to insert given @value at given @index and return 1 if insert was succeed.
 */
template<typename TYPE>
int ArrayNS::insertToArray(Array<TYPE> *arr, TYPE value, int index) {
    if (arr == nullptr || arr->array == nullptr || index < 0) {
        return 0;
    }
    if (arr->size <= index) {
        return 0;
    }
    arr->array[index] = value;
    return 1;
}

/**
 * TODO Implement function that find an address of @Array element which store @value or @nullptr if no such elements in array.
 * @tparam TYPE the type of stored in array information
 * @param arr the pointer to the array where we should find the @value
 * @param value the search value
 * @return pointer to the element in @Array which store value @value. If no such element found @nullptr must be returned
 */
template<typename TYPE>
TYPE *ArrayNS::find(Array<TYPE> *arr, TYPE value) {
    if (arr == nullptr || arr->array == nullptr) {
        return nullptr;
    }
    for (int i = 0; i < arr->size; i++) {
        if (arr->array[i] == value) {
            return &(arr->array[i]);
        }
    }
    return nullptr;
}

/**
 * TODO function should properly delete array. Firstly the structure members must be deleted and after @arr inself should be deleted.
 * @tparam TYPE the type of stored in array information
 * @param arr the pointer to the array which should be properly deleted.
 */
template<typename TYPE>
void ArrayNS::deleteArray(Array<TYPE> *arr) {
    if (arr == nullptr) {
        return;
    }
    delete[] arr->array;
    delete arr;
}