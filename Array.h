/**
 * This is Array Data Structure implementation. Student must implement all functions from ArrayNS namespace.
 * Please check the description of each function before function prototype. 
 * The implementations must be located in file Array.cpp
 */


#ifndef SFEDU_ICTIS_AP_DSA_ARRAY_H
#define SFEDU_ICTIS_AP_DSA_ARRAY_H

template<typename TYPE>
struct Array {
    TYPE *array;
    int size;
};

namespace ArrayNS {
    /**
     * TODO Implement function that initialize new @Array with provided @size.
     * The function must create a pointer to new structure @Array. The size and *array members must be initialized properly.
     * @tparam TYPE the type of stored in array information.  
     * @param size - the size of newly created array
     * @return  - the pointer to newly created array of @TYPE elements with provided @size
     */
    template<typename TYPE>
    Array<TYPE> *newArray(int size);

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
    int insertToArray(Array<TYPE> *arr, TYPE value, int index);

    /**
     * TODO Implement function that find an address of @Array element which store @value or @nullptr if no such elements in array.
     * @tparam TYPE the type of stored in array information 
     * @param arr the pointer to the array where we should find the @value
     * @param value the search value
     * @return pointer to the element in @Array which store value @value. If no such element found @nullptr must be returned
     */
    template<typename TYPE>
    TYPE *find(Array<TYPE> *arr, TYPE value);

    /**
     * TODO function should properly delete array. Firstly the structure members must be deleted and after @arr inself should be deleted.  
     * @tparam TYPE the type of stored in array information
     * @param arr the pointer to the array which should be properly deleted.
     */
    template<typename TYPE>
    void deleteArray(Array<TYPE> *arr);
};

#endif SFEDU_ICTIS_AP_DSA_ARRAY_H
