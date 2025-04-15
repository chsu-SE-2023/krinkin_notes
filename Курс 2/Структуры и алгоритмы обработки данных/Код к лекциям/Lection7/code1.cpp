#include <iostream>

void vivod(int *a, int n) {
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

void insertion(int *a, int n) {
	for (int i = 1; i < n; i++) { // i = 2 для границы
		int j = i, k = a[i]; // a[0] = k; для границы
		while (k > 0 && k < a[j - 1]) { // k > 0 & для границы
            a[j] = a[j-1]; 
            j--;
        }
        a[j] = k;
	}
}

int main() {
	const int n = 10;
	int a[n] = { 2, 6, 3, 9, 1, 5, 2, 8, 9, 10 };
	insertion(a, n);
	vivod(a, n);
	return 0;
}
