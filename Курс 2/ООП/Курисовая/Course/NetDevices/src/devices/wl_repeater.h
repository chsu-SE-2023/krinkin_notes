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
    WLRepeater(std::vector<unsigned char>&);
    WLRepeater(std::vector<unsigned char>&, MAC_Address, std::string, std::string);
    WLRepeater(const WLRepeater&);
    ~WLRepeater();
    virtual void connect(Client&) override;
    virtual void connect(Client&, std::string, std::string);
    virtual std::string get_info() override;
    virtual std::string get_ssid() const;
    virtual bool is_wps() const;
    virtual void set_ssid(std::string);
    virtual void set_passwd(std::string);
    virtual void reset() override;
    virtual std::string type_name() override;
    virtual void wps_init();
};
