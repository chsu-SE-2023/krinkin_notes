#include <iostream>
#include "router.h"

/**
* Приватный метод, задающий значения по умолчанию
*/
void Router::set_defaults() {
    this->wps = false;
}

/**
* Конструктор по умолчанию
*/
Router::Router() : Gateway(), WLRepeater() {
    set_defaults();
}

/**
* Конструктор с параметрами
*
* @param SSID беспроводной сети
* @param пароль беспроводной сети
*/
Router::Router(std::string ssid, std::string passwd) : Gateway(), WLRepeater(ssid, passwd) {
    set_defaults();
}

/**
* Конструктор с параметрами
*
* @param вектор клиентов
*/
Router::Router(std::vector<Client>& clients) : Gateway(clients) {
    set_defaults();
}

/**
* Конструктор с параметрами
*
* @param MAC-адрес
*/
Router::Router(MAC_Address address) : Gateway(address), WLRepeater() {
    set_defaults();
}

/**
* Конструктор с параметрами
*
* @param массив пакетов
*/
Router::Router(std::vector<unsigned char>& bytes) : Gateway(bytes) {
    set_defaults();
}

/**
* Конструктор с параметрами
*
* @param вектор клиентов
* @param MAC-адрес
*/
Router::Router(std::vector<Client>& clients, MAC_Address address) : Gateway(clients, address), WLRepeater() {
    set_defaults();
}

/**
* Конструктор с параметрами
*
* @param массив пакетов
* @param вектор клиентов
* @param MAC-адрес
* @param наименование протокола
* @param SSID беспроводной сети
* @param пароль беспроводной сети
*/
Router::Router(std::vector<unsigned char>& bytes, std::vector<Client>& clients, MAC_Address address, std::string protocol, std::string ssid, std::string passwd) : Gateway(bytes, clients, address, protocol), WLRepeater(ssid, passwd) {
    set_defaults();
}

/**
* Копирующий коструктор
*
* @param экземпляр Router
*/
Router::Router(const Router& copy) : Gateway(const_cast<std::vector<unsigned char>&>(copy.Gateway::bytes), const_cast<std::vector<Client>&>(copy.Gateway::clients), copy.Gateway::address, copy.protocol), WLRepeater(copy.ssid, copy.passwd) {
    this->wps = copy.wps;
}

/**
* Деконструктор
*/
Router::~Router() {
    Gateway::~Gateway();
    WLRepeater::~WLRepeater();
}

/**
* Метод, возвращающий количество клиентов, подключенных к устройству
*
* @return количество клиентов, подключенных к устройству
*/
int Router::clients_count() const {
    return Gateway::clients_count();
}

/*
* Метод подключающий клиента по WPS и отключающий режим WPS
*
* @param подключаемый клиент
*/
void Router::connect(Client& client) {
    if (Gateway::clients.size() <= cli_cap) {
        if (client.get_type() == ClientType::Wired)
            this->Gateway::clients.push_back(client);
        if (client.get_type() == ClientType::Wireless) {
            if (wps) {
                this->Gateway::clients.push_back(client);
                this->wps = false;
            }
            else throw std::invalid_argument("Device will be in WPS mode to connect wireless client without credentials");
        }
    }
    else {
        throw std::overflow_error("There is not enouth capacity for new client");
    }
}

/*
* Метод подключающий клиента к беспроводной сети
*
* @param подключаемый клиент
* @param SSID сети устройства
* @param пароль сети устройства
*/
void Router::connect(Client& client, std::string ssid, std::string passwd) {
    if (Gateway::clients.size() <= cli_cap) {
        if (this->ssid == ssid && this->passwd == passwd)
            this->Gateway::clients.push_back(client);
        else throw std::invalid_argument("Wrong credentials provided!");
    }
    else {
        throw std::overflow_error("There is not enouth capacity for new client");
    }
}

/**
* Метод отключающий клиента от устройства
*
* @param отключаемый клиент
*/
void Router::disconnect(Client& client) {
    Gateway::disconnect(client);
}

/**
* Метод, возвращающий MAC-адрес устройства
*
* @return MAC-адрес
*/
MAC_Address Router::get_address() const {
    return Repeater::get_address();
};

/**
* Метод, возвращающий хранимый массив пакетов
*
* @return массив пакетов
*/
std::vector<unsigned char> Router::get_bytes() const {
    return Repeater::get_bytes();
};

/**
* Метод, возвращающий количество хранимых байт
*
* @return количество хранимых байт
*/
int Router::package_size() const {
    return Gateway::bytes.size();
}

/**
* Метод, возвращающий вектор подключенных клиентов
*
* @return вектор подключенных клиентов
*/
std::vector<Client> Router::get_clients() {
    return Gateway::clients;
}

/**
* Метод, возвращающий информацию об объекте
* в виде текста о его полях
*
* @return текст о полях объекта
*/
std::string Router::get_info() {
    return Gateway::get_info() + ", ssid: " + ssid + ", passwd: " + passwd + ", wps: " + std::to_string(wps);
}

/**
* Метод, для получения пакетов
*
* @param принимаемый массив пакетов
*/
void Router::receive(std::vector<unsigned char>& bytes) {
    Repeater::receive(bytes);
};

/**
* Публичный метод, сбрасывающий устройство до значений по умолчанию
*/
void Router::reset() {
    Gateway::set_defaults();
    WLRepeater::set_defaults();
    set_defaults();
}

/**
* Метод, устанавливающий MAC-адрес устройства
*
* @param MAC-адрес
*/
void Router::set_address(const MAC_Address& address) {
    Repeater::set_address(address);
}

/**
* Метод, возвращающий имя типа данных
*/
std::string Router::type_name() {
    return "Router";
}
