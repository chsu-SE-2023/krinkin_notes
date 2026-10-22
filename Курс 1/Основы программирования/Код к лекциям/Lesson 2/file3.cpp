// Вывести на экран таблицу простых чисел от 2 до n

#include <iostream>

int main() {
    int n = 1000;

    for (int i=2,k=0;i<=n;i++)
        for (int del=2;del<=sqrt(i);del++)
            if (i % del==0) {
                k++;
                break;
            } 
        if (k==0) {
            std::cout.width(8);
            std::cout << i;
        }
    std::cout << std::endl;

    return 0;
}