#include <iostream>
#include "router.h"

/**
* ѕриватный метод, задающий значени€ по умолчанию
*/
void Router::set_defaults() {
    this->wps = false;
}

/**
*  онструктор по умолчанию
*/
Router::Router() : Gateway(), WLRepeater() {
    set_defaults();
}

/**
*  онструктор с параметрами
*
* @param SSID беспроводной сети
* @param пароль беспроводной сети
*/
Router::Router(std::string ssid, std::string passwd) : Gateway(), WLRepeater(ssid, passwd) {
    set_defaults();
}

/**
*  онструктор с параметрами
*
* @param вектор клиентов
*/
Router::Router(std::vector<int>& clients) : Gateway(clients) {
    set_defaults();
}

/**
*  онструктор с параметрами
*
* @param MAC-адрес
*/
Router::Router(std::array<int, 5>& address) : Gateway(address), WLRepeater() {
    set_defaults();
}

/**
*  онструктор с параметрами
*
* @param массив пакетов
*/
Router::Router(const double*& packets) : Router(packets) {
    set_defaults();
}

/**
*  онструктор с параметрами
*
* @param вектор клиентов
* @param MAC-адрес
*/
Router::Router(std::vector<int>& clients, std::array<int, 5>& address) : Gateway(clients, address), WLRepeater() {
    set_defaults();
}

/**
*  онструктор с параметрами
*
* @param массив пакетов
* @param вектор клиентов
* @param MAC-адрес
* @param наименование протокола
* @param SSID беспроводной сети
* @param пароль беспроводной сети
*/
Router::Router(const double*& packets, std::vector<int>& clients, std::array<int, 5> address, std::string protocol, std::string ssid, std::string passwd) : Gateway(packets, clients, address, protocol), WLRepeater(ssid, passwd) {
    set_defaults();
}

/**
*  опирующий коструктор
*
* @param экземпл€р Router
*/
Router::Router(Router& copy) : Gateway(copy.Gateway::packets, copy.clients, copy.Gateway::address, copy.protocol), WLRepeater(copy.ssid, copy.passwd) {
    this->wps = copy.wps;
}

/**
* ƒеконструктор
*/
Router::~Router() {
    Gateway::~Gateway();
    WLRepeater::~WLRepeater();
}

/**
* ћетод, возвращающий хранимый массив пакетов
*
* @return массив пакетов
*/
const double* Router::get_packets() const {
    return Repeater::get_packets();
};

/**
* ћетод, дл€ получени€ пакетов
*
* @param принимаемый массив пакетов
*/
void Router::receive(const double*& packets) {
    Repeater::receive(packets);
};

/**
* ћетод, возвращающий MAC-адрес устройства
*
* @return MAC-адрес
*/
std::array<int, 5> Router::get_address() const {
    return Repeater::get_address();
};

/**
* ћетод возвращающиц активирован ли на устройстве режим WPS подключени€
* 
* @return булевое значение активации режима WPS подключени€
*/
bool Router::is_wps() const {
    return wps;
}

/**
* ћетод, печатающий информацию об устройстве в консоль
*/
void Router::print_info() const {
    std::cout << "   - WPS: ";
    this->wps ? std::cout << "enabled" : std::cout << "disabled";
    std::cout << std::endl;
}

/**
* ѕубличный метод, сбрасывающий устройство до значений по умолчанию
*/
void Router::reset() {
    Gateway::set_defaults();
    WLRepeater::set_defaults();
    set_defaults();
}

/**
* ћетод, устанавливающий MAC-адрес устройства
*
* @param MAC-адрес
*/
void Router::set_address(const std::array<int, 5>& address) {
    Repeater::set_address(address);
}

/**
* ћетод активирующий режим WPS подключени€ на устройстве
*/
void Router::wps_init() {
    this->wps = true;
}

/*
* ћетод подключающий клиента по WPS и отключающий режим WPS
* 
* @param подключаемый клиент
*/
void Router::wps_connect(int client_id) {
    // TODO: Append clients
    // this->clients.assign(client_id);
    this->wps = false;
}
