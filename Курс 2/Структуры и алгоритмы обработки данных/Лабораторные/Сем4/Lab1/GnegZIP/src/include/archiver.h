#pragma once
#include <string>

class Archiver {

private:
	int progress = 0;
	int fsize = 1;
	int processed = 0;

public:
	void updateProgress();
	void clearProgress();
	int getProgress();
	void compress(std::string, std::string);
	void decompress(std::string, std::string);
};