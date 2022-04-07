//
// Created by sfedu on 3/27/22.
//

#include <cstdio>
#include <cstdlib>
#include "PerformanceTests.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

Array<int> *rand(int size) {
    Array<int> *newArr = new Array<int>;
    newArr->array = new int[size];
    newArr->size = size;

    for (int i = 0; i < newArr->size; i++) {
        newArr->array[i] = rand() % 1000;
    }
    return newArr;
}

long checkInsertArrayTime(Array<int> *arr) {
    auto start = high_resolution_clock::now();
    ArrayNS::insertToArray(arr, rand() % 1000, rand() % arr->size);
    auto stop = high_resolution_clock::now();
    return duration_cast<milliseconds>(stop - start).count();
}

long checkFindArrayTime(Array<int> *arr) {
    auto start = high_resolution_clock::now();
    ArrayNS::find(arr, rand() % 1000);
    auto stop = high_resolution_clock::now();
    return duration_cast<nanoseconds>(stop - start).count();
}

long checkPushStackTime(Stack<int> *arr) {
    auto start = high_resolution_clock::now();
    StackNS::push(arr, rand() % 255);
    auto stop = high_resolution_clock::now();
    return duration_cast<milliseconds>(stop - start).count();
}

long checkPopStackTime(Stack<int> *arr) {
    auto start = high_resolution_clock::now();
    StackNS::pop(arr);
    auto stop = high_resolution_clock::now();
    return duration_cast<nanoseconds>(stop - start).count();
}

long checkEnqueueTime(Queue<int> *arr) {
    auto start = high_resolution_clock::now();
    QueueNS::enqueue(arr, rand() % 255);
    auto stop = high_resolution_clock::now();
    return duration_cast<milliseconds>(stop - start).count();
}

long checkDequeueTime(Queue<int> *arr) {
    auto start = high_resolution_clock::now();
    QueueNS::dequeue(arr);
    auto stop = high_resolution_clock::now();
    return duration_cast<nanoseconds>(stop - start).count();
}

void createEmptyFile(const char *fileName) {
    FILE *f = fopen(fileName, "w");
    fprintf(f, "");
    fclose(f);
}


void addToFile(const char *fileName, int size, long insertTime, long searchTime) {
    FILE *f = fopen(fileName, "a");
    fprintf(f, "%d,%lu,%lu\n", size, insertTime, searchTime);
    fclose(f);
}

void PerformanceTestsNS::arrayPerformanceTest() {
    createEmptyFile("Array.csv");
    for (int test = 0; test < sizesArray; test++) {
        int numOfArr = sizes[test];
        Array<int> *arr = rand(numOfArr);
        int numOfRepeations = (int) (seriasRate * (float) numOfArr);
        long timeForSearch = 0;
        long timeForInsert = 0;
        for (int iter = 0; iter < numOfRepeations; iter++) {
            timeForSearch += checkFindArrayTime(arr);
            timeForInsert += checkInsertArrayTime(arr);
        }
        timeForSearch = timeForSearch / numOfRepeations;
        timeForInsert = timeForInsert / numOfRepeations;
        addToFile("Array.csv", numOfArr, timeForInsert, timeForSearch);
        ArrayNS::deleteArray(arr);
    }
}


void PerformanceTestsNS::stackPerformanceTest() {
    createEmptyFile("Stack.csv");
    for (int test = 0; test < sizesArray; test++) {
        int numOfArr = sizes[test];
        auto *stack = StackNS::newStack<int>();
        int numOfRepeations = (int) (seriasRate * (float) numOfArr);
        long timeForSearch = 0;
        long timeForInsert = 0;
        for (int iter = 0; iter < numOfRepeations; iter++) {
            timeForSearch += checkPopStackTime(stack);
            timeForInsert += checkPushStackTime(stack);
        }
        timeForSearch = timeForSearch / numOfRepeations;
        timeForInsert = timeForInsert / numOfRepeations;
        addToFile("Stack.csv", numOfArr, timeForInsert, timeForSearch);
        StackNS::deleteStack(stack);
    }
}


void PerformanceTestsNS::queuePerformanceTest() {
    createEmptyFile("Queue.csv");
    for (int test = 0; test < sizesArray; test++) {
        int numOfArr = sizes[test];
        auto *queue = QueueNS::newQueue<int>();
        int numOfRepeations = (int) (seriasRate * (float) numOfArr);
        long timeForSearch = 0;
        long timeForInsert = 0;
        for (int iter = 0; iter < numOfRepeations; iter++) {
            timeForSearch += checkEnqueueTime(queue);
            timeForInsert += checkEnqueueTime(queue);
        }
        timeForSearch = timeForSearch / numOfRepeations;
        timeForInsert = timeForInsert / numOfRepeations;
        addToFile("Queue.csv", numOfArr, timeForInsert, timeForSearch);
        QueueNS::deleteQueue(queue);
    }
}

void PerformanceTestsNS::listPerformanceTest() {
    createEmptyFile("List.csv");
    for (int test = 0; test < sizesArray; test++) {
        int numOfArr = sizes[test];
        auto *queue = QueueNS::newQueue<int>();
        int numOfRepeations = (int) (seriasRate * (float) numOfArr);
        long timeForSearch = 0;
        long timeForInsert = 0;
        for (int iter = 0; iter < numOfRepeations; iter++) {
            timeForSearch += checkEnqueueTime(queue);
            timeForInsert += checkEnqueueTime(queue);
        }
        timeForSearch = timeForSearch / numOfRepeations;
        timeForInsert = timeForInsert / numOfRepeations;
        addToFile("List.csv", numOfArr, timeForInsert, timeForSearch);
        QueueNS::deleteQueue(queue);
    }
}

