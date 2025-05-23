// VARIANT A12
#include "tests.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

int main() {

    std::cout << "# Variant 5" << std::endl;
    std::cout << "Tests (7):" << std::endl;
    Tests* tests;

    std::cout << " * malloc test - ";
    tests = new Tests();
    std::cout << tests->memory() << std::endl;
    delete tests;

    std::cout << " * data fields test - ";
    tests = new Tests();
    std::cout << tests->data() << std::endl;
    delete tests;

    std::cout << " * container test - ";
    tests = new Tests();
    std::cout << tests->container()<< std::endl;
    delete tests;

    std::cout << " * search test - ";
    tests = new Tests();
    std::cout<< tests->search() << std::endl;
    delete tests;

    std::cout << " * sort test - ";
    tests = new Tests();
    const char* hui = tests->sort();
    std::cout << hui << std::endl;
    delete tests;

    std::cout << " * operators test - ";
    tests = new Tests();
    std::cout << tests->opers() << std::endl;
    delete tests;

    std::cout << " * stats test - ";
    tests = new Tests();
    std::cout << tests->stats() << std::endl;
    delete tests;

    return 0;
}
