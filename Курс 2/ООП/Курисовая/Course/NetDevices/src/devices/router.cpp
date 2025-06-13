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
Router::Router(const unsigned char*& bytes) : Gateway(bytes) {
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
Router::Router(const unsigned char*& bytes, std::vector<Client>& clients, MAC_Address address, std::string protocol, std::string ssid, std::string passwd) : Gateway(bytes, clients, address, protocol), WLRepeater(ssid, passwd) {
    set_defaults();
}

/**
* Копирующий коструктор
*
* @param экземпляр Router
*/
Router::Router(const Router& copy) : Gateway(const_cast<const unsigned char*&>(copy.Gateway::bytes), const_cast<std::vector<Client>&>(copy.clients), copy.Gateway::address, copy.protocol), WLRepeater(copy.ssid, copy.passwd) {
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
* Метод, возвращающий хранимый массив пакетов
*
* @return массив пакетов
*/
const unsigned char* Router::get_bytes() const {
    return Repeater::get_bytes();
};

/**
* Метод, для получения пакетов
*
* @param принимаемый массив пакетов
*/
void Router::receive(const unsigned char*& bytes) {
    Repeater::receive(bytes);
};

/**
* Метод, возвращающий MAC-адрес устройства
*
* @return MAC-адрес
*/
MAC_Address Router::get_address() const {
    return Repeater::get_address();
};

/**
* Метод, возвращающий информацию об объекте
* в виде текста о его полях
*
* @return текст о полях объекта
*/
std::string Router::get_info() {
    return Gateway::get_info() + WLRepeater::get_info() + ", wps: " + std::to_string(wps);
}

/**
* Метод возвращающиц активирован ли на устройстве режим WPS подключения
* 
* @return булевое значение активации режима WPS подключения
*/
bool Router::is_wps() const {
    return wps;
}

/**
* Метод, печатающий информацию об устройстве в консоль
*/
void Router::print_info() const {
    std::cout << "   - WPS: ";
    this->wps ? std::cout << "enabled" : std::cout << "disabled";
    std::cout << std::endl;
}

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
void Router::set_address(MAC_Address address) {
    Repeater::set_address(address);
}

/**
* Метод активирующий режим WPS подключения на устройстве
*/
void Router::wps_init() {
    this->wps = true;
}

/*
* Метод подключающий клиента по WPS и отключающий режим WPS
* 
* @param подключаемый клиент
*/
void Router::connect(Client client) {
    if (client.get_type() == WIRED)
        this->clients.push_back(client);
    if (client.get_type() == WIRELESS) {
        if (wps) {
            this->clients.push_back(client);
            this->wps = false;
        }
        else throw std::invalid_argument("Device will be in WPS mode to connect wireless client without credentials");
    }
}

/*
* Метод подключающий клиента к беспроводной сети
*
* @param подключаемый клиент
* @param SSID сети устройства
* @param пароль сети устройства
*/
void Router::connect(Client client, std::string ssid, std::string passwd) {
    if (this->ssid == ssid && this->passwd == passwd)
        this->clients.push_back(client);
    else throw std::invalid_argument("Wrong credentials provided!");
}
