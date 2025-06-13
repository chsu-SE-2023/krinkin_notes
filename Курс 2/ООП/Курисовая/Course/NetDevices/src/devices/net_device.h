#pragma once
#include <string>
#include "../misc/address.h"

class NetDevice {
protected:
	virtual void set_defaults() = 0;
public:
	virtual const unsigned char* get_bytes() const = 0;
	virtual void receive(const unsigned char*&) = 0;
	virtual MAC_Address get_address() const = 0;
	virtual void set_address(MAC_Address) = 0;
	virtual std::string get_info() = 0;
	virtual void print_info() = 0;
	virtual void reset() = 0;
};