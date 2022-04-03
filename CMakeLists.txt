cmake_minimum_required(VERSION 3.17.3)
project(sfedu_ictis_ap_dsa)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)


add_executable(sfedu_ictis_ap_dsa main.cpp Array.cpp Tests.h Tests.cpp Array.h Array.cpp TestData.h ArrayTestImpl.h PerformanceTests.cpp PerformanceTests.h Array.cpp Stack.cpp)