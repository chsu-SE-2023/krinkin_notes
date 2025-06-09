#include <iostream>
#include "wl_repeater.h"

/**
* Приватный метод, задающий значения по умолчанию
*/
void WLRepeater::set_defaults() {
    this->ssid = "admin";
    this->passwd = "admin";
}

/**
* Конструктор по умолчанию
*/
WLRepeater::WLRepeater() : Repeater() {
    set_defaults();
}

/**
* Конструктор с параметрами
*
* @param SSID беспроводной сети
* @param пароль беспроводной сети
*/
WLRepeater::WLRepeater(std::string ssid, std::string passwd) : Repeater() {
    set_defaults();
    this->ssid = ssid;
    this->passwd = passwd;
}

/**
* Конструктор с параметрами
*
* @param MAC-адрес
*/
WLRepeater::WLRepeater(MAC_Address address) : Repeater(address) {
    set_defaults();
}

/**
* Конструктор с параметрами
*
* @param массив пакетов
*/
WLRepeater::WLRepeater(const double*& packets) : Repeater(packets) {
    set_defaults();
}

/**
* Конструктор с параметрами
*
* @param массив пакетов
* @param MAC-адрес
* @param SSID беспроводной сети
* @param пароль беспроводной сети
*/
WLRepeater::WLRepeater(const double*& packets, MAC_Address address, std::string ssid, std::string passwd) : Repeater(packets, address) {
    set_defaults();
    this->ssid = ssid;
    this->passwd = passwd;
}

/**
* Копирующий коструктор
*
* @param экземпляр WLRepeater
*/
WLRepeater::WLRepeater(const WLRepeater& copy) : Repeater(const_cast<const double*&>(copy.packets), const_cast<MAC_Address&>(copy.address)) {
    this->ssid = copy.ssid;
    this->passwd = copy.passwd;
}

/**
* Деконструктор
*/
WLRepeater::~WLRepeater() {
    Repeater::~Repeater();
    this->ssid = "";
    this->passwd = "";
}

/**
* Метод, возвращающий информацию об объекте
* в виде текста о его полях
*
* @return текст о полях объекта
*/
std::string WLRepeater::get_info() {
    return Repeater::get_info() + ", ssid: " + ssid + ", passwd: " + passwd;
}

/**
* Метод возвращающий SSID сети устройства
* 
* @return SSID сети устройства
*/
std::string WLRepeater::get_ssid() const {
    return this->ssid;
}

/**
* Метод, печатающий информацию об устройстве в консоль
*/
void WLRepeater::print_info() const {
    /*
    * Метод печатает информацию об устройстве
    */
    std::cout << "   - SSID: ";
    this->ssid.empty() ? std::cout << this->ssid : std::cout << "None";
    std::cout << std::endl;
}

/**
* Метод устанавливающий SSID сети устройства
* 
* @param SSID сети устройства
*/
void WLRepeater::set_ssid(std::string ssid) {
    this->ssid = ssid;
}

/**
* Метод устанавливающий пароль сети устройства
* 
* @param пароль сети устройства
*/
void WLRepeater::set_passwd(std::string passwd) {
    this->passwd = passwd;
}

/**
* Публичный метод, сбрасывающий устройство до значений по умолчанию
*/
void WLRepeater::reset() {
    Repeater::reset();
    set_defaults();
}
