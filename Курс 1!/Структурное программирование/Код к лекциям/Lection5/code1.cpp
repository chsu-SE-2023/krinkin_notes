#include <iostream>

int f(int n) {
    int res = 1;
    for (int i=1;i<=n;i++) {
        res = res * i;
    }
    return res;
}

int main() {
    int n = 5;
    std::cout << f(n) << std::endl;
    return 0;
}