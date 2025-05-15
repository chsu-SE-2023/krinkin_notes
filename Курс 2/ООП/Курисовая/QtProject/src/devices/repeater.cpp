#include "repeater.h"
#include <iostream>
#include <vector>

/**
* Приватный метод, задающий значения по умолчанию
*/
void Repeater::set_defaults() {
    this->packets = nullptr;
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
* @param массив пакетов
*/
Repeater::Repeater(const double*& packets) {
    set_defaults();
    this->packets = packets;
};

/**
* Конструктор с параметрами
*
* @param массив пакетов
* @param MAC-адрес
*/
Repeater::Repeater(const double*& packets, MAC_Address address) {
    set_defaults();
    this->packets = packets;
    this->address = address;
}

/**
* Копирующий коструктор
*
* @param экземпляр Repeater
*/
Repeater::Repeater(Repeater& copy) {
    this->address = copy.address;
    this->packets = copy.packets;
};

/**
* Деконструктор
*/
Repeater::~Repeater() {
    // А нужно ли вообще удалять внешние данные?
    /*if (packets != nullptr)
        delete packets;*/
};

/**
* Метод, возвращающий хранимый массив пакетов
* 
* @return массив пакетов
*/
const double* Repeater::get_packets() const {
    return packets;
};

/**
* Метод, для получения пакетов
*
* @param принимаемый массив пакетов
*/
void Repeater::receive(const double*& packets) {
    this->packets = packets;
};

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
* Метод, печатающий информацию об устройстве в консоль
*/
void Repeater::print_info() {
    std::cout << "Device info: " << std::endl;
    std::cout << "   - MAC Address: " << address.as_string() << " " << std::endl;
};

/**
* Публичный метод, сбрасывающий устройство до значений по умолчанию
*/
void Repeater::reset() {
    set_defaults();
}
