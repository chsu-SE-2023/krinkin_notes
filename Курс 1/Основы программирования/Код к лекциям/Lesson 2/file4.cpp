// Найти все натуральные числа равные сумме факториалов своих цифр.

#include <iostream>

int main() {

    int n = 1000;

    for (int i=1;i<=n;i++) {
        int s = 0;
        int a = 1;
        while (a>0) {
            int digit = a%10;
            int f = 1;
            for (int j=2;j<=digit;j++)
                f*=j;
            s+=f;
            a/=10;
        }
        if (s==i) std::cout << i << " ";
    }

    std::cout << std::endl;

    return 0;
}
