#pragma once
#include "repeater.h"
#include <vector>
#include <array>

class Switch: public Repeater {

protected:
    static const int cli_cap = 32;
    std::vector<int> clients;
    void set_defaults();
public:
    Switch();
    Switch(std::vector<int>&); // clients
    Switch(std::array<int, 5>&); // address
    Switch(std::vector<int>&, std::array<int, 5>&); // clients, address
    Switch(const double*&, std::vector<int>&, std::array<int, 5>&); // packets, clients, address
    Switch(Switch&); // copy
    ~Switch();
    friend bool operator>(const Switch&, const Switch&); // Оператор сравнения
    int clients_count() const;
    std::vector<int> get_clients() const;
    void set_clients(std::vector<int>&);
    void print_info() const;
    void reset();
};
