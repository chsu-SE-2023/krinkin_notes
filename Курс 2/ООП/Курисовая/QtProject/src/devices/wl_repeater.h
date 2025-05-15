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
    WLRepeater(std::string, std::string);
    WLRepeater(MAC_Address);
    WLRepeater(const double*&);
    WLRepeater(const double*&, MAC_Address, std::string, std::string);
    WLRepeater(WLRepeater&);
    ~WLRepeater();
    std::string get_ssid() const;
    void print_info() const;
    void set_ssid(std::string);
    void set_passwd(std::string);
    void reset();
};