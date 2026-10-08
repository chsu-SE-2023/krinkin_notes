#include "random"
#include <iostream>
#include <iomanip>
#include "omp.h"
#include <chrono>
#include <windows.h>

const int WIDTH = 4;

int divp(int a, int b) {
	return (a + b - 1) / b;
}

void print(int** matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			std::cout << std::setw(WIDTH) << matrix[i][j];
		std::cout << std::endl;
	}
}

void print(int* vec, int n) {
	for (int i = 0; i < n; i++)
		std::cout << std::setw(WIDTH) << vec[i];
	std::cout << std::endl;
}

void print(const char* str, int w = 1) {
	std::cout << std::setw(w) << str << std::endl;
}

int main() {
#ifdef _DEBUG
	int n = 3, m = 3;
#else
	int n = 10000, m = 10000;
#endif
	srand(0);

	int** matrix = new int*[n]();
	for (int i = 0; i < n; i++)
		matrix[i] = new int[m]();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = 1+rand() % 9;

#ifdef _DEBUG
	print(matrix, n, m);
	print("x", WIDTH * divp(n, 2));
#endif

	int* vec = new int[n]();
	for (int i = 0; i < n; i++) 
		vec[i] = rand() % 10;

#ifdef _DEBUG
	print(vec, n);
	print("=", WIDTH * divp(n, 2));
#endif

	int* result = new int[n] {0};
	
	auto start = std::chrono::high_resolution_clock::now();

	print("Single");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			result[i] += matrix[i][j] * vec[j];

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

	start = std::chrono::high_resolution_clock::now();

	print("Parallel");
#pragma omp parallel for collapse(2)
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			result[i] += matrix[i][j] * vec[j];
#ifdef _DEBUG
	print(result, m);
#endif

	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Time taken: " << duration.count() << " microseconds";

	return 0;
}