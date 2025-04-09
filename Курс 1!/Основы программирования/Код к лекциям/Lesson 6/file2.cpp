#include <iostream>

int main() {
    
    int n1, n2;
    std::cout << "n1 = "; std::cin >> n1;
    std::cout << "n2 = "; std::cin >> n2;

    int **a = new int*[n1];
    for (int i=0;i<n1;i++)
        a[i] = new int[n2];

    for (int i=0;i<n1;i++) {
        for (int j=0;j<n2;j++)
            a[i][j] = rand() % 9;
    }

    for (int i=0;i<n1;i++) {
        for (int j=0;j<n2;j++)
            std::cout << a[i][j] << " ";
    std::cout << std::endl;
    }

    return 0;
}