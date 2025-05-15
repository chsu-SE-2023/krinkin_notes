#include <iostream>
#include "wl_repeater.h"

/**
* ѕриватный метод, задающий значени€ по умолчанию
*/
void WLRepeater::set_defaults() {
    this->ssid = "admin";
    this->passwd = "admin";
}

/**
*  онструктор по умолчанию
*/
WLRepeater::WLRepeater() : Repeater() {
    set_defaults();
}

/**
*  онструктор с параметрами
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
*  онструктор с параметрами
*
* @param MAC-адрес
*/
WLRepeater::WLRepeater(MAC_Address address) : Repeater(address) {
    set_defaults();
}

/**
*  онструктор с параметрами
*
* @param массив пакетов
*/
WLRepeater::WLRepeater(const double*& packets) : Repeater(packets) {
    set_defaults();
}

/**
*  онструктор с параметрами
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
*  опирующий коструктор
*
* @param экземпл€р WLRepeater
*/
WLRepeater::WLRepeater(WLRepeater& copy) : Repeater(copy.packets, copy.address) {
    this->ssid = copy.ssid;
    this->passwd = copy.passwd;
}

/**
* ƒеконструктор
*/
WLRepeater::~WLRepeater() {
    Repeater::~Repeater();
    this->ssid = "";
    this->passwd = "";
}

/**
* ћетод возвращающий SSID сети устройства
* 
* @return SSID сети устройства
*/
std::string WLRepeater::get_ssid() const {
    return this->ssid;
}

/**
* ћетод, печатающий информацию об устройстве в консоль
*/
void WLRepeater::print_info() const {
    /*
    * ћетод печатает информацию об устройстве
    */
    std::cout << "   - SSID: ";
    this->ssid.empty() ? std::cout << this->ssid : std::cout << "None";
    std::cout << std::endl;
}

/**
* ћетод устанавливающий SSID сети устройства
* 
* @param SSID сети устройства
*/
void WLRepeater::set_ssid(std::string ssid) {
    this->ssid = ssid;
}

/**
* ћетод устанавливающий пароль сети устройства
* 
* @param пароль сети устройства
*/
void WLRepeater::set_passwd(std::string passwd) {
    this->passwd = passwd;
}

/**
* ѕубличный метод, сбрасывающий устройство до значений по умолчанию
*/
void WLRepeater::reset() {
    Repeater::reset();
    set_defaults();
}
