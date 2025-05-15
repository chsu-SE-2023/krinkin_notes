#pragma once
#include <array>
#include "net_device.h"

class Repeater: public NetDevice {
protected:
    std::array<int, 5> address;
    const double* packets;
    void set_defaults();
public:
    Repeater();
    Repeater(std::array<int, 5>); // address
    Repeater(const double*&); // packets
    Repeater(const double*&, std::array<int, 5>); // packets, address
    Repeater(Repeater&); // copy
    ~Repeater();
    std::array<int, 5> get_address() const;
    const double* get_packets() const;
    void set_address(const std::array<int, 5>&);
    void receive(const double*&);
    void print_info() const;
    void reset();
};
