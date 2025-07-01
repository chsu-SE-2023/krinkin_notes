#pragma once
#include <string>
#include <array>
#include <ctime>

class MAC_Address {
private:
	std::array<unsigned char, 6> values;

public:
	MAC_Address();
	MAC_Address(std::array<unsigned char, 6>);
	MAC_Address(std::string);
	MAC_Address(const MAC_Address&);
	friend bool operator>(const MAC_Address&, const MAC_Address&);
	friend bool operator<(const MAC_Address&, const MAC_Address&);
	friend bool operator>=(const MAC_Address&, const MAC_Address&);
	friend bool operator<=(const MAC_Address&, const MAC_Address&);
    friend bool operator== (const MAC_Address&, const MAC_Address&);
    friend bool operator!= (const MAC_Address&, const MAC_Address&);
	std::string as_string();
	void generate();
};
