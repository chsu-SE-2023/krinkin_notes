#include <iostream>
#include "switch.h"

int Switch::cli_cap = 32;

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
* @param массив байт
*/
Switch::Switch(const unsigned char*& bytes) : Repeater(bytes) {
    set_defaults();
}

/**
* Конструктор с параметрами
*
* @param вектор клиентов
*/
Switch::Switch(std::vector<Client>& clients) : Repeater() {
    set_defaults();
    if (clients.size() > cli_cap) throw std::overflow_error("clients vector is too big");
    this->clients = clients;
}

/**
* Конструктор с параметрами
*
* @param адрес
*/
Switch::Switch(MAC_Address address) : Repeater(address) {
    set_defaults();
}

/**
* Конструктор с параметрами
*
* @param вектор клиентов
* @param адрес
*/
Switch::Switch(std::vector<Client>& clients, MAC_Address address) : Repeater(address) {
    set_defaults();
    if (clients.size() > cli_cap) throw std::overflow_error("clients vector is too big");
    this->clients = clients;
}

/**
* Конструктор с параметрами
*
* @param массив байт
* @param вектор клиентов
* @param адрес
*/
Switch::Switch(const unsigned char*& bytes, std::vector<Client>& clients, MAC_Address address) : Repeater(bytes, address) {
    set_defaults();
    if (clients.size() > cli_cap) throw std::overflow_error("clients vector is too big");
    this->clients = clients;
}

/**
* Копирующий коструктор
*
* @param экземпляр Switch
*/
Switch::Switch(const Switch& sw) : Repeater(const_cast<const unsigned char*&>(sw.bytes), const_cast<MAC_Address&>(sw.address)) {
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
* Перезрузка оператора >
*
* @param ссылка на первый объект
* @param ссылка на первый объект
* @return результат сравнения
*/
bool operator>(const Switch& first, const Switch& second) {
    return first.clients.size() > first.clients.size();
}

/**
* Перезрузка оператора <
*
* @param ссылка на первый объект
* @param ссылка на первый объект
* @return результат сравнения
*/
bool operator<(const Switch& first, const Switch& second) {
    return first.clients.size() < first.clients.size();
}

/**
* Перезрузка оператора >=
*
* @param ссылка на первый объект
* @param ссылка на первый объект
* @return результат сравнения
*/
bool operator>=(const Switch& first, const Switch& second) {
    return first.clients.size() >= first.clients.size();
}

/**
* Перезрузка оператора <=
*
* @param ссылка на первый объект
* @param ссылка на первый объект
* @return результат сравнения
*/
bool operator<=(const Switch& first, const Switch& second) {
    return first.clients.size() <= first.clients.size();
}

/**
* Перезрузка оператора ==
*
* @param ссылка на первый объект
* @param ссылка на первый объект
* @return результат сравнения
*/
bool operator==(const Switch& first, const Switch& second) {
    return first.clients.size() == first.clients.size();
}

/**
* Перезрузка оператора !=
*
* @param ссылка на первый объект
* @param ссылка на первый объект
* @return результат сравнения
*/
bool operator!=(const Switch& first, const Switch& second) {
    return first.clients.size() != first.clients.size();
}

/**
* Метод, возвращающий вместимость устройства
*
* @return вместимость устройства
*/
int Switch::get_capacity() {
    return Switch::cli_cap;
}

/**
* Метод, возвращающий вектор подключенных клиентов
* 
* @return вектор подключенных клиентов 
*/
std::vector<Client> Switch::get_clients() const {
    return this->clients;
}

/**
* Метод, возвращающий информацию об объекте
* в виде текста о его полях
*
* @return текст о полях объекта
*/
std::string Switch::get_info() {
    return Repeater::get_info() + ", cli_cap: " + std::to_string(cli_cap);
}
/**
* Статический метод задающий вместительность устройства
*
* @param вместительность устройства
*/
void Switch::set_capacity(int value) {
    cli_cap = value;
}

/**
* Метод принимающий вектор клиентов, подключаемых к устройству
* 
* @param вектор клиентов, подключаемых к устройству
*/
void Switch::set_clients(std::vector<Client>& clients) {
    if (clients.size() > cli_cap) throw std::length_error("clients vector is too big");
    this->clients = clients;
}

/**
* Метод, возвращающий количество клиентов, подключенных к устройству
*
* @return количество клиентов, подключенных к устройству
*/
int Switch::clients_count() const {
    return this->clients.size();
}

/**
* Метод подключающий клиента к устройству 
*
* @param подключаемый клиент
*/
void Switch::connect(Client& client) {
    if (clients.size() <= cli_cap) {
        if (client.get_type() == ClientType::Wired)
            this->clients.push_back(client);
        else
            throw std::invalid_argument("This device does not support wireless connection");
    }
    else {
        throw std::overflow_error("There is not enouth capacity for new client");
    }
};

/**
* Публичный метод, сбрасывающий устройство до значений по умолчанию
*/
void Switch::reset() {
    Repeater::reset();
    set_defaults();
}

/**
* Метод, возвращающий имя типа данных
*/
std::string Switch::type_name() {
    return "Switch";
}