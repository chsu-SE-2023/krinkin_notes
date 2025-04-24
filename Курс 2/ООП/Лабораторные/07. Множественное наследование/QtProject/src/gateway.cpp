#pragma once
#include "gateway.h"
#include <iostream>

void Gateway::set_defaults() {
    this->protocol = "";
}

Gateway::Gateway() : Switch() {
    set_defaults();
};

Gateway::Gateway(std::array<int, cli_cap>& clients) : Switch(clients) {
    set_defaults();
};

Gateway::Gateway(std::array<int, 5> address) : Switch(address) {
    set_defaults();
};

Gateway::Gateway(std::array<int, cli_cap>& clients, std::array<int, 5> address) : Switch(clients, address) {
    set_defaults();
};

Gateway::Gateway(const double*& packets, std::array<int, cli_cap>& clients, std::array<int, 5> address, std::string protocol) : Switch(packets, clients, address) {
    set_defaults();
    this->protocol = protocol;
};

Gateway::Gateway(Gateway& copy) : Switch(copy.packets, copy.clients, copy.address) {
    this->protocol = copy.protocol;
};

Gateway::~Gateway() {
    Switch::~Switch();
    this->protocol = "";
};

std::string Gateway::get_protocol() const {
    /*
    * ����� ��������� ������������ ���������, � ������� �������� ����������
    */
    return protocol;
};

void Gateway::set_protocol(std::string protocol) {
    /*
    * ����� ������������� ������������ ���������, � ������� �������� ����������
    */
    this->protocol = protocol;
};

void Gateway::print_info() const {
    /*
    * ����� �������� ���������� �� ����������
    */
    Switch::print_info();
    std::cout << "Protocol - " << this->protocol << std::endl;
};

void Gateway::reset() {
    /*
    * ����� ���������� ��� ��������� ���������� � ��������� �� ���������
    */

    Switch::reset();
    set_defaults();
};