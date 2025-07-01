#pragma once
#include <vector>
#include "net_device.h"
#include "../misc/client.h"

class Repeater: public NetDevice_I {
protected:
    MAC_Address address;
    std::vector<unsigned char> bytes;
    std::vector<Client> clients;
    void set_defaults();
public:
    Repeater();
    Repeater(MAC_Address);
    Repeater(std::vector<unsigned char>&);
    Repeater(std::vector<unsigned char>&, MAC_Address);
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
    virtual std::vector<Client> get_clients();
    virtual std::string get_info() override;
    virtual std::vector<unsigned char> get_bytes() const override;
    virtual int package_size() const override;
    virtual void set_address(const MAC_Address&) override;
    virtual void receive(std::vector<unsigned char>&) override;
    virtual void reset() override;
    virtual std::string type_name();
};
