#pragma once
#include <string>

class Archiver {

private:
	int progress = 0;
	int fsize = 0;
	int processed = 0;

public:
	void updateProgress();
	int getProgress();
	void compress(std::string, std::string);
	void decompress(std::string, std::string);
};