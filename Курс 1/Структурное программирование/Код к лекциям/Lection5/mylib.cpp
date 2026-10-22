#include "mylib.h"

int f(int n) {
    if (n==0) return 1;
    return f(n-1);
}

int g(int a, int b) {
    return a*a+b*b;
}