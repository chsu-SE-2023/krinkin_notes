#include <iostream>

int main() {

    char str[100] = "0000, 0001, 0010, 0011, 0100 ..., 1111 !!!";
    char seps[100] = " ,.!?:;";
    char* token = strtok(str, seps);
    int num = 0;

    while (token != NULL) {
        std::cout << token << std::endl;
        token = strtok(NULL, seps);
        num++;
    }

    std::cout << num << std::endl;

    return 0;
}