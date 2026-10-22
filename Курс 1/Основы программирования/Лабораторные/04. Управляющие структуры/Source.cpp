// Variant 15

#include <iostream>
#include <time.h>
#include <string>

int main() {

    int num;
    std::cout << "Номер задания: "; std::cin >> num;

    int age, year, n, m, sum, count, del;
    char male, first;
    std::string a; 
    switch (num) {
        case 1: {
            std::cout << std::endl << "Сколько вам лет? [число] "; std::cin >> age;
            if (age < 15)                  std::cout << "Да Вы еще молоды!" << std::endl;
            if (15 < age & age < 60)       std::cout << "Да Вы в полном расцвете сил!" << std::endl;
            if (age > 60)                  std::cout << "Похоже, что Вы на пенсии." << std::endl;

            std::cout << std::endl << "Вы мужчина? [y/n] "; std::cin >> male;
            if (male == 'y')               std::cout << "Чтож, приятно познакомиться!" << std::endl;
            if (male == 'n')               std::cout << "Хмм, приятно познакомиться." << std::endl;

            std::cout << std::endl << "Сколько лет вы используете компьютер? [число] "; std::cin >> year;
            if (year < 3)                  std::cout << "Чтож, буду знать что вы новичок." << std::endl;
            if (3 < year & year < 10)      std::cout << "Приятно познакомиться, друг." << std::endl;
            if (10 < year & year < 30)     std::cout << "Добро пожаловать, оператор!" << std::endl;
            if (year > 30)                 std::cout << "здравствуйте, господин профессор!" << std::endl;

            std::cout << std::endl << "Вы используете меня впервые? [y/n] "; std::cin >> first;
            if (first=='y')                std::cout << "Понял, постараюсь Вам помочь!" << std::endl;
            if (first=='n')                std::cout << "Понял, не буду вмешиваться в Вашу работу!" << std::endl;

            std::cout << std::endl << "Как вы провели свой день? [текст] "; std::cin >> a;
            srand(time(0));
            switch (rand()%5) {
                case 0:
                    std::cout << "Отлично!" << std::endl;
                    break;
                case 1:
                    std::cout << "Рад за Вас!" << std::endl;
                    break;
                case 2:
                    std::cout << "Поздравляю!" << std::endl;
                    break;
                case 3:
                    std::cout << "Чтож..." << std::endl;
                    break;
                case 4:
                    std::cout << "Сочувствую..." << std::endl;
                    break;
            }
            break;
        }
        case 2: {
            std::cout << "n = "; std::cin >> n;
            for (int i=1;i<=n;i++) {
                for (int j=1;j<=n+1-i;j++) std::cout << i << " ";
                std::cout << std::endl;
            }
            break;
        }
        case 3: {
            std::cout << "M = "; std::cin >> m;
            std::cout << "N = "; std::cin >> n;

            for (int i=m;i<=n;i++) {
                int num = i;
                sum = 0;
                while (num > 0) {
                    sum += num % 10;
                    num /= 10;
                }
                count = 0;
                for (int i=1;i<=sum;i++) {
                    if (sum % i == 0) count++;
                }
                del = 0;
                for (int i=1;i<=count;i++) {
                    if (sum % i == 0) del++;
                }
                if (del == 2) std::cout << i << " (" << count << ")" << std::endl;
            }
            break;
        }
    }

    return 0;
}