#pragma once
#include <vector>
#include "net_device.h"
#include "../misc/client.h"

class Repeater: public NetDevice_I {
protected:
    MAC_Address address;
    const unsigned char* bytes;
    void set_defaults();
    std::vector<Client> clients;
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
    virtual int clients_count() const override;
    virtual void connect(Client&);
    virtual void disconnect(Client&);
    virtual MAC_Address get_address() const override;
    virtual std::string get_info() override;
    virtual const unsigned char* get_bytes() const override;
    virtual void set_address(const MAC_Address) override;
    virtual void receive(const unsigned char*&) override;
    virtual void reset() override;
    virtual std::string type_name();
};
