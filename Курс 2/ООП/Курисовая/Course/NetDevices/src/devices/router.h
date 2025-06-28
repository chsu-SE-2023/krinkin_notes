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
    Router(const unsigned char*&);
    Router(std::vector<Client>&, MAC_Address);
    Router(const unsigned char*&, std::vector<Client>&, MAC_Address, std::string, std::string, std::string);
    Router(const Router&);
    ~Router();
    virtual int clients_count() const override;
    virtual MAC_Address get_address() const override;
    virtual std::vector<Client> get_clients() override;
    virtual std::string get_info() override;
    virtual const unsigned char* get_bytes() const override;
    virtual void set_address(MAC_Address) override;
    virtual void connect(Client&) override;
    virtual void connect(Client&, std::string, std::string) override;
    virtual void receive(const unsigned char*&) override;
    virtual void reset() override;
    virtual std::string type_name() override;
};
