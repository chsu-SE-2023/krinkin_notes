#include <iostream>
#include <time.h>

int main() {
    srand(time(0));
    int n, a, b, c, d, a1, b1, c1, d1, co, bu, k = 0;

    do {
        a = rand()%10; b = rand()%10;
        c = rand()%10; d = rand()%10;
    }
    while (a == b || a == c || a == d || b == c || b == d);
    // std::cout << a << b << c << d << std::endl; // Debug

    do {
        std::cout << "Введите выше число: "; std::cin >> n;
        a1 = n/1000;
        b1 = n/100 % 10;
        c1 = n/10 % 10;
        d1 = n % 10;

        co=0;
        if (a1==a || a1==b || a1==c || a1 == d) co++;
        if (b1==a || b1==b || b1==c || b1 == d) co++;
        if (c1==a || c1==b || c1==c || c1 == d) co++;
        if (d1==a || d1==b || d1==c || d1 == d) co++;

        bu=0;
        if (a==a1) bu++;
        if (b==b1) bu++;
        if (c==c1) bu++;
        if (d==d1) bu++;

        std::cout << co << " - " << bu << std::endl;
        k++;
    } 
    while (bu < 4);

    std::cout << "Поздравляем!!!" << std::endl << "Вы выйграли!!!" << std::endl << "Число ходов: " << k << std::endl;;

    return 0;
}