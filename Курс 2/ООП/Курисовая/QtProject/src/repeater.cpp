#include "repeater.h"
#include <iostream>
#include <vector>

void Repeater::set_defaults() {
    this->packets = nullptr;
    this->address.fill(0);
}

Repeater::Repeater() {
    set_defaults();
};

Repeater::Repeater(std::array<int, 5> address) {
    set_defaults();
    this->address = address;
};

Repeater::Repeater(const double*& packets) {
    set_defaults();
    this->packets = packets;
};

Repeater::Repeater(const double*& packets, std::array<int, 5> address) {
    set_defaults();
    this->packets = packets;
    this->address = address;
}

Repeater::Repeater(Repeater& copy) {
    this->address = copy.address;
    this->packets = copy.packets;
};

Repeater::~Repeater() {
    // Need I to delete external packets?
    /*if (packets != nullptr)
        delete packets;*/
};

const double* Repeater::get_packets() const {
    return packets;
};

void Repeater::receive(const double*& packets) {
    this->packets = packets;
};

std::array<int, 5> Repeater::get_address() const {
    return address;
};

void Repeater::set_address(const std::array<int, 5>& address) {
    this->address = address;
};

void Repeater::print_info() const {
    std::cout << "Device info: " << std::endl;
    std::cout << "   - MAC Address: ";
    for (int i = 0; i < address.size(); i++)
        std::cout << this->address[i] << ":";
    std::cout << "\b" << " " << std::endl;
};

void Repeater::reset() {
    set_defaults();
}
