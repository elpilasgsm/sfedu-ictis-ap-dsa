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
        std::cerr << "Array Tests failed with " << errors << " errors" << std::endl;
        return errors;
    }
    std::cout << "Array Tests passed successfully. " << std::endl;

    errors += StackTestsNS::test();
    if (errors > 0) {
        std::cerr << "Stack Tests failed with " << errors << " errors" << std::endl;
        return errors;
    }
    std::cout << "Stack Tests passed successfully. " << std::endl;

    //Run stress testing for graphics.
    PerformanceTestsNS::arrayPerformanceTest();
    return errors;
}