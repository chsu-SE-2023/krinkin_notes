#pragma once
#include "gateway.h"
#include <iostream>

/**
* ѕриватный метод, задающий значени€ по умолчанию
*/
void Gateway::set_defaults() {
    this->protocol = "";
}

/**
*  онструктор по умолчанию
*/
Gateway::Gateway() : Switch() {
    set_defaults();
};

/**
*  онструктор с параметрами
*
* @param вектор клиентов
*/
Gateway::Gateway(std::vector<Client>& clients) : Switch(clients) {
    set_defaults();
};

/**
*  онструктор с параметрами
*
* @param MAC-адресс
*/
Gateway::Gateway(MAC_Address address) : Switch(address) {
    set_defaults();
};

/**
*  онструктор с параметрами
*
* @param вектор клиентов
* @param MAC-адресс
*/
Gateway::Gateway(std::vector<Client>& clients, MAC_Address address) : Switch(clients, address) {
    set_defaults();
};

/**
*  онструктор с параметрами
*
* @param массив пакетов
* @param вектор клиентов
* @param MAC-адресс
* @param протокол
*/
Gateway::Gateway(const double*& packets, std::vector<Client>& clients, MAC_Address address, std::string protocol) : Switch(packets, clients, address) {
    set_defaults();
    this->protocol = protocol;
};

/**
*  опирующий коструктор
*
* @param экземпл€р Gateway
*/
Gateway::Gateway(Gateway& copy) : Switch(copy.packets, copy.clients, copy.address) {
    this->protocol = copy.protocol;
};

/**
* ƒеконструктор
*/
Gateway::~Gateway() {
    Switch::~Switch();
    this->protocol = "";
};

/**
* ћетод вовращающий наименование протокола, с которым работает устройство
* 
* @return наименование протокола
*/
std::string Gateway::get_protocol() const {
    return protocol;
};

/**
* ћетод устанавливающий наименование протокола, с которым работает устройство
* 
* @param наименование протокола
*/
void Gateway::set_protocol(std::string protocol) {

    this->protocol = protocol;
};

/**
* ћетод, печатающий информацию об устройстве в консоль
*/
void Gateway::print_info() {
    Switch::print_info();
    std::cout << "Protocol - " << this->protocol << std::endl;
};

/**
* ѕубличный метод, сбрасывающий устройство до значений по умолчанию
*/
void Gateway::reset() {
    Switch::reset();
    set_defaults();
};