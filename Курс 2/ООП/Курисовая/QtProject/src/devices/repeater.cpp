#include "repeater.h"
#include <iostream>
#include <vector>

/**
* ��������� �����, �������� �������� �� ���������
*/
void Repeater::set_defaults() {
    this->packets = nullptr;
    this->address = MAC_Address();
}

/**
* ����������� �� ���������
*/
Repeater::Repeater() {
    set_defaults();
};

/**
* ����������� � �����������
* 
* @param MAC-�����
*/
Repeater::Repeater(MAC_Address address) {
    set_defaults();
    this->address = address;
};

/**
* ����������� � �����������
*
* @param ������ �������
*/
Repeater::Repeater(const double*& packets) {
    set_defaults();
    this->packets = packets;
};

/**
* ����������� � �����������
*
* @param ������ �������
* @param MAC-�����
*/
Repeater::Repeater(const double*& packets, MAC_Address address) {
    set_defaults();
    this->packets = packets;
    this->address = address;
}

/**
* ���������� ����������
*
* @param ��������� Repeater
*/
Repeater::Repeater(Repeater& copy) {
    this->address = copy.address;
    this->packets = copy.packets;
};

/**
* �������������
*/
Repeater::~Repeater() {
    // � ����� �� ������ ������� ������� ������?
    /*if (packets != nullptr)
        delete packets;*/
};

/**
* �����, ������������ �������� ������ �������
* 
* @return ������ �������
*/
const double* Repeater::get_packets() const {
    return packets;
};

/**
* �����, ��� ��������� �������
*
* @param ����������� ������ �������
*/
void Repeater::receive(const double*& packets) {
    this->packets = packets;
};

/**
* �����, ������������ MAC-����� ����������
*
* @return MAC-�����
*/
MAC_Address Repeater::get_address() const {
    return address;
};

/**
* �����, ��������������� MAC-����� ����������
*
* @param MAC-�����
*/
void Repeater::set_address(MAC_Address address) {
    this->address = address;
};

/**
* �����, ���������� ���������� �� ���������� � �������
*/
void Repeater::print_info() {
    std::cout << "Device info: " << std::endl;
    std::cout << "   - MAC Address: " << address.as_string() << " " << std::endl;
};

/**
* ��������� �����, ������������ ���������� �� �������� �� ���������
*/
void Repeater::reset() {
    set_defaults();
}
