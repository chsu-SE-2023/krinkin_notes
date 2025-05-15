#pragma once
#include <string>
#include <array>

class MAC_Address {
private:
	std::array<char, 6> values;

public:
	MAC_Address();
	MAC_Address(std::array<char, 6>);
	std::string as_string();
	void generate(unsigned int = time(0));
};