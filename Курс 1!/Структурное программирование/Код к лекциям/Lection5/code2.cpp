#include <iostream>

void f(int n, int *res) {
    *res = 1;
    for (int i=1;i<=n;i++) {
        *res = *res * i;
    }
}

int main() {
    int n = 5, res = 0;
    f(n, &res);
    std::cout << res << std::endl;
    return 0;
}