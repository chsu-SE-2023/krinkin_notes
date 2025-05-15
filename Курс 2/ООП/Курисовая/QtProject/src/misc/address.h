#pragma once
#include <string>
#include <array>

class MAC_Address {
private:
	std::array<unsigned char, 6> values;

public:
	MAC_Address();
	MAC_Address(std::array<unsigned char, 6>);
	std::string as_string();
	void generate(unsigned int = time(0));
};