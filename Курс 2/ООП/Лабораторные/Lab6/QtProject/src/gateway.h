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
    Gateway(std::array<int, cli_cap>); // clients
    Gateway(std::array<int, 5>); // address
    Gateway(std::array<int, cli_cap>&, std::array<int, 5>); // clients, address
    Gateway(const double*&, std::array<int, cli_cap>&, std::array<int, 5>, std::string); // packets, clients, address, protocol
    Gateway(const Gateway&); // copy
    ~Gateway();
    std::string get_protocol() const;
    void set_protocol(std::string);
    void print_info() const;
    void reset();
};
