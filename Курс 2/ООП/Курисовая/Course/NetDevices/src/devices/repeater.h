#pragma once
#include "net_device.h"

class Repeater: public NetDevice_I {
protected:
    MAC_Address address;
    const unsigned char* bytes;
    void set_defaults();
public:
    Repeater();
    Repeater(MAC_Address);
    Repeater(const unsigned char*&);
    Repeater(const unsigned char*&, MAC_Address);
    Repeater(const Repeater&);
    ~Repeater();
    friend bool operator>(const Repeater&, const Repeater&);
    friend bool operator<(const Repeater&, const Repeater&);
    friend bool operator>=(const Repeater&, const Repeater&);
    friend bool operator<=(const Repeater&, const Repeater&);
    friend bool operator==(const Repeater&, const Repeater&);
    friend bool operator!=(const Repeater&, const Repeater&);
    int clients_count() const;
    MAC_Address get_address() const;
    std::string get_info();
    const unsigned char* get_bytes() const;
    void set_address(const MAC_Address);
    void receive(const unsigned char*&);
    void print_info();
    void reset();
};
