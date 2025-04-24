#pragma once
#include <array>

class NetDevice {
protected:
	std::array<int, 5> address;
	const double* packets;
	virtual void set_defaults() = 0;

public:

	virtual const double* get_packets() const = 0;
	virtual void receive(const double*&) = 0;
	virtual std::array<int, 5> get_address() const = 0;
	virtual void set_address(const std::array<int, 5>&) = 0;
	virtual void print_info() const = 0;
};