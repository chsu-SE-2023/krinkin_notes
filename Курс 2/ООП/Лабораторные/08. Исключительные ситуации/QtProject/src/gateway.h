#pragma once
#include "switch.h"
#include <string>
#include <array>
#include <vector>

class Gateway : public Switch {
protected:
    std::string protocol;
    void set_defaults();
    friend class Tests;
public:
    Gateway();
    Gateway(std::vector<int>&); // clients
    Gateway(std::array<int, 5>); // address
    Gateway(std::vector<int>&, std::array<int, 5>); // clients, address
    Gateway(const double*&, std::vector<int>&, std::array<int, 5>, std::string); // packets, clients, address, protocol
    Gateway(Gateway&); // copy
    ~Gateway();
    std::string get_protocol() const;
    void set_protocol(std::string);
    void print_info() const;
    void reset();
};
