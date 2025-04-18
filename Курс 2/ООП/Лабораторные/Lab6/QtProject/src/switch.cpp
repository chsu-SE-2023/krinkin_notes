#include <iostream>
#include "switch.h"

void Switch::set_defaults() {
    Repeater::set_defaults();
    this->clients = {};
}

Switch::Switch() {
    set_defaults();
}

Switch::Switch(std::array<int, cli_cap> clients) {
    set_defaults();
    this->set_clients(clients);
}

Switch::Switch(std::array<int, 5>& address) {
    set_defaults();
    this->address = address;
}

Switch::Switch(std::array<int, cli_cap>& clients, std::array<int, 5>& address) {
    set_defaults();
    this->clients = clients;
    this->address = address;
}

Switch::Switch(const double*& packets, std::array<int, cli_cap>& clients, std::array<int, 5>& address) {
    this->set_defaults();
    this->packets = packets;
    this->clients = clients;
    this->address = address;
}

Switch::Switch(const Switch& sw) {
    this->packets = sw.packets;
    this->clients = sw.clients;
    this->address = sw.address;
};

Switch::~Switch() {
    Repeater::~Repeater();
    this->clients = {};
}

bool operator>(Switch& first, Switch& second) {
    /*
     * Оператор проверяет больше ли в устройстве на первой полке устройств, чем во второй.
     */
    return first.clients.size() > second.clients.size();
}

// Эта компонентная функция печатает данные из объекта на экран.
void Switch::print_info() const {
    Repeater::print_info();
    std::cout << "   - Connected devices (" << this->clients.size() << "): ";
    for (int i = 0; i < this->clients.size(); i++)
        std::cout << this->clients[i] << " ";
    std::cout << std::endl;
}

std::array<int, Switch::cli_cap> Switch::get_clients() const {
    return this->clients;
}

void Switch::set_clients(std::array<int, cli_cap>& clients) {
    this->clients = clients;
}

int Switch::clients_count() const {
    return this->clients.size();
}
