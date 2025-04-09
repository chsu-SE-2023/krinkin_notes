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
    friend class Router;
    friend class Tests;

public:
    Switch(); // Конструктор по умолчанию
    Switch(const int*, int); // clients
    Switch(const int*); // address
    Switch(const int*, int, const int*); // clients, address
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

class Router: public Switch {
private:
    char* ssid;
    char* passwd;
    bool wpa;

    void set_defaults();
    friend class Tests;

public:
    Router();
    Router(const char*, const char*);
    Router(const Switch&);
    Router(const double*&, const int*, int, const int*, const char*, const char*);
    char* get_ssid() const;
    bool wpa_enabled() const;
    void print_info() const;
    void set_ssid(char*);
    void set_passwd(char*);
    void set_wpa(bool);
    void reset();
};
