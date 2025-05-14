// VARIANT A12

#pragma once

class Switch {

private:
    // friend class ServerRoom; // Объявление дружественного класса
    static const int cli_cap = 32; // Статическая
    const double* packets; // Указатель
    int* clients; // Массив
    int* address; // Произвольный
    int connected; // Произвольный

    void set_defaults();

public:
    Switch(); // Конструктор по умолчанию
    Switch(const int*, int); // clients
    Switch(const int*); // address
    Switch(const int*, int, const int*); // mask, address
    Switch(const double*&, const int*, int, const int*); // Полный набор
    Switch(const Switch&); // Копирующий
    ~Switch();
    friend bool operator>(Switch&, Switch&); // Оператор сравнения
    void print_info() const;
    int* get_address() const;
    void set_address(const int*);
    void set_clients(const int*);
    int clients_count() const;
};
