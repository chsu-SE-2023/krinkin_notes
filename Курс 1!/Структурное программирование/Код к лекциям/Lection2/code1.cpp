#include <iostream>

int main() {
    char a[] = {"L", "e", "h", "a", "\0"};

    std::cout << a << std::endl;

    return 0;
}