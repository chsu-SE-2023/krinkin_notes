#pragma once
#include "repeater.h"
#include <vector>
#include <array>

class Bridge: public Repeater {

protected:
    std::array<int, 5>& address;
    int connected;
    void set_defaults();

public:
    Bridge();
    Bridge(std::array<int, 5>&); // address
    Bridge(const std::vector<double>*&, std::array<int, 5>&); // packets, address
    Bridge(Bridge&); // copy
    ~Bridge();
    void connect();
    void disconnect();
    void print_info() const;
    std::array<int, 5> get_address() const;
    int get_connected() const;
    void set_address(const std::array<int, 5>&);
};
