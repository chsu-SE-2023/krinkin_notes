// Тест 9: Определение високосного года (логические операторы)
#include <iostream>
using namespace std;

int main() {
    int year = 2024;

    /* Високосный год:
       - делится на 4 и не делится на 100,
       - либо делится на 400 */
    bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    cout << year << (leap ? " is a leap year." : " is not a leap year.") << endl;
    return 0;
}
