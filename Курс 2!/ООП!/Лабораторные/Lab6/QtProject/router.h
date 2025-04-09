#pragma once
#include "gateway.h"
#include <string>
#include <vector>
#include <array>

class Router: public Gateway {
private:
    std::string ssid;
    std::string passwd;
    bool wpa;

protected:
    void set_defaults();
    friend class Tests;

public:
    Router();
    Router(std::string, std::string); // ssid, passwd
    Router(const std::vector<double>*&, std::array<int, cli_cap>, std::array<int, 5>, std::string, std::string, std::string); // packets, clients, address, protocol, ssid, passwd
    Router(const Router&); // copy
    std::string get_ssid() const;
    bool wpa_enabled() const;
    void print_info() const;
    void set_ssid(std::string);
    void set_passwd(std::string);
    void set_wpa(bool);
    void reset();
};
