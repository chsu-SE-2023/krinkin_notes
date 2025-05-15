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
    Gateway(std::vector<Client>&);
    Gateway(MAC_Address);
    Gateway(std::vector<Client>&, MAC_Address);
    Gateway(const double*&, std::vector<Client>&, MAC_Address, std::string);
    Gateway(Gateway&);
    ~Gateway();
    std::string get_protocol() const;
    void set_protocol(std::string);
    void print_info();
    void reset();
};
