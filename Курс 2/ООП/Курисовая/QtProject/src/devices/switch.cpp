#include <iostream>
#include "switch.h"

/**
* Приватный метод, задающий значения по умолчанию
*/
void Switch::set_defaults() {
    this->clients = {};
}

/**
* Конструктор по умолчанию
*/
Switch::Switch() : Repeater() {
    set_defaults();
}

/**
* Конструктор с параметрами
*
* @param вектор клиентов
*/
Switch::Switch(std::vector<int>& clients) : Repeater() {
    set_defaults();
    if (clients.size() > cli_cap) throw std::overflow_error("clients vector is too big");
    this->clients = clients;
}

/**
* Конструктор с параметрами
*
* @param адрес
*/
Switch::Switch(std::array<int, 5>& address) : Repeater(address) {
    set_defaults();
}

/**
* Конструктор с параметрами
*
* @param вектор клиентов
* @param адрес
*/
Switch::Switch(std::vector<int>& clients, std::array<int, 5>& address) : Repeater(address) {
    set_defaults();
    if (clients.size() > cli_cap) throw std::overflow_error("clients vector is too big");
    this->clients = clients;
}

/**
* Конструктор с параметрами
*
* @param массив пакетов
* @param вектор клиентов
* @param адрес
*/
Switch::Switch(const double*& packets, std::vector<int>& clients, std::array<int, 5>& address) : Repeater(packets, address) {
    set_defaults();
    if (clients.size() > cli_cap) throw std::overflow_error("clients vector is too big");
    this->clients = clients;
}

/**
* Копирующий коструктор
*
* @param экземпляр Switch
*/
Switch::Switch(Switch& sw) : Repeater(sw.packets, sw.address) {
    this->clients = sw.clients;
};

/**
* Деконструктор
*/
Switch::~Switch() {
    Repeater::~Repeater();
    this->clients = {};
}

/**
 * Оператор сравнивающий количество подключенных к устройствам клиентов
 * 
 * @param первое устройство
 * @param второе устройство
 * @return булево значение сравнения
 */
bool operator>(const Switch& first, const Switch& second) {
    return first.clients.size() > second.clients.size();
}

/**
 * Оператор сравнивающий количество подключенных к устройствам клиентов
 *
 * @param первое устройство
 * @param второе устройство
 * @return булево значение сравнения
 */
bool operator<(const Switch& first, const Switch& second) {
    return first.clients.size() < second.clients.size();
}

/**
* Метод, печатающий информацию об устройстве в консоль
*/
void Switch::print_info() const {
    Repeater::print_info();
    std::cout << "   - Connected devices (" << this->clients.size() << "): ";
    for (int i = 0; i < this->clients.size(); i++)
        std::cout << this->clients[i] << " ";
    std::cout << std::endl;
}

/**
* Метод, возвращающий вектор подключенных клиентов
* 
* @return вектор подключенных клиентов 
*/
std::vector<int> Switch::get_clients() const {
    return this->clients;
}

/**
* Метод принимающий вектор клиентов, подключаемых к устройству
* 
* @param вектор клиентов, подключаемых к устройству
*/
void Switch::set_clients(std::vector<int>& clients) {
    if (clients.size() > cli_cap) throw std::length_error("clients vector is too big");
    this->clients = clients;
}

/**
* Метод принимающий вектор клиентов, подключаемых к устройству
*
* @param вектор клиентов, подключаемых к устройству
*/
int Switch::clients_count() const {
    return this->clients.size();
}

/**
* Публичный метод, сбрасывающий устройство до значений по умолчанию
*/
void Switch::reset() {
    Repeater::reset();
    set_defaults();
}
