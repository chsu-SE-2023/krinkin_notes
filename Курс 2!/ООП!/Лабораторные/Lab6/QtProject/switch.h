#pragma once
#include "bridge.h"
#include <array>

class Switch: public Bridge {

protected:
    static const int cli_cap = 32;
    std::array<int, cli_cap>& clients;

    void set_defaults();
    friend class Tests;

public:
    Switch();
    Switch(std::array<int, cli_cap>&); // clients
    Switch(std::array<int, 5>&); // address
    Switch(std::array<int, cli_cap>&, std::array<int, 5>&); // clients, address
    Switch(const std::vector<double>*&, std::array<int, cli_cap>&, std::array<int, 5>&); // packets, clients, address
    Switch(const Switch&); // copy
    ~Switch();
    friend bool operator>(Switch&, Switch&); // Оператор сравнения
    void print_info() const;
    void set_clients(std::array<int, cli_cap>);
    int clients_count() const;
    void reset();
};
