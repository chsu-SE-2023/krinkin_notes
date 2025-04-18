#pragma once
#include "repeater.h"
#include <string>
#include <array>

class WLRepeater : public Repeater {
protected:
	void set_defaults();
    std::string ssid;
    std::string passwd;
public:
    WLRepeater();
    WLRepeater(std::string, std::string); // ssid, passwd
    WLRepeater(std::array<int, 5>); // address
    WLRepeater(const double*&); // packets
    WLRepeater(const double*&, std::array<int, 5>, std::string, std::string); // packets, address, ssid, passwd
    WLRepeater(WLRepeater&); // copy
    ~WLRepeater();
    std::string get_ssid() const;
    void print_info() const;
    void set_ssid(std::string);
    void set_passwd(std::string);
    void reset();
};