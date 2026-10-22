#include <iostream>

void input(int *arr, int count) {
    for (int i=0;i<count;i++) {
        srand(time(0));
        arr[i] = rand() % 100;
    }
}

void output(int *arr, int count) {
    for (int i=0;i<count;i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int num = 20;
    int a[num];
    
    input(a, num);
    output(a, num);

    return 0;
}