#include <iostream>
#include "router.h"

void Router::set_defaults() {
    this->wps = false;
}

Router::Router() : Gateway(), WLRepeater() {
    set_defaults();
}

Router::Router(std::string ssid, std::string passwd) : Gateway(), WLRepeater(ssid, passwd) {
    set_defaults();
}

Router::Router(std::vector<int>& clients) : Gateway(clients) {
    set_defaults();
}

Router::Router(std::array<int, 5>& address) : Gateway(address), WLRepeater() {
    set_defaults();
}

Router::Router(std::vector<int>& clients, std::array<int, 5>& address) : Gateway(clients, address), WLRepeater() {
    set_defaults();
}

Router::Router(const double*& packets, std::vector<int>& clients, std::array<int, 5> address, std::string protocol, std::string ssid, std::string passwd) : Gateway(packets, clients, address, protocol), WLRepeater(ssid, passwd) {
    set_defaults();
}

Router::Router(Router& copy) : Gateway(copy.Gateway::packets, copy.clients, copy.Gateway::address, copy.protocol), WLRepeater(copy.ssid, copy.passwd) {
    this->wps = copy.wps;
}

Router::~Router() {
    Gateway::~Gateway();
    WLRepeater::~WLRepeater();
}

const double* Router::get_packets() const {
    /*
    * Метод возвращает указатель на массив пакетов
    */ 
    return Repeater::get_packets();
};

void Router::receive(const double*& packets) {
    /*
    * Метод принимает массив пакетов
    */
    Repeater::receive(packets);
};

std::array<int, 5> Router::get_address() const {
    /*
    * Метод возвращает MAC-адрес устройства
    */
    return Repeater::get_address();
};

bool Router::is_wps() const {
    /*
    * Метод возвращает открыт ли на устройстве режим WPS подключения
    */
    return wps;
}

void Router::print_info() const {
    /*
    * Метод печатает информацию об устройстве
    */
    std::cout << "   - WPS: ";
    this->wps ? std::cout << "enabled" : std::cout << "disabled";
    std::cout << std::endl;
}

void Router::reset() {
    /*
    * Метод сбрасывает все установки устройства к значениям по умолчанию
    */
    Gateway::set_defaults();
    WLRepeater::set_defaults();
    set_defaults();
}

void Router::set_address(const std::array<int, 5>& address) {
    /*
    * Метод устанавливает MAC-адрес для устройства
    */
    Repeater::set_address(address);
}

void Router::wps_init() {
    /*
    * Метод активирует WPS режим подключения на устройстве
    */
    this->wps = true;
}

void Router::wps_connect(int client_id) {
    /*
    * Метод подключающий клиента по WPS и отключающий WPS
    */
    // TODO: Append clients
    // this->clients.assign(client_id);
    this->wps = false;
}
