#include <iostream>

void vivod(int *a, int n) {
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

void shaker(int *a, int n) {
    int left = 1, right = n-1, k = right;
    do { // Душная скобочка
        for (int j = right; j >= left; j--)
            if (a[j] < a[j - 1]) {
                std::swap(a[j], a[j - 1]);
                k = j;
            }
        left = k + 1;

        for (int j = left; j <= right; j++)
            if (a[j] < a[j - 1]) {
                std::swap(a[j], a[j - 1]);
                k = j;
            }
        right = k - 1;
    } while (left <= right);
}

int main() {
	const int n = 10;
	int a[n] = { 2, 6, 3, 9, 1, 5, 2, 8, 9, 10 };
	shaker(a, n);
	vivod(a, n);
	return 0;
}
