#pragma once
#include <array>
#include "net_device.h"

class Repeater: public NetDevice {

protected:
    void set_defaults();
public:
    Repeater();
    Repeater(std::array<int, 5>); // address
    Repeater(const double*&); // packets
    Repeater(const Repeater&); // copy
    ~Repeater();
    const double* get_packets() const;
    void receive(const double*&);
    std::array<int, 5> get_address() const;
    void set_address(const std::array<int, 5>&);
    void print_info() const;
};
