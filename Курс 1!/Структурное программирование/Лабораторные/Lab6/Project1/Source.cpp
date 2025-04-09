#include <iostream>
#include <sstream>

int _sum(int number) {
    int sum = 0;
    while (number % 10 != 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int rec_sum(int number) {
    int sum = 0;
    if (number != 0) {
        sum = rec_sum(number / 10);
        sum += number % 10;
    }
    return sum;
}

void rec_sum(int number, int& sum) {
    sum = 0;
    if (number != 0) {
        rec_sum(number / 10, sum);
        sum += number % 10;
    }
}

struct AEROFLOT
{
    std::string destination;
    std::string out_date;
    std::string out_time;
};

void structgen(int pos, int number, AEROFLOT** arr) {
    std::string buff;
    std::getline(std::cin, buff);
    if (pos < number) {
        int i = pos + 1;
        arr[pos] = new AEROFLOT;
        std::cout << "[Самолёт " << i << "] Введите место назначения: "; std::getline(std::cin, arr[pos]->destination);
        std::cout << "[Самолёт " << i << "] Введите дату и время вылета самолёта: "; std::cin >> arr[pos]->out_date >> arr[pos]->out_time;
        structgen(pos + 1, number, arr);
    }
}

void structout(int pos, int number, AEROFLOT** arr, std::string needed, int &sum) {
    if (pos < number) {
        if (arr[pos]->destination == needed) {
            int i = pos + 1;
            std::cout << "Самолёт " << i << " вылетает в " << arr[pos]->out_date << " " << arr[pos]->out_time << std::endl;
            sum++;
        }
        structout(pos + 1, number, arr, needed, sum);
    }
    if (!sum) {
        std::cout << "Самолёты не найдены!" << std::endl;
        sum = -1;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int prog;
    std::cout << "Выберите задание [1/2]: "; std::cin >> prog;

    switch (prog) {
    case 1: {
        int num;
        std::cout << "int = ";
        std::cin >> num;
        int sum = 0;

        sum = _sum(num);
        std::cout << "[Обычная] sum = " << sum << std::endl;

        sum = rec_sum(num);
        std::cout << "[Рекурсивная] sum = " << sum << std::endl;

        rec_sum(num, sum);
        std::cout << "[Рекурсивная void] sum = " << sum << std::endl;
        break;
    }
    case 2: {
        const int n = 5;
        int sum = 0;
        AEROFLOT* arr[n];
        structgen(0, n, arr);

        std::string needed;
        std::cout << "Пункт назначения: "; std::getline(std::cin, needed);
        structout(0, n, arr, needed, sum);
        break;
    }
    }

    return 0;
}
