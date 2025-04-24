#pragma once
#include "gateway.h"
#include <iostream>

void Gateway::set_defaults() {
    Switch::set_defaults();
    this->clients = {};
}

Gateway::Gateway() {
    set_defaults();
};

Gateway::Gateway(std::array<int, cli_cap> clients) {
    set_defaults();
    this->clients = clients;
};

Gateway::Gateway(std::array<int, 5> address) {
    set_defaults();
    this->address = address;
};

Gateway::Gateway(std::array<int, cli_cap>& clients, std::array<int, 5> address) {
    set_defaults();
    this->clients = clients;
    this->address = address;
};

Gateway::Gateway(const double*& packets, std::array<int, cli_cap>& clients, std::array<int, 5> address, std::string protocol) {
    set_defaults();
    this->packets = packets;
    this->clients = clients;
    this->address = address;
    this->protocol = protocol;
};

Gateway::Gateway(const Gateway& copy) {
    this->packets = copy.packets;
    this->clients = copy.clients;
    this->address = copy.address;
    this->protocol = copy.protocol;
};

Gateway::~Gateway() {
    Switch::~Switch();
    this->protocol = "";
};

std::string Gateway::get_protocol() const {
    return protocol;
};

void Gateway::set_protocol(std::string protocol) {
    this->protocol = protocol;
};

void Gateway::print_info() const {
    Switch::print_info();
    std::cout << "Protocol - " << this->protocol << std::endl;
};

void Gateway::reset() {
    set_defaults();
};