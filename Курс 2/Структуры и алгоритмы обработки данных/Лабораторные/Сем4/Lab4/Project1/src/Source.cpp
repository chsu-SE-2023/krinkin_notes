#include "search_tree.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

std::string& strip(std::string& word) {
	std::string delims = ".,[]()=!?";
	for (int i = 0; i < delims.size(); i++)
		std::replace(word.begin(), word.end(), delims[i], '\0');
	return word;
}

int main() {
	std::string filename;
	std::cout << "Enter filename: "; std::cin >> filename;
	std::ifstream in(filename);
	std::string word;
	SearchTree tree();

	if (!in.is_open()) { std::cout << "File cannot be opened!" << std::endl; return 255; };

	while (std::getline(in, word, ' ')) {
		std::cout << strip(word) << std::endl;
	}

	in.close();
	return 0;
}