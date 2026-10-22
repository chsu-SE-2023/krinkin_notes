// Variant 15
#include <iostream>

int main() {

    int num;
    std::cout << "Номер задания: "; std::cin >> num;

    switch (num) {
        case 1: {
            const int n = 2, m = 1;

            // Создание двумерного  массива
            int a[n][m];

            // Ввод матрицы
            for (int i=0;i<n;i++) {
                for (int j=0;j<m;j++) {
                    std::cout << "A[" << i << "][" << j << "] = "; std::cin >> a[i][j];
                }
            }

            //Находим самый длинный элемент
            int maxWidth = 0, currentWidth = 0;
            for (int i=0;i<n;i++) {
                for (int j=0;j<m;j++) {
                    currentWidth = std::to_string(a[i][j]).length();
                    if (currentWidth > maxWidth) {
                        maxWidth = currentWidth;
                    }
                }
            }

            // Вывод матрицы
            for (int i=0;i<n;i++) {
                for (int j=0;j<m;j++) {
                    std::cout.width(maxWidth + 1);
                    std::cout << a[i][j] << " ";
                }
                std::cout << std::endl;
            }

            // Поиск минимума и максимума
            int min = a[0][0], max = a[0][0], min_i, min_j, max_i, max_j;
            for (int i=0;i<n;i++) {
                for (int j=0;j<m;j++) {
                    if (a[i][j] < min) {min = a[i][j]; min_i = i; min_j = j;};
                    if (a[i][j] > max) {max = a[i][j]; max_i = i; max_j = j;};
                }
            }
            a[min_i][min_j] = max; a[max_i][max_j] = min;

            // Вывод матрицы
            std::cout << std::endl;
            for (int i=0;i<n;i++) {
                for (int j=0;j<m;j++) {
                    std::cout.width(maxWidth + 1);
                    std::cout << a[i][j];
                }
                std::cout << std::endl;
            }

            break;
        }
        case 2: {
            const int n1 = 2, n2 = 3;

            // Создание заданной матрицы
            int a[n1][n2];
            srand(time(0));
            for (int i=0;i<n1;i++) {
                for (int j=0;j<n2;j++)
                    a[i][j] = rand()%100;
            }

            // Вывод матрицы
            for (int i=0;i<n1;i++) {
                for (int j=0;j<n2;j++) {
                    std::cout << a[i][j] << " ";
                }
                std::cout.width(3);
                std::cout << std::endl;
            }
            
            // Смена столбцов
            for (int j=0;j<n2;j+=2) {
                int tmp;
                for (int i=0;i<n1;i++) {
                    if (n2 % 2 != 0) {
                        if (j==n2-1) break;
                    }
                    tmp = a[i][j+1];
                    a[i][j+1] = a[i][j];
                    a[i][j] = tmp;
                }
            }

            // Вывод матрицы
            std::cout << std::endl;
            for (int i=0;i<n1;i++) {
                for (int j=0;j<n2;j++) {
                    std::cout.width(3);
                    std::cout << a[i][j] << " ";
                }
                std::cout << std::endl;
            }
            break;
        }
    }
    return 0;
}