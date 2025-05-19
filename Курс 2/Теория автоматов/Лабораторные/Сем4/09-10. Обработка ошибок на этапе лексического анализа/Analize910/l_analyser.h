#pragma once
#include <iostream>
#include <string>

class Analyser {
private:
	std::string buffer = "";
	std::string error = "";
	bool is_id = false;
	int state = 0;
	int check_next = true;

public:
	Analyser();
	Analyser(Analyser*);
	void clear_state();
	std::string get_error();
	int get_state() const;
	bool is_delim(char);
	bool is_multisign();
	bool is_next_valid(char);
	bool is_sign(char);
	bool is_special(char);
	void set_state(int);
	char space_filter(char, char);
	std::string lexem_filter(char, char);
};
