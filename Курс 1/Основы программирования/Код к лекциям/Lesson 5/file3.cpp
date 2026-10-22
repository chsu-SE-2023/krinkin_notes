// Обход массива с помощью указателей

#include <iostream>

int main() {

    const int n = 10;
    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    int *p=a;
    for (int i=1;i<=n;i++){
        std::cout << *p++ << " ";
    }
    std::cout << std::endl;

    return 0;
}