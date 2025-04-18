#pragma once
#include "repeater.h"
#include <array>

class Switch: public Repeater {

protected:
    static const int cli_cap = 32;
    std::array<int, cli_cap> clients;
    void set_defaults();
public:
    Switch();
    Switch(std::array<int, cli_cap>&); // clients
    Switch(std::array<int, 5>&); // address
    Switch(std::array<int, cli_cap>&, std::array<int, 5>&); // clients, address
    Switch(const double*&, std::array<int, cli_cap>&, std::array<int, 5>&); // packets, clients, address
    Switch(Switch&); // copy
    ~Switch();
    friend bool operator>(Switch&, Switch&); // Оператор сравнения
    int clients_count() const;
    std::array<int, cli_cap> get_clients() const;
    void set_clients(std::array<int, cli_cap>&);
    void print_info() const;
    void reset();
};
