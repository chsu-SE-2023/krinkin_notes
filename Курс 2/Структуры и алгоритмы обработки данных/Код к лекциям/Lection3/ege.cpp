#include <iostream>

int max_ = 0;
void poisk(int* m, int n, int i, int j, int s) {
    s+=m[i*n+j];
    if (i==n-1 && j==n-1 && s>max_)
        max_=s;
    if (i<n-1) poisk(m, n, i+1, j, s);
    if (j<n-1) poisk(m, n, i, j+1, s);
}

int main() {
    const int n = 4;
    int s = 0;
    int m[n][n] = {
        {2, 1, 1, 1},
        {1, 2, 1, 1},
        {1, 1, 2, 1},
        {1, 1, 1, 2}
    };

    poisk(&m[0][0], n, 0, 0, s);

    std::cout << max_ << std::endl;

    return 0;
}