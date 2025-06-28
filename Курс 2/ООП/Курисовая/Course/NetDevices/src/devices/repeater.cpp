#include "repeater.h"
#include <iostream>

/**
* Приватный метод, задающий значения по умолчанию
*/
void Repeater::set_defaults() {
    this->bytes = nullptr;
    this->address = MAC_Address();
}

/**
* Конструктор по умолчанию
*/
Repeater::Repeater() {
    set_defaults();
};

/**
* Конструктор с параметрами
* 
* @param MAC-адрес
*/
Repeater::Repeater(MAC_Address address) {
    set_defaults();
    this->address = address;
};

/**
* Конструктор с параметрами
*
* @param массив байт
*/
Repeater::Repeater(const unsigned char*& bytes) {
    set_defaults();
    this->bytes = bytes;
};

/**
* Конструктор с параметрами
*
* @param массив байт
* @param MAC-адрес
*/
Repeater::Repeater(const unsigned char*& bytes, MAC_Address address) {
    set_defaults();
    this->bytes = bytes;
    this->address = address;
}

/**
* Копирующий коструктор
*
* @param экземпляр Repeater
*/
Repeater::Repeater(const Repeater& copy) {
    this->address = copy.address;
    this->bytes = copy.bytes;
};

/**
* Деконструктор
*/
Repeater::~Repeater() {
    if (bytes) delete bytes;
};

/**
* Перезрузка оператора >
* 
* @param ссылка на первый объект
* @param ссылка на первый объект
* @return результат сравнения
*/
bool operator>(const Repeater& first, const Repeater& second) {
    return first.address > second.address;
}

/**
* Перезрузка оператора <
*
* @param ссылка на первый объект
* @param ссылка на первый объект
* @return результат сравнения
*/
bool operator<(const Repeater& first, const Repeater& second) {
    return first.address < second.address;
}

/**
* Перезрузка оператора >=
*
* @param ссылка на первый объект
* @param ссылка на первый объект
* @return результат сравнения
*/
bool operator>=(const Repeater& first, const Repeater& second) {
    return first.address >= second.address;
}

/**
* Перезрузка оператора <=
*
* @param ссылка на первый объект
* @param ссылка на первый объект
* @return результат сравнения
*/
bool operator<=(const Repeater& first, const Repeater& second) {
    return first.address <= second.address;
}

/**
* Перезрузка оператора ==
*
* @param ссылка на первый объект
* @param ссылка на первый объект
* @return результат сравнения
*/
bool operator==(const Repeater& first, const Repeater& second) {
    return first.address == second.address;
}

/**
* Перезрузка оператора !=
*
* @param ссылка на первый объект
* @param ссылка на первый объект
* @return результат сравнения
*/
bool operator!=(const Repeater& first, const Repeater& second) {
    return first.address != second.address;
}

/**
* Метод, возвращающий количество клиентов, подключенных к устройству
*
* @return количество клиентов, подключенных к устройству
*/
int Repeater::clients_count() const {
    return clients.size();
}

/**
* Метод подключающий клиента к устройству
*
* @param подключаемый клиент
*/
void Repeater::connect(Client& client) {
    if (client.get_type() == ClientType::Wired)
        if (clients.size() == 0)
            this->clients.push_back(client);
        else
            throw std::overflow_error("This device does not support multiple clients");
    else
        throw std::invalid_argument("This device does not support wireless connection");
}

/**
* Метод отключающий клиента от устройства
*
* @param отключаемый клиент
*/
void Repeater::disconnect(Client& client) {
    clients.erase(std::find(clients.begin(), clients.end(), client));
}

/**
* Метод, возвращающий хранимый массив пакетов
* 
* @return массив пакетов
*/
const unsigned char* Repeater::get_bytes() const {
    return bytes;
};

/**
* Метод, возвращающий вектор подключенных клиентов
*
* @return вектор подключенных клиентов
*/
std::vector<Client> Repeater::get_clients() {
    return clients;
};

/**
* Метод для получения байт
*
* @param принимаемый массив байт
*/
void Repeater::receive(const unsigned char*& bytes) {
    this->bytes = bytes;
};

/**
* Метод, возвращающий информацию об объекте
* в виде текста о его полях
*
* @return текст о полях объекта
*/
std::string Repeater::get_info() {
    // TODO: печать bytes
    return "address: " + address.as_string() + 
        ", clients: vector<Client> {size: " + std::to_string(clients.size()) + "}";
}

/**
* Метод, возвращающий MAC-адрес устройства
*
* @return MAC-адрес
*/
MAC_Address Repeater::get_address() const {
    return address;
};

/**
* Метод, устанавливающий MAC-адрес устройства
*
* @param MAC-адрес
*/
void Repeater::set_address(MAC_Address address) {
    this->address = address;
};

/**
* Публичный метод, сбрасывающий устройство до значений по умолчанию
*/
void Repeater::reset() {
    set_defaults();
}

/**
* Метод, возвращающий имя типа данных
*/
std::string Repeater::type_name() {
    return "Repeater";
}
