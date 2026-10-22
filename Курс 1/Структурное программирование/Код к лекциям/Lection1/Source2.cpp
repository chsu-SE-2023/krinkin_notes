#include <iostream>

struct student {
    std::string fio;
    int m1;
    int m2;
    int m3;
};

int main() {
    const int n = 5;
    int col;
    student* a[n];

    for (int i=0;i<n;i++) {
        a[i] = new student;
        std::cout << "Student " << i+1 << "." << std::endl;
        std::cout << "FIO: "; std::cin >> a[i]->fio;
        std::cout << "Mark 1: "; std::cin >> a[i]->m1;
        std::cout << "Mark 2: "; std::cin >> a[i]->m2;
        std::cout << "Mark 3: "; std::cin >> a[i]->m3;
    }

    for (int i=0;i<n;i++) {
        if (a[i]->m1 > 3 && a[i]->m2 > 3 && a[i]->m3 > 3) {
            col++;
        }
    }

    std::cout << "Стипендия будет у " << col << " человек." << std::endl;

    return 0;
}