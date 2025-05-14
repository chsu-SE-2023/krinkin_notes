#include <iostream>
#include "wl_repeater.h"

void WLRepeater::set_defaults() {
    this->ssid = "admin";
    this->passwd = "admin";
}

WLRepeater::WLRepeater() : Repeater() {
    set_defaults();
}

WLRepeater::WLRepeater(std::string ssid, std::string passwd) : Repeater() {
    set_defaults();
    this->ssid = ssid;
    this->passwd = passwd;
}

WLRepeater::WLRepeater(std::array<int, 5> address) : Repeater(address) {
    set_defaults();
}

WLRepeater::WLRepeater(const double*& packets) : Repeater(packets) {
    set_defaults();
}

WLRepeater::WLRepeater(const double*& packets, std::array<int, 5> address, std::string ssid, std::string passwd) : Repeater(packets, address) {
    set_defaults();
    this->ssid = ssid;
    this->passwd = passwd;
}

WLRepeater::WLRepeater(WLRepeater& copy) : Repeater(copy.packets, copy.address) {
    this->ssid = copy.ssid;
    this->passwd = copy.passwd;
}

WLRepeater::~WLRepeater() {
    Repeater::~Repeater();
    this->ssid = "";
    this->passwd = "";
}

std::string WLRepeater::get_ssid() const {
    /*
    * ����� ������������ SSID ���� ����������
    */
    return this->ssid;
}

void WLRepeater::print_info() const {
    /*
    * ����� �������� ���������� �� ����������
    */
    std::cout << "   - SSID: ";
    this->ssid.empty() ? std::cout << this->ssid : std::cout << "None";
    std::cout << std::endl;
}

void WLRepeater::set_ssid(std::string ssid) {
    /*
    * ����� ��������������� SSID ���� ����������
    */
    this->ssid = ssid;
}

void WLRepeater::set_passwd(std::string passwd) {
    /*
    * ����� ��������������� ������ ���� ����������
    */
    this->passwd = passwd;
}

void WLRepeater::reset() {
    /*
    * ����� ���������� ��� ��������� ���������� � ��������� �� ���������
    */
    Repeater::reset();
    set_defaults();
}
