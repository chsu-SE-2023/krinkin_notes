#include <iostream>
#include "router.h"

void Router::set_defaults() {
    Gateway::set_defaults();
    this->ssid = "admin";
    this->passwd = "admin";
    this->wpa = false;
}

Router::Router() {
    set_defaults();
}

Router::Router(const Router& copy) {
    this->wpa = copy.wpa;
    this->packets = copy.packets;
    this->clients = copy.clients;
    this->address = copy.address;
    this->ssid = copy.ssid;
    this->passwd = copy.passwd;
}

Router::Router(std::string ssid, std::string passwd) {
    set_defaults();
    this->ssid = ssid;
    this->passwd = passwd;
}

Router::Router(const double*& packets, std::array<int, cli_cap> clients, std::array<int, 5> address, std::string protocol, std::string ssid, std::string passwd) {
    this->set_defaults();
    this->packets = packets;
    this->clients = clients;
    this->address = address;
    this->protocol = protocol;
    this->ssid = ssid;
    this->passwd = passwd;
}

std::string Router::get_ssid() const {
    return this->ssid;
}

bool Router::wpa_enabled() const {
    return wpa;
}

void Router::print_info() const {
    Gateway::print_info();
    std::cout << "   - SSID: ";
    this->ssid.empty() ? std::cout << this->ssid : std::cout << "None";
    std::cout << std::endl;
    std::cout << "   - WPA: ";
    this->wpa ? std::cout << "enabled" : std::cout << "disabled";
    std::cout << std::endl;
}

void Router::set_ssid(std::string ssid) {
    this->ssid = ssid;
}

void Router::set_passwd(std::string passwd) {
    this->passwd = passwd;
}

void Router::set_wpa(bool wpa) {
    this->wpa = wpa;
}
