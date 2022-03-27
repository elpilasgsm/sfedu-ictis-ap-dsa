//
// Created by sfedu on 3/25/22.
//
#include "Tests.h"
#include "PerformanceTests.h"


int main() {
    //Test functionality
    int errors = ArrayTestsNS::testInsert();
    errors += ArrayTestsNS::testFind();

    //Run stress testing for graphics.
    PerformanceTestsNS::arrayPerformanceTest();
    return errors;
}