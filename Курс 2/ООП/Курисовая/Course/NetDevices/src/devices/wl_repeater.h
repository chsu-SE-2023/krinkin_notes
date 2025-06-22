#pragma once
#include "repeater.h"
#include <string>

class WLRepeater : public Repeater {
protected:
	void set_defaults();
    bool wps;
    std::string ssid;
    std::string passwd;
public:
    WLRepeater();
    WLRepeater(std::string, std::string);
    WLRepeater(MAC_Address);
    WLRepeater(const unsigned char*&);
    WLRepeater(const unsigned char*&, MAC_Address, std::string, std::string);
    WLRepeater(const WLRepeater&);
    ~WLRepeater();
    void connect(Client&);
    void connect(Client&, std::string, std::string);
    std::string get_info();
    std::string get_ssid() const;
    bool is_wps() const;
    void print_info() const;
    void set_ssid(std::string);
    void set_passwd(std::string);
    void reset();
    void wps_init();
};
