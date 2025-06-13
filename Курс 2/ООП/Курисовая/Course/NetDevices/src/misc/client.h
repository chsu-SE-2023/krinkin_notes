#pragma once
#include "address.h"
#include "../devices/net_device.h"

#define WIRED 0
#define WIRELESS 1

class Client {
private:
	std::string name;
	MAC_Address address;
	const unsigned char* bytes;
	char type;

public:
	Client();
	Client(std::string);
	Client(MAC_Address);
	Client(unsigned char*);
	Client(std::string, MAC_Address, unsigned char*, char);
	Client(const Client&);
	~Client();
	friend bool operator==(const Client&, const Client&);
	MAC_Address get_address() const;
	std::string get_name() const;
	char get_type() const;
	void set_address(MAC_Address);
	void set_name(std::string);
	void set_type(char);
	void send_to(NetDevice*);
	const unsigned char* receive_from(NetDevice*);
};