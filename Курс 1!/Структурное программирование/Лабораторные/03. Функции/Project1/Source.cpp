#define _USE_MATH_DEFINES

#include <iostream>
#include <windows.h>
#include <cmath>

double volume(double radius) {
	return 4.0 / 3.0 * M_PI * pow(radius, 3);
}

void output(int* arr, int arr_len) {
	std::cout << "Array = { ";
	for (int i = 0; i < arr_len; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "}" << std::endl;
}

void input(int* out_arr, int arr_len) {
	srand(time(0));
	for (int i = 0; i < arr_len; i++) {
		out_arr[i] = rand() % 10;
	}
}

void if_output(int* arr, int arr_len, int num) {
	for (int i = 0; i < arr_len; i++) {
		if (arr[i] != 0) {
			if (num % arr[i] == 0) {
				std::cout << arr[i] << " ";
			}
		}
	}
	std::cout << std::endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int prog;
	std::cout << "Введите номер программы: "; std::cin >> prog;

	switch (prog) {
	case 1: {
		double radius;
		std::cout << "Введите радиус сферы: "; std::cin >> radius;

		std::cout << std::endl << "Объём сферы равен " << volume(radius) << std::endl;
		}
		  break;
	case 2: {
        int n, num;
        std::cout << "n = "; std::cin >> n;
        std::cout << "num = "; std::cin >> num;

        int* A = new int[n];

        // Генератор массива
		input(A, n);

        // Вывод массива
		output(A, n);

		// Вывод нужного
		if_output(A, n, num);
        break;
	}
	}
	return 0;
}