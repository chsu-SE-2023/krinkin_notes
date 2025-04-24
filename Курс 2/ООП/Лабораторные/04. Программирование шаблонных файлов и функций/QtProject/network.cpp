// VARIANT A12

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "network.h"

// Определение конструктора по умолчанию
Switch::Switch() {
    set_defaults();
}

// Определение конструктора с парамером clients
Switch::Switch(const int* clients, int count) {
    set_defaults();
    this->connected = count;
    this->set_clients(clients);
}

// Определение конструктора с парамером address
Switch::Switch(const int* address) {
    set_defaults();
    this->set_address(address);
}

// Определение конструктора с парамерами clients и address
Switch::Switch(const int* clients, int count, const int* address) {
    set_defaults();
    this->connected = count;
    this->set_clients(clients);
    this->set_address(address);
}

// Определение конструктора с полным набором параметров
Switch::Switch(const double*& packets, const int* clients, int count, const int* address) {
    this->set_defaults();
    this->connected = count;
    this->packets = packets;
    this->set_clients(clients);
    this->set_address(address);
}

// Определение копирующего конструктора
Switch::Switch(const Switch& sw) {
    this->packets = sw.packets;
    this->connected = sw.connected;
    this->set_clients(sw.clients);
    this->set_address(sw.address);
};

// Деструктор
Switch::~Switch() {
    /*delete this->packets;
    delete[] this->clients;
    delete[] this->address;*/
}

bool operator>(Switch& first, Switch& second) {
    /*
     * Оператор проверяет больше ли в устройстве на первой полке устройств, чем во второй.
     */
    return first.connected > second.connected;
}

// Эта компонентная функция печатает данные из объекта на экран.
void Switch::print_info() const {
    std::cout << "  Switch info: " << std::endl;
    std::cout << "   - Clients capacity: " << this->cli_cap << std::endl;
    std::cout << "   - Connected devices (" << this->connected << "): ";
    for (int i = 0; i < this->connected; i++)
        std::cout << this->clients[i] << " ";
    std::cout << std::endl;
    std::cout << "   - MAC Address: ";
    for (int i = 0; i < 5; i++)
        std::cout << this->address[i] << ":";
    std::cout << "\b" << " " << std::endl;
}

// Эта компонентная функция возвращает значение поля address (геттер). 
int* Switch::get_address() const {
    return this->address;
};

// Эта компонентная функция устанавливает стандатные значения для объекта (сеттер). 
void Switch::set_defaults() {
    this->connected = 0;
    this->packets = nullptr;
    this->clients = new int[this->cli_cap]();
    this->address = new int[5]{0, 0, 0, 0, 0};
}

// Эта компонентная функция устанавливает значение поля address (сеттер).
void Switch::set_address(const int* address) {
    const int addr_len = 5;
    this->address = new int[addr_len];
    for (int i = 0; i < addr_len; i++)
        this->address[i] = address[i];
}

// Эта компонентная функция устанавливает значение поля clients.
void Switch::set_clients(const int* clients) {
    this->clients = new int[this->cli_cap]();
    for (int i = 0; i < this->connected; i++)
        this->clients[i] = clients[i];
}

// Эта компонентная функция возвраащет значения поля connected.
int Switch::clients_count() const {
    return this->connected;
}

Router::Router() {
    set_defaults();
}

Router::Router(const Switch& sw) {
    this->packets = sw.packets;
    this->connected = sw.connected;
    this->set_clients(sw.clients);
    this->set_address(sw.address);
}

Router::Router(const char* ssid, const char* passwd) {
    set_defaults();
    this->ssid = new char[strlen(ssid)+1];
    strcpy(this->ssid, ssid);
    this->passwd = new char[strlen(passwd)+1];
    strcpy(this->passwd, passwd);
}

Router::Router(const double*& packets, const int* clients, int count, const int* address, const char* ssid, const char* passwd) {
    this->set_defaults();
    this->connected = count;
    this->packets = packets;
    this->set_clients(clients);
    this->set_address(address);
    this->ssid = new char[strlen(ssid)+1];
    strcpy(this->ssid, ssid);
    this->passwd = new char[strlen(passwd)+1];
    strcpy(this->passwd, passwd);
}

char* Router::get_ssid() const {
    return this->ssid;
}

bool Router::wpa_enabled() const {
    return wpa;
}

void Router::print_info() const {
    std::cout << "  Router info: " << std::endl;
    std::cout << "   - Clients capacity: " << this->cli_cap << std::endl;
    std::cout << "   - Connected devices (" << this->connected << "): ";
    for (int i = 0; i < this->connected; i++)
        std::cout << this->clients[i] << " ";
    std::cout << std::endl;
    std::cout << "   - MAC Address: ";
    for (int i = 0; i < 5; i++)
        std::cout << this->address[i] << ":";
    std::cout << "\b" << " " << std::endl;
    std::cout << "   - SSID: "; 
    this->ssid ? std::cout << this->ssid : std::cout << "None";
    std::cout << std::endl;
    std::cout << "   - WPA: ";
    this->wpa ? std::cout << "enabled" : std::cout << "disabled";
    std::cout << std::endl;
}

void Router::set_ssid(char* ssid) {
    this->ssid = new char[strlen(ssid)+1];
    strcpy(this->ssid, ssid);
}

void Router::set_passwd(char* passwd) {
    this->passwd = new char[strlen(passwd)+1];
    strcpy(this->passwd, passwd);
}

void Router::set_wpa(bool wpa) {
    this->wpa = wpa;
}

void Router::reset() {
    this->set_defaults();
}

void Router::set_defaults() {
    this->connected = 0;
    this->packets = nullptr;
    this->clients = new int[this->cli_cap]();
    this->address = new int[5]{0, 0, 0, 0, 0};
    this->ssid = new char[5];
    strcpy(this->ssid, "admin");
    this->passwd = new char[5];
    strcpy(this->passwd, "admin");
    this->wpa = false;
}
