#pragma once
#include "address.h"
#include "../devices/net_device.h"

#define WIRED 0
#define WIRELESS 1

class Client {
private:
	std::string name;
	MAC_Address address;
	const double* packets;
	char type;

public:
	Client();
	Client(std::string);
	Client(MAC_Address);
	Client(double*);
	Client(std::string, MAC_Address, double*, char);
	Client(Client&);
	~Client();
	MAC_Address get_address() const;
	std::string get_name() const;
	char get_type() const;
	void set_address(MAC_Address);
	void set_name(std::string);
	void set_type(char);
	void send_to(NetDevice*);
	const double* receive_from(NetDevice*);
};