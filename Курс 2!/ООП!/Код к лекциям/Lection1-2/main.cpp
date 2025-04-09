#include "some_class.h"

int main() {

    Pixel t1; // Конструктор по умолчанию
    Pixel t1 = Pixel(); // Коструктор без параметров
    Pixel mt[10];
    Pixel t4(3); // Конструктор с int
    Pixel t5("red"); // Конструктор с char*
    Pixel t2(2, 2, "red", 1.1); // Конструктор со всеми параметрами
    Pixel t3(t2); // Конструктор копирования

    t5.get_color(); // Вызов сеттерв
    t1.set_x(1); // Вызов геттера

    return 0;
}