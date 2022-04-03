//
// Created by sfedu on 3/25/22.
//
#include <cstdlib>
#include <cstdio>
#include "Tests.h"

void print(Array<int> *arr) {
    printf("\n");
    for (int i = 0; i < arr->size; i++) {
        printf(" %d,", arr->array[i]);
    }
    printf("\n");
}

void rand(Array<int> *arr) {
    if (arr == nullptr) {
        return;
    }
    for (int i = 0; i < arr->size; i++) {
        arr->array[i] = rand() % 1000;
    }
    //print(arr);
}

int ArrayTestsNS::testFind() {
    int errors = 0;
    const int size = rand() % 100 + 50;
    Array<int> *arr = ArrayNS::newArray<int>(size);
    rand(arr);
    if (arr == nullptr) {
        return 1;
    }

    for (int i = 0; i < size; i++) {
        int curPos = i;
        int atPos = arr->array[curPos];
        int *atPosPoint = ArrayNS::find(arr, atPos);
        if (atPosPoint == nullptr) {
            errors++;
            printf("=========================\n");
            printf("Find by value failed\n");
            printf("Array\n");
            print(arr);
            printf("Position = %d\n", curPos);
            printf("Expected value = %d\n", atPos);
            printf("Actual value is NULL\n");
            printf("=========================\n");
            continue;
        }
        if (atPos != *atPosPoint) {
            errors++;
            printf("=========================\n");
            printf("ArrayNS::find works incorrectly\n");
            printf("Expected value = %d\n", atPos);
            printf("Actual value is %d\n", *atPosPoint);
            printf("=========================\n");
        }
        int newVal = -1 * (atPos + (rand() % 50 + 1));
        ArrayNS::insertToArray(arr, newVal, curPos);
        int *actual = ArrayNS::find(arr, newVal);

        if (actual == nullptr) {
            printf("=========================\n");
            printf("ArrayNS::insertToArray works incorrect.\n");
            printf("Actual value is NULL\n");
            printf("=========================\n");
            errors++;
            continue;
        }

        if (*actual != newVal) {
            printf("=========================\n");
            printf("ArrayNS::insertToArray works incorrect.\n");
            printf("Actual value is NULL\n");
            printf("Expected value = %d\n", newVal);
            printf("Actual value is %d\n", *actual);
            printf("=========================\n");
            errors++;
        }
        arr->array[curPos] = atPos;
    }

    ArrayNS::deleteArray(arr);
    return errors;
}

int ArrayTestsNS::testInsert() {
    int errors = 0;

    const int size = rand() % 100 + 50;
    Array<int> *arr = ArrayNS::newArray<int>(size);
    rand(arr);
    for (int i = 0; i < arr->size / 3; i++) {
        const int curPos = rand() % size;
        const int oldValue = arr->array[curPos];
        const int expected = oldValue + (rand() % 90 + 1);
        ArrayNS::insertToArray(arr, expected, curPos);
        int *found = ArrayNS::find(arr, expected);
        errors += (*found != expected);
        return errors;
    }
    ArrayNS::deleteArray(arr);
    return errors;
}

int StackTestsNS::test() {
    int errors = 0;
    const int size = rand() % 100 + 50;
    Array<int> *arr = ArrayNS::newArray<int>(size);
    rand(arr);

    auto *stack = new Stack<int>;
    for (int i = 0; i < arr->size; i++) {
        StackNS::push(stack, arr->array[i]);
    }
    for (int i = 0; i < arr->size / 2; i++) {
        auto val = arr->array[arr->size - 1 - i];
        errors += (val != StackNS::pop(stack)->key);
    }
    return errors;
}


int QueueTestsNS::test() {
    int errors = 0;
    const int size = rand() % 100 + 50;
    Array<int> *arr = ArrayNS::newArray<int>(size);
    rand(arr);

    auto *q = new Queue<int>;
    for (int i = 0; i < arr->size; i++) {
        QueueNS::enqueue(q, arr->array[i]);
    }
    for (int i = 0; i < arr->size / 2; i++) {
        auto val = arr->array[ i];
        errors += (val != QueueNS::dequeue(q)->key);
    }
    return errors;
}