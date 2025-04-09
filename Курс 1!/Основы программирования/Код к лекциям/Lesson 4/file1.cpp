// Поменять местами минимальный и  максимальный элементы в отличие от предыдущено примера для того чтобы поменять максимум и минимум в массиве нам надо знать не их значение, а их местоположение

#include <iostream>

int main(){

    int array[10] = {65, 6, 9, 7, 23, 15, 87, 9, 0, 4};

    for (int a=0;a<10;a++) {
        std::cout << array[a] << " ";
    }
    std::cout << std::endl;

    int max=array[0], min=array[0], nmax=0, nmin=0;
    for (int a=0;a<10;a++) {
        if (array[a]>max) {max=array[a]; nmax=a;};
        if (array[a]>min) {min=array[a]; nmin=a;};
    }
    array[nmax]=min; array[nmin]=max;

    for (int a=0;a<10;a++) {
        std::cout << array[a] << " ";
    }
    std::cout << std::endl;

    return 0;
}