#pragma once
#include <iostream>
#include <string>

class Analyser {
private:
	std::string buffer = "";
	int state = 0;
	bool is_delim(char);
	bool is_sign(char);

public:

	void clearState();
	int getState() const;
	char space_filter(char);
	std::string lexem_filter(char, char);
};
