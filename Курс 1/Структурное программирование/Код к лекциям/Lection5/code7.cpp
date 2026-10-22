#include <iostream>
#include <unistd.h>

int i = 0;
double persent;

void f() {
    i += 1;
    usleep(10);
    persent = (i / 523864.0) * 100.0;
    std::cout << "\r" << std::round(persent) << "%   ";
    f();
}

int main(){
    f();
    return 0;
}