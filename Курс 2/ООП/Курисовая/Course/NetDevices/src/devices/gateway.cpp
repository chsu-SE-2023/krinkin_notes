#pragma once
#include "gateway.h"
#include <iostream>

/**
* Приватный метод, задающий значения по умолчанию
*/
void Gateway::set_defaults() {
    this->protocol = "raw";
}

/**
* Конструктор по умолчанию
*/
Gateway::Gateway() : Switch() {
    set_defaults();
};

/**
* Конструктор с параметрами
*
* @param массив пакетов
*/
Gateway::Gateway(const unsigned char*& bytes) : Switch(bytes) {
    set_defaults();
}

/**
* Конструктор с параметрами
*
* @param вектор клиентов
*/
Gateway::Gateway(std::vector<Client>& clients) : Switch(clients) {
    set_defaults();
};

/**
* Конструктор с параметрами
*
* @param MAC-адресс
*/
Gateway::Gateway(MAC_Address address) : Switch(address) {
    set_defaults();
};

/**
* Конструктор с параметрами
*
* @param вектор клиентов
* @param MAC-адресс
*/
Gateway::Gateway(std::vector<Client>& clients, MAC_Address address) : Switch(clients, address) {
    set_defaults();
};

/**
* Конструктор с параметрами
*
* @param массив пакетов
* @param вектор клиентов
* @param MAC-адресс
* @param протокол
*/
Gateway::Gateway(const unsigned char*& bytes, std::vector<Client>& clients, MAC_Address address, std::string protocol) : Switch(bytes, clients, address) {
    set_defaults();
    this->protocol = protocol;
};

/**
* Копирующий коструктор
*
* @param экземпляр Gateway
*/
Gateway::Gateway(const Gateway& copy) : Switch(const_cast<const unsigned char*&>(copy.bytes), const_cast<std::vector<Client>&>(copy.clients), copy.address) {
    this->protocol = copy.protocol;
};

/**
* Деконструктор
*/
Gateway::~Gateway() {
    Switch::~Switch();
    this->protocol = "";
};

/**
* Метод, возвращающий информацию об объекте
* в виде текста о его полях
*
* @return текст о полях объекта
*/
std::string Gateway::get_info() {
    return Switch::get_info() + ", protocol: " + protocol;
}

/**
* Метод вовращающий наименование протокола, с которым работает устройство
* 
* @return наименование протокола
*/
std::string Gateway::get_protocol() const {
    return protocol;
};

/**
* Метод устанавливающий наименование протокола, с которым работает устройство
* 
* @param наименование протокола
*/
void Gateway::set_protocol(std::string protocol) {

    this->protocol = protocol;
};

/**
* Публичный метод, сбрасывающий устройство до значений по умолчанию
*/
void Gateway::reset() {
    Switch::reset();
    set_defaults();
};

/**
* Метод, возвращающий имя типа данных
*/
std::string Gateway::type_name() {
    return "Gateway";
}