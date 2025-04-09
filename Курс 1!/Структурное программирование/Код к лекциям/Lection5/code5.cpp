#include <iostream>

void input(int *arr, int n1, int n2) {
    for (int i=0;i<n1;i++) {
        for (int j=0;j<n2;j++) {
            srand(time(0));
            arr[i*n2+j] = rand() % 100;
        }
    }
}

void output(int *arr, int n1, int n2) {
    for (int i=0;i<n1;i++) {
        for (int j=0;j<n2;j++) {
            std::cout.width(3);
            std::cout << arr[i*n2+j];
        }
        std::cout << std::endl;
    }
}

int main() {
    const int n1 = 7, n2 = 9;
    int a[n1][n2];
    
    input(&a[0][0], n1, n2);
    output(&a[0][0], n1, n2);

    return 0;
}