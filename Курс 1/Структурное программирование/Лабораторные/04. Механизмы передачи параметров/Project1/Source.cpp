#include <iostream>
#include <windows.h>

int fact(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

double series_sum(double x, double p) {
	double sum = 1;
	for (int i = 1; abs(pow(x, i) / fact(i)) >= p; i++) {
		sum += pow(x, i) / fact(i);
	}
	return sum;
}

void series_sum_p(double* x, double* p, double* result) {
	*result = 1;
	for (int i = 1; abs(pow(*x, i) / fact(i)) >= *p; i++) {
		*result += pow(*x, i) / fact(i);
	}
}

void series_sum_l(double& x, double& p, double& result) {
	result = 1;
	for (int i = 1; abs(pow(x, i) / fact(i)) >= p; i++) {
		result += pow(x, i) / fact(i);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int var;
	std::cout << "Выберите вариант работы функции:\n1). Через значения.\n2). Через указатель.\n3). Через ссылку.\n: "; std::cin >> var;

	double x = 0.50, p = 0.001;
	std::cout << "x = " << x << std::endl;

	double result = 0;

	switch (var) {
	case 1: {
		result = series_sum(x, p);
		break;
	}
	case 2: {
		series_sum_p(&x, &p, &result);
		break;
	}
	case 3: {
		series_sum_l(x, p, result);
		break;
	}
	}

	std::cout << "Сумма ряда: " << result << std::endl;

	return 0;
}