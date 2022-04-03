//
// Created by sfedu on 3/25/22.
//
#include "Tests.h"
#include "PerformanceTests.h"
#include <iostream>

int main() {
    //Test functionality
    int errors = ArrayTestsNS::testInsert();
    errors += ArrayTestsNS::testFind();
    if (errors > 0) {
        std::cout << "Array Tests failed with " << errors << " errors" << std::endl;
        return errors;
    }
    //Run stress testing for graphics.
    PerformanceTestsNS::arrayPerformanceTest();
    return errors;
}