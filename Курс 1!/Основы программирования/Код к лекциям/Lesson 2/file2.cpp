// Работа с числителем числа

// Дано натуральное число.
// Найти сумму, произведение и количество делителей

#include <iostream>

int main(){
    int num = 12;
    int sum = 0, sub = 0, val = 0;

    for (int del=1;del<=num;del++)
        if (num % del==0) {
            val++;
            sum+=del;
            sub*=del;
        }

    std::cout << sum << std::endl;
    std::cout << sub << std::endl;
    std::cout << val << std::endl;

    return 0;
}