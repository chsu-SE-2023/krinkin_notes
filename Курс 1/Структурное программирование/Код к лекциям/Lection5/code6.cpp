#include <iostream>

int func(int a, int b) {
    return a * b;
}

double func(double a, double b) {
    return a * b;
}

int main() {
    
    int a1 = 7, b1 = 9;
    double a2 = 7.7, b2 = 9.4;

    std::cout << func(a1, b1) << std::endl;
    std::cout << func(a2, b2) << std::endl;

    return 0;
}