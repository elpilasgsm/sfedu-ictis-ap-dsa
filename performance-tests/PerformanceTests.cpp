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
        int numOfRepeations = 0.5 * numOfArr;
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