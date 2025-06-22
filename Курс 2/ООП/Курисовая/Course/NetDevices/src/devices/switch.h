#pragma once
#include "repeater.h"
#include "../misc/client.h"
#include <vector>

class Switch: public Repeater {

protected:
    static int cli_cap;
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
    friend bool operator>=(const Switch&, const Switch&);
    friend bool operator<=(const Switch&, const Switch&);
    friend bool operator==(const Switch&, const Switch&);
    friend bool operator!=(const Switch&, const Switch&);
    int clients_count() const;
    void connect(Client&);
    std::vector<Client> get_clients() const;
    std::string get_info();
    static void set_capacity(int);
    void set_clients(std::vector<Client>&);
    void print_info();
    void reset();
};
