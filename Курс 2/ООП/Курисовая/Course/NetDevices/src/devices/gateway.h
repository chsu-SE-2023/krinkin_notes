#pragma once
#include "switch.h"
#include <string>
#include <vector>

class Gateway : public Switch {
protected:
    std::string protocol;
    void set_defaults();
public:
    Gateway();
    Gateway(std::vector<unsigned char>&);
    Gateway(std::vector<Client>&);
    Gateway(MAC_Address);
    Gateway(std::vector<Client>&, MAC_Address);
    Gateway(std::vector<unsigned char>&, std::vector<Client>&, MAC_Address, std::string);
    Gateway(const Gateway&);
    ~Gateway();
    virtual std::string get_info() override;
    virtual std::string get_protocol() const;
    virtual void set_protocol(std::string);
    virtual void reset() override;
    virtual std::string type_name() override;
};
