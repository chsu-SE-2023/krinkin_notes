#pragma once
#include <iostream>
#include <string>

class Analyser {
private:
	std::string buffer = "";
	bool is_id = false;
	int state = 0;
	int check_next = true;

	bool is_delim(char);
	bool is_sign(char);
	bool is_next_valid(char);
	bool is_multisign();

public:
	Analyser();
	Analyser(Analyser*);
	void clearState();
	int getState() const;
	void setState(int);
	char space_filter(char);
	std::string lexem_filter(char, char);
};
