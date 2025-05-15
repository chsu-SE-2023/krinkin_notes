#include <iostream>
#include "wl_repeater.h"

/**
* ��������� �����, �������� �������� �� ���������
*/
void WLRepeater::set_defaults() {
    this->ssid = "admin";
    this->passwd = "admin";
}

/**
* ����������� �� ���������
*/
WLRepeater::WLRepeater() : Repeater() {
    set_defaults();
}

/**
* ����������� � �����������
*
* @param SSID ������������ ����
* @param ������ ������������ ����
*/
WLRepeater::WLRepeater(std::string ssid, std::string passwd) : Repeater() {
    set_defaults();
    this->ssid = ssid;
    this->passwd = passwd;
}

/**
* ����������� � �����������
*
* @param MAC-�����
*/
WLRepeater::WLRepeater(MAC_Address address) : Repeater(address) {
    set_defaults();
}

/**
* ����������� � �����������
*
* @param ������ �������
*/
WLRepeater::WLRepeater(const double*& packets) : Repeater(packets) {
    set_defaults();
}

/**
* ����������� � �����������
*
* @param ������ �������
* @param MAC-�����
* @param SSID ������������ ����
* @param ������ ������������ ����
*/
WLRepeater::WLRepeater(const double*& packets, MAC_Address address, std::string ssid, std::string passwd) : Repeater(packets, address) {
    set_defaults();
    this->ssid = ssid;
    this->passwd = passwd;
}

/**
* ���������� ����������
*
* @param ��������� WLRepeater
*/
WLRepeater::WLRepeater(WLRepeater& copy) : Repeater(copy.packets, copy.address) {
    this->ssid = copy.ssid;
    this->passwd = copy.passwd;
}

/**
* �������������
*/
WLRepeater::~WLRepeater() {
    Repeater::~Repeater();
    this->ssid = "";
    this->passwd = "";
}

/**
* ����� ������������ SSID ���� ����������
* 
* @return SSID ���� ����������
*/
std::string WLRepeater::get_ssid() const {
    return this->ssid;
}

/**
* �����, ���������� ���������� �� ���������� � �������
*/
void WLRepeater::print_info() const {
    /*
    * ����� �������� ���������� �� ����������
    */
    std::cout << "   - SSID: ";
    this->ssid.empty() ? std::cout << this->ssid : std::cout << "None";
    std::cout << std::endl;
}

/**
* ����� ��������������� SSID ���� ����������
* 
* @param SSID ���� ����������
*/
void WLRepeater::set_ssid(std::string ssid) {
    this->ssid = ssid;
}

/**
* ����� ��������������� ������ ���� ����������
* 
* @param ������ ���� ����������
*/
void WLRepeater::set_passwd(std::string passwd) {
    this->passwd = passwd;
}

/**
* ��������� �����, ������������ ���������� �� �������� �� ���������
*/
void WLRepeater::reset() {
    Repeater::reset();
    set_defaults();
}
