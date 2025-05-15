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
    Switch(std::vector<int>&);
    Switch(std::array<int, 5>&);
    Switch(std::vector<int>&, std::array<int, 5>&);
    Switch(const double*&, std::vector<int>&, std::array<int, 5>&);
    Switch(Switch&);
    ~Switch();
    friend bool operator>(const Switch&, const Switch&);
    friend bool operator<(const Switch&, const Switch&);
    int clients_count() const;
    std::vector<int> get_clients() const;
    void set_clients(std::vector<int>&);
    void print_info() const;
    void reset();
};
