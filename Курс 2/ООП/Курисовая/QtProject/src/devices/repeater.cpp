#include "repeater.h"
#include <iostream>
#include <vector>

/**
* ��������� �����, �������� �������� �� ���������
*/
void Repeater::set_defaults() {
    this->packets = nullptr;
    this->address.fill(0);
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
Repeater::Repeater(std::array<int, 5> address) {
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
Repeater::Repeater(const double*& packets, std::array<int, 5> address) {
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
std::array<int, 5> Repeater::get_address() const {
    return address;
};

/**
* �����, ��������������� MAC-����� ����������
*
* @param MAC-�����
*/
void Repeater::set_address(const std::array<int, 5>& address) {
    this->address = address;
};

/**
* �����, ���������� ���������� �� ���������� � �������
*/
void Repeater::print_info() const {
    std::cout << "Device info: " << std::endl;
    std::cout << "   - MAC Address: ";
    for (int i = 0; i < address.size(); i++)
        std::cout << this->address[i] << ":";
    std::cout << "\b" << " " << std::endl;
};

/**
* ��������� �����, ������������ ���������� �� �������� �� ���������
*/
void Repeater::reset() {
    set_defaults();
}
