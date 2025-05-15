#pragma once
#include "gateway.h"
#include <iostream>

/**
* ��������� �����, �������� �������� �� ���������
*/
void Gateway::set_defaults() {
    this->protocol = "";
}

/**
* ����������� �� ���������
*/
Gateway::Gateway() : Switch() {
    set_defaults();
};

/**
* ����������� � �����������
*
* @param ������ ��������
*/
Gateway::Gateway(std::vector<Client>& clients) : Switch(clients) {
    set_defaults();
};

/**
* ����������� � �����������
*
* @param MAC-������
*/
Gateway::Gateway(MAC_Address address) : Switch(address) {
    set_defaults();
};

/**
* ����������� � �����������
*
* @param ������ ��������
* @param MAC-������
*/
Gateway::Gateway(std::vector<Client>& clients, MAC_Address address) : Switch(clients, address) {
    set_defaults();
};

/**
* ����������� � �����������
*
* @param ������ �������
* @param ������ ��������
* @param MAC-������
* @param ��������
*/
Gateway::Gateway(const double*& packets, std::vector<Client>& clients, MAC_Address address, std::string protocol) : Switch(packets, clients, address) {
    set_defaults();
    this->protocol = protocol;
};

/**
* ���������� ����������
*
* @param ��������� Gateway
*/
Gateway::Gateway(Gateway& copy) : Switch(copy.packets, copy.clients, copy.address) {
    this->protocol = copy.protocol;
};

/**
* �������������
*/
Gateway::~Gateway() {
    Switch::~Switch();
    this->protocol = "";
};

/**
* ����� ����������� ������������ ���������, � ������� �������� ����������
* 
* @return ������������ ���������
*/
std::string Gateway::get_protocol() const {
    return protocol;
};

/**
* ����� ��������������� ������������ ���������, � ������� �������� ����������
* 
* @param ������������ ���������
*/
void Gateway::set_protocol(std::string protocol) {

    this->protocol = protocol;
};

/**
* �����, ���������� ���������� �� ���������� � �������
*/
void Gateway::print_info() {
    Switch::print_info();
    std::cout << "Protocol - " << this->protocol << std::endl;
};

/**
* ��������� �����, ������������ ���������� �� �������� �� ���������
*/
void Gateway::reset() {
    Switch::reset();
    set_defaults();
};