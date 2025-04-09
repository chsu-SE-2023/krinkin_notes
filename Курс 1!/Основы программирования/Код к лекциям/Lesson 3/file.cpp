#include <iostream>
#include <fstream>

int main() {

    const int n = 10;
    int a[n];

    // for (int i=0;i<n;i++) { // Ввод массива из консоли
    //     std::cout << "a[" << i << "] = "; std::cin >> a[i]; std::cout << std::endl;
    // }

    std::ifstream f("input.txt");

    for (int i=0;i<n;i++) // Ввод массива из файла
        f >> a[i];
    f.close();

    for (int i=0;i<n;i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}