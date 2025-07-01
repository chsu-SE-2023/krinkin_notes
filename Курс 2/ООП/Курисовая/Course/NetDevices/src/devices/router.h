#pragma once
#include "gateway.h"
#include "wl_repeater.h"
#include <string>
#include <vector>

class Router: public Gateway, public WLRepeater {
protected:
    void set_defaults();
public:
    Router();
    Router(std::string, std::string);
    Router(std::vector<Client>&);
    Router(MAC_Address);
    Router(std::vector<unsigned char>&);
    Router(std::vector<Client>&, MAC_Address);
    Router(std::vector<unsigned char>&, std::vector<Client>&, MAC_Address, std::string, std::string, std::string);
    Router(const Router&);
    ~Router();
    virtual int clients_count() const override;
    virtual MAC_Address get_address() const override;
    virtual std::vector<Client> get_clients() override;
    virtual std::string get_info() override;
    virtual std::vector<unsigned char> get_bytes() const override;
    virtual int package_size() const override;
    virtual void set_address(const MAC_Address&) override;
    virtual void connect(Client&) override;
    virtual void connect(Client&, std::string, std::string) override;
    virtual void disconnect(Client&) override;
    virtual void receive(std::vector<unsigned char>&) override;
    virtual void reset() override;
    virtual std::string type_name() override;
};
