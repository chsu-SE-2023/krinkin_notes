#include <iostream>

int main() {
    double sum;
    int n;
    std::cin >> n;
    for (int i=0; i<n; i++) {
        int chis = i+1;
        int znam = i+2;
        sum+=chis/znam;
    }

    std::cout << sum << std::endl;
}