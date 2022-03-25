//
// Created by sfedu on 3/25/22.
//

#include "Tests.h"
#include "Array.h"
#include "math.h"
#include "stdlib.h"

int ArrayTestsNS::testFind() {
    int errors = 0;
    const int size = rand() % 100 + 50;
    Array<int> *arr = ArrayNS::newArray<>(size);

    for (int i = 0;i<arr->size / 3;i++){
        const int curPos = rand() % size;
        const int expected = arr->array[curPos];
        int *actual = ArrayNS::find(arr, curPos);
        errors += (&actual != expected);
    }

    ArrayNS::deleteArray(arr);
    return errors;
}

int ArrayTestsNS::testInsert() {
    int errors = 0;
    const int size = rand() % 100 + 50;
    Array<int> *arr = ArrayNS::newArray<>(size);

    for (int i = 0;i<arr->size / 3;i++){
        const int curPos = rand() % size;
        const oldValue = arr->array[curPos] ;
        const expected = oldValue + (rand() % 90 + 1);
        ArrayNS::insertToArray(arr,expected,curPos);
        int *found = ArrayNS::find(arr, expected);
        errors += (&found != expected);
        return errors;
    }

    ArrayNS::deleteArray(arr);
    return errors;
}