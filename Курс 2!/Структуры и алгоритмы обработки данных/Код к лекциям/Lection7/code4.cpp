#include <iostream>

void vivod(int *a, int n) {
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

void shell(int *a, int n) {
    int step = n/2;
    while (step > 0) {
        for (int i = 0; i < n - step; i++) {
            int j = i;
            while (j >= 0 && a[j] > a[j + step]) {
                std::swap(a[j], a[j+step]);
                j -= step;
            }
        }
        step /= 2;
    }
}

int main() {
	const int n = 10;
	int a[n] = { 2, 6, 3, 9, 1, 5, 2, 8, 9, 10 };
	shell(a, n);
	vivod(a, n);
	return 0;
}
