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
    Router(const double*&);
    Router(std::vector<Client>&, MAC_Address);
    Router(const double*&, std::vector<Client>&, MAC_Address, std::string, std::string, std::string);
    Router(Router&);
    ~Router();
    MAC_Address get_address() const;
    const double* get_packets() const;
    bool is_wps() const;
    void print_info() const;
    void set_address(MAC_Address);
    void wps_init();
    void connect(Client);
    void connect(Client, std::string, std::string);
    void receive(const double*&);
    void reset();
};
