#pragma once
#include <fstream>
#include <string>
#include <iostream>

class Analyser {
public:
	std::string source;
	std::string stripped;
	int state;

	Analyser() {
		state = 0;
	}

	// Чтение файла
	std::string& readSource(std::string fileName) {
		std::ifstream file(fileName);
		std::string line;
		this->source = "";
		while (std::getline(file, line)) {
			this->source += line + '\n';
		}
		file.close();
		return this->source;
	}

	// Функция, обрабатывающая текст и оправляющая символы анализатору
	std::string& stripSource() {
		this->stripped = "";
		for (int i = 0; i < source.size(); i++) {
			char out = filter(source[i]);
			if (out != -1) this->stripped += out;
		}
		return this->stripped;
	}

	// Функция, возвращающая количество строк в тексте
	int getLineCount(std::string text) {
		int res = 0;
		for (int i = 0; i < text.length() ;i++)
			if (text[i] == '\n')
				res++;
		return res;
	}

private:
	// Функция анализатора
	char filter(char c) {
		if (c == '	') return -1;
		switch (state) {
		case 0: {
			switch (c) {
			case '/': { state = 1; break; }
			case ' ': { state = 4; break; }
			case '\n': { state = 4; break; }
			default: { state = 0; break; }
			} break;
		}
		case 1: {
			switch (c) {
			case '/': { state = 1; break; }
			case '*': { state = 2; break; }
			case '\n': { state = 5; break; }
			} break;
		}
		case 2: {
			switch (c) {
			case '*': { state = 3; break; }
			default: { state = 2; break; }
			} break;
		}
		case 3: {
			switch (c) {
			case '/': { state = 5; break; }
			default: { state = 2; break; }
			} break;
		}
		case 4: {
			switch (c) {
			case '/': { state = 1; break; }
			case '\n': { state = 5; break; }
			case ' ': { state = 5; break; }
			default: { state = 0; break; }
			} break;
		}
		case 5: {
			switch (c) {
			case '/': { state = 1; break; }
			case ' ': { state = 5; break; }
			case '\n': { state = 5; break; }
			default: { state = 0; break; }
			} break;
		}
		}

		// Печать обрабатываемых символов в консоль (отладка)
#ifdef _DEBUG
		if (c == '\n') std::cout << "\\n" << " " << state;
		else if (c == '\r') std::cout << "\\r" << " " << state;
		else std::cout << c << " " << state;
		if (state == 0 || state == 4) {
			std::cout << " - Valid";
		};
		std::cout << std::endl;
#endif

		if (state == 0 || state == 4) 
			return c;
		return -1;
	}
};
