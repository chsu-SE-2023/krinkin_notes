#include <iostream>

int main() {

    int a=21,b=32;
    int *p1 = &a;
    int *p2 = &b;
    int *p3 = 0x7ff7b7e42214;

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;

    p2+=1;
    (*p2)++;

    std::cout << a << std::endl;

    return 0;
}