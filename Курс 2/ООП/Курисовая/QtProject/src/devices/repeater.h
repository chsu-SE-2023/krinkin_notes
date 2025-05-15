#pragma once
#include "net_device.h"

class Repeater: public NetDevice {
protected:
    MAC_Address address;
    const double* packets;
    void set_defaults();
public:
    Repeater();
    Repeater(MAC_Address);
    Repeater(const double*&);
    Repeater(const double*&, MAC_Address);
    Repeater(Repeater&);
    ~Repeater();
    MAC_Address get_address() const;
    const double* get_packets() const;
    void set_address(const MAC_Address);
    void receive(const double*&);
    void print_info();
    void reset();
};
