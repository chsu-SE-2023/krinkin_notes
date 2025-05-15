#pragma once
#include "../misc/address.h"

class NetDevice {
protected:
	virtual void set_defaults() = 0;
public:
	virtual const double* get_packets() const = 0;
	virtual void receive(const double*&) = 0;
	virtual MAC_Address get_address() const = 0;
	virtual void set_address(MAC_Address) = 0;
	virtual void print_info() const = 0;
	virtual void reset() = 0;
};