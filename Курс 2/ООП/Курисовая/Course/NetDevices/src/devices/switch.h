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
    Switch(std::vector<unsigned char>&);
    Switch(std::vector<Client>&);
    Switch(MAC_Address);
    Switch(std::vector<Client>&, MAC_Address);
    Switch(std::vector<unsigned char>&, std::vector<Client>&, MAC_Address);
    Switch(const Switch&);
    ~Switch();
    friend bool operator>(const Switch&, const Switch&);
    friend bool operator<(const Switch&, const Switch&);
    friend bool operator>=(const Switch&, const Switch&);
    friend bool operator<=(const Switch&, const Switch&);
    friend bool operator==(const Switch&, const Switch&);
    friend bool operator!=(const Switch&, const Switch&);
    virtual int clients_count() const override;
    virtual void connect(Client&) override;
    static int get_capacity();
    virtual std::vector<Client> get_clients() const;
    virtual std::string get_info() override;
    static void set_capacity(int);
    virtual void set_clients(std::vector<Client>&);
    virtual void reset() override;
    virtual std::string type_name() override;
};
