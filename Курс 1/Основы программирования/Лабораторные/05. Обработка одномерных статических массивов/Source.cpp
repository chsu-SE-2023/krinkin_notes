// Variant 15
#include <iostream>

int main() {

    const int n = 10;
    int num;
    std::cout << "Номер задания: "; std::cin >> num;

    int a[n];

    switch (num) {
        case 1:

            // Ввод цикла
            for (int i=0;i<n;i++) {
                std::cout << "a[" << i << "] = "; std::cin >> a[i];
            }

            // Вывод цикла
            for (int i=0;i<n;i++) {
                std::cout << a[i] << " ";
            }
            std::cout << std::endl;

            // Вывод после 0
            for (int i=0;i<n;i++) {
                if (a[i] == 0) {
                    for (int j=i+1;j<n;j++) {
                        std::cout << a[j] << " ";
                    }
                }
            }
            std::cout << std::endl;
            break;
        case 2:
            // Ввод цикла
            for (int i=0;i<n;i++) {
                std::cout << "a[" << i << "] = "; std::cin >> a[i];
            }

            // Вывод цикла
            for (int i=0;i<n;i++) {
                std::cout << a[i] << " ";
            }
            std::cout << std::endl;

            for (int i=0;i<n;i++) {
                if (a[i] / 100 == 0 & a[i] / 10 != 0) std::cout << a[i] << " ";
            }
            std::cout << std::endl;

            break;
    }

    return 0;
}