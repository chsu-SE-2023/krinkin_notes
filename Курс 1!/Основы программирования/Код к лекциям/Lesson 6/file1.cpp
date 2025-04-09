// Динамические переменные

#include <iostream>

int main() {

    int *p=new int;
    std::cout << p << std::endl; // Адрес в куче
    std::cout << *p << std::endl; // Содержание

    *p=25;
    std::cout << *p << std::endl;

    delete(p); // Удаление динамической переменной
    std::cout << p << std::endl;
    std::cout << *p << std::endl;

    p = NULL; // Обнуление
    std::cout << p << std::endl;
    std::cout << *p << std::endl;

    return 0;
}