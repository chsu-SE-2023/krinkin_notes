#pragma once
#include <vector>
#include "address.h"
#include "../devices/net_device.h"

enum class ClientType {
	Wired,
	Wireless
};

class Client {
private:
	std::string name;
	MAC_Address address;
	std::vector<unsigned char> bytes;
	ClientType type;

public:
	Client();
	Client(std::string);
	Client(MAC_Address);
	Client(std::vector<unsigned char>);
	Client(std::string, MAC_Address, std::vector<unsigned char>, ClientType);
	Client(const Client&);
	~Client();
	friend bool operator==(const Client&, const Client&);
	MAC_Address get_address() const;
	std::string get_name() const;
	ClientType get_type() const;
	void set_address(MAC_Address);
	void set_name(std::string);
	void set_type(ClientType);
	void send_to(NetDevice_I*);
	std::vector<unsigned char> receive_from(NetDevice_I*);
};