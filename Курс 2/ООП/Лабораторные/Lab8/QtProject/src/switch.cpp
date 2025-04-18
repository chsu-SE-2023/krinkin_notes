#include <iostream>
#include "switch.h"

void Switch::set_defaults() {
    this->clients = {};
}

Switch::Switch() : Repeater() {
    set_defaults();
}

Switch::Switch(std::vector<int>& clients) : Repeater() {
    set_defaults();
    if (clients.size() > cli_cap) throw std::overflow_error("clients vector is too big");
    this->clients = clients;
}

Switch::Switch(std::array<int, 5>& address) : Repeater(address) {
    set_defaults();
}

Switch::Switch(std::vector<int>& clients, std::array<int, 5>& address) : Repeater(address) {
    set_defaults();
    if (clients.size() > cli_cap) throw std::overflow_error("clients vector is too big");
    this->clients = clients;
}

Switch::Switch(const double*& packets, std::vector<int>& clients, std::array<int, 5>& address) : Repeater(packets, address) {
    set_defaults();
    if (clients.size() > cli_cap) throw std::overflow_error("clients vector is too big");
    this->clients = clients;
}

Switch::Switch(Switch& sw) : Repeater(sw.packets, sw.address) {
    this->clients = sw.clients;
};

Switch::~Switch() {
    Repeater::~Repeater();
    this->clients = {};
}

bool operator>(const Switch& first, const Switch& second) {
    /*
     * Оператор проверяет больше ли в устройстве на первой полке устройств, чем во второй.
     */
    return first.clients.size() > second.clients.size();
}

// Эта компонентная функция печатает данные из объекта на экран.
void Switch::print_info() const {
    /*
    * Метод печатает информацию об устройстве
    */
    Repeater::print_info();
    std::cout << "   - Connected devices (" << this->clients.size() << "): ";
    for (int i = 0; i < this->clients.size(); i++)
        std::cout << this->clients[i] << " ";
    std::cout << std::endl;
}

std::vector<int> Switch::get_clients() const {
    /*
    * Метод возвращающий массив клиентов, подключенных к устройству
    */
    return this->clients;
}

void Switch::set_clients(std::vector<int>& clients) {
    /*
    * Метод устанавливающий массив клиентов, подключенных к устройству
    */
    if (clients.size() > cli_cap) throw std::length_error("clients vector is too big");
    this->clients = clients;
}

int Switch::clients_count() const {
    /*
    * Метод возвращающий количество клиентов, подключенных к устройству
    */
    return this->clients.size();
}

void Switch::reset() {
    /*
    * Метод сбрасывает все установки устройства к значениям по умолчанию
    */
    Repeater::reset();
    set_defaults();
}
