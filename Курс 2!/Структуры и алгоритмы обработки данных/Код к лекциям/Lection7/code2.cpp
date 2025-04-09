#include <iostream>

void vivod(int *a, int n) {
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

void bubble(int *a, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n-1; j > i; j--)
            if (a[j] < a[j-1])
                std::swap(a[j], a[j-1]);
}

int main() {
	const int n = 10;
	int a[n] = { 2, 6, 3, 9, 1, 5, 2, 8, 9, 10 };
	bubble(a, n);
	vivod(a, n);
	return 0;
}
