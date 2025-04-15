#include <iostream>

class Stud {
public:
    Stud(char* nm, int n, float r);
    ~Stud() {};
    Stud& operator=(const Stud& m); // Оператор присваивания
    void print() const; // Вывод информации
    float summa(); // Начисление стипендии (использовать только в while True (пожалуйста))
    float input(char*, int, float); // Ввод данных
protected:
    char name[30]; // Имя
    int N; // Номер
    float R; // Рейтинг

private:
    char *sport; // Увлечения
};

// Здесь должны быть определения функций

class Asp: public Stud { // dass == dumbass
public:
/* Коструктор, деструктор, перегрузка не наследуются!
    (Наследуются)
    void print() const;
    float summa();
    float input(char*, int, float); */
    Asp(char* nm, int n, float r, char* th, int);
    Asp(const Asp& a);
    ~Asp() {};
    Asp& operator=(const Asp& a);
    void print() const; // Переопределяемая/перекрываемая функция
    float input(char*, int, float, char*, int);
    int Hirsh();
protected:
/*
    Имеется доступ для чтения для:
    Stud.name;
    Stud.N;
    Stud.R;
*/
    char thesis[300]; // Тема доклада
    int k; // Публикации
};

class Doct: public Asp {
public:
    Doct();
    Doct(char* nm, int n, float r, char* th, int k);
    Doct(const Doct& d);
    ~Doct() {};
    Doct& operator=(const Doct& d);
    void print() const; // Переопределяемая/перекрываемая функция
    float grant();
protected:
/*
    Имеется доступ для чтения для:
    Stud.name;
    Stud.N;
    Stud.R;
    Asp.thesis;
    Asp.k;
*/
    float G;
};

class Worker {
public:
    //Конструктор, деструктор
    void print() const;
protected:
    char name[30];
    char prof[30];
    int R;
};

class StudWorker: public Stud, public Worker {
public:
    //StudWorker(): Stud(), Worker(), T(0) {};
    void print() const;
protected:
    int T; // Отпуск
};

void StudWorker::print() const {
    std::cout << T << prof << Stud::R; // (Worker::R)
}