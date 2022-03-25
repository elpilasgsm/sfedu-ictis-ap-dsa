//
// Created by sfedu on 3/25/22.
//
#include "Tests.h"
#include "TestData.h"


int main() {
    int errors = ArrayTestsNS::testInsert();
    errors += ArrayTestsNS::testFind();
    return errors;
}