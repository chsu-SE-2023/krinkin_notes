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
* @param массив байт
*/
WLRepeater::WLRepeater(const unsigned char*& bytes) : Repeater(bytes) {
    set_defaults();
}

/**
* Конструктор с параметрами
*
* @param массив байт
* @param MAC-адрес
* @param SSID беспроводной сети
* @param пароль беспроводной сети
*/
WLRepeater::WLRepeater(const unsigned char*& bytes, MAC_Address address, std::string ssid, std::string passwd) : Repeater(bytes, address) {
    set_defaults();
    this->ssid = ssid;
    this->passwd = passwd;
}

/**
* Копирующий коструктор
*
* @param экземпляр WLRepeater
*/
WLRepeater::WLRepeater(const WLRepeater& copy) : Repeater(const_cast<const unsigned char*&>(copy.bytes), const_cast<MAC_Address&>(copy.address)) {
    set_defaults();
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

/*
* Метод подключающий клиента по WPS и отключающий режим WPS
*
* @param подключаемый клиент
*/
void WLRepeater::connect(Client& client) {
    if (clients.size() == 0) {
        if (client.get_type() == ClientType::Wired)
            this->clients.push_back(client);
        if (client.get_type() == ClientType::Wireless) {
            if (wps) {
                this->clients.push_back(client);
                this->wps = false;
            }
            else throw std::invalid_argument("Device will be in WPS mode to connect wireless client without credentials");
        }
    } else {
        throw std::overflow_error("This device does not support multiple clients");
    }
}

/*
* Метод подключающий клиента к беспроводной сети
*
* @param подключаемый клиент
* @param SSID сети устройства
* @param пароль сети устройства
*/
void WLRepeater::connect(Client& client, std::string ssid, std::string passwd) {
    if (clients.size() == 0) {
        if (this->ssid == ssid && this->passwd == passwd) {
            this->clients.push_back(client);   
        } else throw std::invalid_argument("Wrong credentials provided!");
    } else {
        throw std::overflow_error("This device does not support multiple clients");
    }
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
* Метод возвращающиц активирован ли на устройстве режим WPS подключения
*
* @return булевое значение активации режима WPS подключения
*/
bool WLRepeater::is_wps() const {
    return wps;
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

/**
* Метод активирующий режим WPS подключения на устройстве
*/
void WLRepeater::wps_init() {
    this->wps = true;
}