#pragma once
#include "gateway.h"
#include "wl_repeater.h"
#include <string>
#include <vector>
#include <array>

class Router: public Gateway, public WLRepeater {
protected:
    bool wps;
    void set_defaults();
public:
    Router();
    Router(std::string, std::string);
    Router(std::vector<int>&);
    Router(std::array<int, 5>&);
    Router(const double*&);
    Router(std::vector<int>&, std::array<int, 5>&);
    Router(const double*&, std::vector<int>&, std::array<int, 5>, std::string, std::string, std::string);
    Router(Router&);
    ~Router();
    std::array<int, 5> get_address() const;
    const double* get_packets() const;
    bool is_wps() const;
    void print_info() const;
    void set_address(const std::array<int, 5>&);
    void wps_init();
    void wps_connect(int);
    void receive(const double*&);
    void reset();
};
