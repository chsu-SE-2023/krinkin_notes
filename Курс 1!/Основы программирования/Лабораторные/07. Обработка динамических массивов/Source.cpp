#include <iostream>

int main() {

    int num;
    std::cout << "Номер программы: "; std::cin >> num;

    switch (num) {
        case 1: {
            int n, num;
            std::cout << "n = "; std::cin >> n;
            std::cout << "num = "; std::cin >> num;

            int *A = new int[n];

            srand(time(0));

            // Генератор массива
            for (int i=0;i<n;i++) {
                A[i] = rand()%10;
            }

            // Вывод массива
            std::cout << "A = { ";
            for (int i=0;i<n;i++) {
                std::cout << A[i] << " ";
            }
            std::cout << "}" << std::endl;

            for (int i=0;i<n;i++) {
                if (A[i] != 0) {
                    if (num % A[i] == 0) {
                        std::cout << A[i] << " ";
                    }
                }
            }
            std::cout << std::endl;

            break;
        }
        case 2: {
            int n;
            std::cout << "n = "; std::cin >> n;

            srand(time(0));

            // Создание квадратной матрицы
            int **a = new int*[n];
            for (int i=0;i<n;i++)
                a[i] = new int[n];
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++)
                    a[i][j] = rand()%100;
            }

            // Вывод матрицы
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                    std::cout.width(3);
                    std::cout << a[i][j] << " ";
                }
                std::cout << std::endl;
            }

            int max_m = a[0][0], max_a = a[0][n-1];
            for (int i=0;i<n;i++) {
                if (a[i][i] > max_m) max_m = a[i][i];
                if (a[n-1-i][i] > max_a) max_a = a[n-1-i][i];
            }
            std::cout << std::endl;
            std::cout << "max из главной: " << max_m << std::endl;
            std::cout << "max из побочной: " << max_a << std::endl;

            break;
        }
    }

    return 0;
}