#include <iostream>

void plus_(int* m, int n) {
    int i = n;
    while (m[i] == 1)
        m[i--] = 0;
    m[i] = 1;
}

int main() {
    const int n = 5;
    int min = 15;
    int m[n+1] = {0, 1, 2, 3, 4, 5},
        bin[n+1] = {0, 0, 0, 0, 0, 0},
        best[n+1] = {0, 0, 0, 0, 0, 0};
    while (bin[0]==0) {
        int s1 = 0, s2 = 0;
        for (int i = 1; i <= n; i++)
            if (bin[i]==0) s1 += m[i];
            else s2 += m[i];
        if (abs(s1 - s2) < min) {
            for (int i = 1; i <= n; i++)
                best[i] = bin[i];
            min = abs(s1 - s2);
        }
        plus_(bin, n);
    }

    std::cout << min << std::endl;
    std::cout << "1 group:" << std::endl;
    for (int i = 1; i <= n; i++)
        if (best[i] == 0) std::cout << m[i] << " ";
    std::cout << std::endl;
    std::cout << "2 group:" << std::endl;
    for (int i = 1; i <= n; i++)
        if (best[i] == 1) std::cout << m[i] << " ";
    std::cout << std::endl;
    return 0;
}