#include <iostream>

void arrgen(int lenght, int* array) {
    srand(time(0));
    for (int i=0;i<lenght;i++) {
        int num = rand() % 100;
        if (num) {
            array[i] = num;
        }
    }
    array[rand()%lenght] = 0;
}

void arrgen(int lenght, double* array) {
    srand(time(0));
    for (int i=0;i<lenght;i++) {
        double num = rand() / 10;
        if (num) {
            array[i] = num;
        }
    }
    array[rand()%lenght] = 0;
}

void arrgen(int lenght, char* array) {
    srand(time(0));
    for (int i=0;i<lenght;i++) {
        char num = 65 + rand() % 63;
        if (num) {
            array[i] = num;
        }
    }
    array[rand()%lenght] = 0;
}

void arrprint(int lenght, int* array) {
    std::cout << "* Full int: { ";
    for (int i=0;i<lenght;i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "}" << std::endl;
}

void arrprint(int lenght, double* array) {
    std::cout << "* Full double: { ";
    for (int i=0;i<lenght;i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "}" << std::endl;
}

void arrprint(int lenght, char* array) {
    std::cout << "* Full char: { ";
    for (int i=0;i<lenght;i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "}" << std::endl;
}

void arrpzero(int lenght, int* array) {
    std::cout << "* Zero int: { ";
    for (int i=0;i<lenght;i++) {
        if (array[i] == 0) {
            for (int j=i+1;j<lenght;j++) {
                std::cout << array[j] << " ";
            }
        }
    }
    std::cout << "}" << std::endl;
}

void arrpzero(int lenght, double* array) {
    std::cout << "* Zero double: [ ";
    for (int i=0;i<lenght;i++) {
        if (array[i] == 0) {
            for (int j=i+1;j<lenght;j++) {
                std::cout << array[j] << " ";
            }
        }
    }
    std::cout << "]" << std::endl;
}

void arrpzero(int lenght, char* array) {
    std::cout << "* Zero char: [ ";
    for (int i=0;i<lenght;i++) {
        if (array[i] == 0) {
            for (int j=i+1;j<lenght;j++) {
                std::cout << array[j] << " ";
            }
        }
    }
    std::cout << "]" << std::endl;
}

int main() {

    const int n = 10;
    int i_arr[n];
    double f_arr[n];
    char c_arr[n];

    // Генерация массива
    arrgen(n, i_arr);
    // Вывод массива
    arrprint(n, i_arr);
    // Вывод после 0
    arrpzero(n, i_arr);

    // Генерация массива
    arrgen(n, f_arr);
    // Вывод массива
    arrprint(n, f_arr);
    // Вывод после 0
    arrpzero(n, f_arr);

    // Генерация массива
    arrgen(n, c_arr);
    // Вывод массива
    arrprint(n, c_arr);
    // Вывод после 0
    arrpzero(n, c_arr);

    return 0;
}