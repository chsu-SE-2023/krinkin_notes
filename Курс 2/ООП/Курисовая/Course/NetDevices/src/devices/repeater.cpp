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
    // HACK: А нужно ли вообще удалять внешние данные?
    // if (packets) delete packets;
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
* Метод, возвращающий хранимый массив пакетов
* 
* @return массив пакетов
*/
const unsigned char* Repeater::get_bytes() const {
    return bytes;
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
    return "address: " + address.as_string();
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
