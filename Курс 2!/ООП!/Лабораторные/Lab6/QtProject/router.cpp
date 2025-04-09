#include <iostream>
#include "router.h"

Router::Router() {
    set_defaults();
}

Router::Router(const Switch& sw) {
    this->packets = sw.packets;
    this->connected = sw.connected;
    this->set_clients(sw.clients);
    this->set_address(sw.address);
}

Router::Router(const char* ssid, const char* passwd) {
    set_defaults();
    this->ssid = new char[strlen(ssid) + 1];
    strcpy(this->ssid, ssid);
    this->passwd = new char[strlen(passwd) + 1];
    strcpy(this->passwd, passwd);
}

Router::Router(const double*& packets, const int* clients, int count, const int* address, const char* ssid, const char* passwd) {
    this->set_defaults();
    this->connected = count;
    this->packets = packets;
    this->set_clients(clients);
    this->set_address(address);
    this->ssid = new char[strlen(ssid) + 1];
    strcpy(this->ssid, ssid);
    this->passwd = new char[strlen(passwd) + 1];
    strcpy(this->passwd, passwd);
}

char* Router::get_ssid() const {
    return this->ssid;
}

bool Router::wpa_enabled() const {
    return wpa;
}

void Router::print_info() const {
    std::cout << "  Router info: " << std::endl;
    std::cout << "   - Clients capacity: " << this->cli_cap << std::endl;
    std::cout << "   - Connected devices (" << this->connected << "): ";
    for (int i = 0; i < this->connected; i++)
        std::cout << this->clients[i] << " ";
    std::cout << std::endl;
    std::cout << "   - MAC Address: ";
    for (int i = 0; i < 5; i++)
        std::cout << this->address[i] << ":";
    std::cout << "\b" << " " << std::endl;
    std::cout << "   - SSID: ";
    this->ssid ? std::cout << this->ssid : std::cout << "None";
    std::cout << std::endl;
    std::cout << "   - WPA: ";
    this->wpa ? std::cout << "enabled" : std::cout << "disabled";
    std::cout << std::endl;
}

void Router::set_ssid(char* ssid) {
    this->ssid = new char[strlen(ssid) + 1];
    strcpy(this->ssid, ssid);
}

void Router::set_passwd(char* passwd) {
    this->passwd = new char[strlen(passwd) + 1];
    strcpy(this->passwd, passwd);
}

void Router::set_wpa(bool wpa) {
    this->wpa = wpa;
}

void Router::reset() {
    this->set_defaults();
}

void Router::set_defaults() {
    this->connected = 0;
    this->packets = nullptr;
    this->clients = new int[this->cli_cap]();
    this->address = new int[5] {0, 0, 0, 0, 0};
    this->ssid = new char[5];
    strcpy(this->ssid, "admin");
    this->passwd = new char[5];
    strcpy(this->passwd, "admin");
    this->wpa = false;
}
