#pragma once
#include "repeater.h"
#include "../misc/client.h"
#include <vector>

class Switch: public Repeater {

protected:
    static const int cli_cap = 32;
    std::vector<Client> clients;
    void set_defaults();
public:
    Switch();
    Switch(const unsigned char*&);
    Switch(std::vector<Client>&);
    Switch(MAC_Address);
    Switch(std::vector<Client>&, MAC_Address);
    Switch(const unsigned char*&, std::vector<Client>&, MAC_Address);
    Switch(const Switch&);
    ~Switch();
    friend bool operator>(const Switch&, const Switch&);
    friend bool operator<(const Switch&, const Switch&);
    int clients_count() const;
    void connect(Client);
    void disconnect(Client);
    std::vector<Client> get_clients() const;
    std::string get_info();
    void set_clients(std::vector<Client>&);
    void print_info();
    void reset();
};
