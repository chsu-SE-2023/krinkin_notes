#pragma once
#include <string>
#include <vector>
#include "../misc/address.h"

class NetDevice_I {
protected:
	virtual void set_defaults() = 0;
public:
	virtual int clients_count() const = 0;
	virtual MAC_Address get_address() const = 0;
	virtual int package_size() const = 0;
	virtual std::vector<unsigned char> get_bytes() const = 0;
	virtual std::string get_info() = 0;
	virtual void receive(std::vector<unsigned char>&) = 0;
	virtual void reset() = 0;
	virtual void set_address(MAC_Address) = 0;
};