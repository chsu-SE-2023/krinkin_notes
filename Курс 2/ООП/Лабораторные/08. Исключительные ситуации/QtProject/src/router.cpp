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
    * ����� ���������� ��������� �� ������ �������
    */ 
    return Repeater::get_packets();
};

void Router::receive(const double*& packets) {
    /*
    * ����� ��������� ������ �������
    */
    Repeater::receive(packets);
};

std::array<int, 5> Router::get_address() const {
    /*
    * ����� ���������� MAC-����� ����������
    */
    return Repeater::get_address();
};

bool Router::is_wps() const {
    /*
    * ����� ���������� ������ �� �� ���������� ����� WPS �����������
    */
    return wps;
}

void Router::print_info() const {
    /*
    * ����� �������� ���������� �� ����������
    */
    std::cout << "   - WPS: ";
    this->wps ? std::cout << "enabled" : std::cout << "disabled";
    std::cout << std::endl;
}

void Router::reset() {
    /*
    * ����� ���������� ��� ��������� ���������� � ��������� �� ���������
    */
    Gateway::set_defaults();
    WLRepeater::set_defaults();
    set_defaults();
}

void Router::set_address(const std::array<int, 5>& address) {
    /*
    * ����� ������������� MAC-����� ��� ����������
    */
    Repeater::set_address(address);
}

void Router::wps_init() {
    /*
    * ����� ���������� WPS ����� ����������� �� ����������
    */
    this->wps = true;
}

void Router::wps_connect(int client_id) {
    /*
    * ����� ������������ ������� �� WPS � ����������� WPS
    */
    // TODO: Append clients
    // this->clients.assign(client_id);
    this->wps = false;
}
