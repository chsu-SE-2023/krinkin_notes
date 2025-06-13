#pragma once
#include "gateway.h"
#include "wl_repeater.h"
#include <string>
#include <vector>

class Router: public Gateway, public WLRepeater {
protected:
    bool wps;
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
    int clients_count() const;
    MAC_Address get_address() const;
    std::string get_info();
    const unsigned char* get_bytes() const;
    bool is_wps() const;
    void print_info() const;
    void set_address(MAC_Address);
    void wps_init();
    void connect(Client);
    void connect(Client, std::string, std::string);
    void receive(const unsigned char*&);
    void reset();
};
