#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iostream>

class Analyser {
private:
	std::string source;
	std::string stripped;
	std::string buffer = "";
	int state = 0;

	bool is_delim(char c) {
		std::string delimers = " ,:;(){}'\"\n\0";
		return std::count(delimers.begin(), delimers.end(), c) > 0;
	}

	bool is_sign(char c) {
		std::string signs = ".:[]<>+-/*=#&";
		return std::count(signs.begin(), signs.end(), c) > 0;
	}

public:

	void clearState() {
		this->state = 0;
		this->buffer = "";
	}

	int getState() const {
		return this->state;
	}

	const std::string& getStripped() const {
		return this->stripped;
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
		this->state = 0;
		this->stripped = "";
		for (int i = 0; i < source.size(); i++) {
			char out = space_filter(source[i]);
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

	// Функция анализатора
	char space_filter(char c) {
		if (c == '	') return -1;
		switch (state) {
		case 0: {
			switch (c) {
			case '/': { state = 1; break; }
			case ' ': { state = 4; break; }
			case '\n': { state = 4; break; }
			default: { switch (c) {
			default: { state = 0; break; }
			} break; break; }
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
			default: { switch (c) {
			default: { state = 0; break; }
			} break; break; }
			} break;
		}
		case 5: {
			switch (c) {
			case '/': { state = 1; break; }
			case ' ': { state = 5; break; }
			case '\n': { state = 5; break; }
			default: { switch (c) {
			default: { state = 0; break; }
			} break; break; }
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

	std::string lexem_filter(char c, char next) {
		/*if (state == 0) buffer = "";*/

		switch (state) {
		case 0: {
			switch (c) {
			// Ключевые слова
			case 'a': { state = 7; break; }
			case 'b': { state = 10; break; }
			case 'c': { state = 16; break; }
			case 'd': { state = 24; break; }
			case 'e': { state = 33; break; }
			case 'f': { state = 36; break; }
			case 'i': { state = 41; break; }
			case 'p': { state = 43; break; }
			case 'r': { state = 53; break; }
			case 't': { state = 58; break; }
			case 'v': { state = 61; break; }

			// Константы
			case '0': { state = 2; break; }
			case '1': { state = 2; break; }
			case '2': { state = 2; break; }
			case '3': { state = 2; break; }
			case '4': { state = 2; break; }
			case '5': { state = 2; break; }
			case '6': { state = 2; break; }
			case '7': { state = 2; break; }
			case '8': { state = 2; break; }
			case '9': { state = 2; break; }

			// Операторы отношения
			case '<': { state = 4; break; }
			case '>': { state = 4; break; }

			// Знаки операций
			case '.': { state = 5; break; }
			case '+': { state = 5; break; }
			case '-': { state = 5; break; }
			case '/': { state = 5; break; }
			case '*': { state = 5; break; }
			case '=': { state = 5; break; }
			case '[': { state = 5; break; }
			case ']': { state = 5; break; }
			case '#': { state = 5; break; }
			case '&': { state = 5; break; }

			// Разделители
			case ' ': { state = 6; break; }
			case ',': { state = 6; break; }
			case ';': { state = 6; break; }
			case ':': { state = 6; break; }
			case '\'': { state = 6; break; }
			case '\"': { state = 6; break; }
			case '{': { state = 6; break; }
			case '}': { state = 6; break; }
			case '(': { state = 6; break; }
			case ')': { state = 6; break; }
			case '\n': { state = 6; break; }
			
			default: { state = 0; break; }
			} break;
		}
		case 1: {
			switch (c) {
			default: { state = 0; break; }
			} break;
		}
		case 2: {
			switch (c) {
			case '0': { state = 2; break; }
			case '1': { state = 2; break; }
			case '2': { state = 2; break; }
			case '3': { state = 2; break; }
			case '4': { state = 2; break; }
			case '5': { state = 2; break; }
			case '6': { state = 2; break; }
			case '7': { state = 2; break; }
			case '8': { state = 2; break; }
			case '9': { state = 2; break; }
			case 'e': { state = 69; break; }
			case 'E': { state = 69; break; }
			case '.': { state = 68; break; }
			default: { state = 0; break; }
			} break;
		}
		case 3: {
			switch (c) {
			default: { state = 0; break; }
			} break;
		}
		case 4: {
			switch (c) {
			case '=': { state = 4; break; }
			case '>': { state = 5; break; }
			case '<': { state = 5; break; }
			default: { state = 0; break; }
			} break;
		}
		case 5: {
			switch (c) {
			case '0': { state = 2; break; }
			case '1': { state = 2; break; }
			case '2': { state = 2; break; }
			case '3': { state = 2; break; }
			case '4': { state = 2; break; }
			case '5': { state = 2; break; }
			case '6': { state = 2; break; }
			case '7': { state = 2; break; }
			case '8': { state = 2; break; }
			case '9': { state = 2; break; }

			case '=': { state = 5; break; }
			case '+': { state = 5; break; }
			case '-': { state = 5; break; }
			case '>': { state = 5; break; }
			default: { state = 0; break; }
			} break;
		}
		case 6: {
			switch (c) {
			case ':': { state = 5; break; }
			default: { state = 0; break; }
			} break;
		}
		case 7: {
			switch (c) {
			case 'u': { state = 8; break; }
			default: { state = 0; break; }
			} break;
		}
		case 8: {
			switch (c) {
			case 't': { state = 9; break; }
			default: { state = 0; break; }
			} break;
		}
		case 9: {
			switch (c) {
			case 'o': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 10: {
			switch (c) {
			case 'r': { state = 11; break; }
			case 'o': { state = 14; break; }
			default: { state = 0; break; }
			} break;
		}
		case 11: {
			switch (c) {
			case 'e': { state = 12; break; }
			default: { state = 0; break; }
			} break;
		}
		case 12: {
			switch (c) {
			case 'a': { state = 13; break; }
			default: { state = 0; break; }
			} break;
		}
		case 13: {
			switch (c) {
			case 'k': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 14: {
			switch (c) {
			case 'o': { state = 15; break; }
			default: { state = 0; break; }
			} break;
		}
		case 15: {
			switch (c) {
			case 'l': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 16: {
			switch (c) {
			case 'l': { state = 17; break; }
			case 'h': { state = 20; break; }
			case 'a': { state = 22; break; }
			default: { state = 0; break; }
			} break;
		}
		case 17: {
			switch (c) {
			case 'a': { state = 18; break; }
			default: { state = 0; break; }
			} break;
		}
		case 18: {
			switch (c) {
			case 's': { state = 19; break; }
			default: { state = 0; break; }
			} break;
		}
		case 19: {
			switch (c) {
			case 's': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 20: {
			switch (c) {
			case 'a': { state = 21; break; }
			default: { state = 0; break; }
			} break;
		}
		case 21: {
			switch (c) {
			case 'r': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 22: {
			switch (c) {
			case 's': { state = 23; break; }
			default: { state = 0; break; }
			} break;
		}
		case 23: {
			switch (c) {
			case 'e': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 24: {
			switch (c) {
			case 'o': { state = 25; break; }
			case 'e': { state = 29; break; }
			default: { state = 0; break; }
			} break;
		}
		case 25: {
			switch (c) {
			case 'u': { state = 26; break; }
			default: { state = 0; break; }
			} break;
		}
		case 26: {
			switch (c) {
			case 'b': { state = 27; break; }
			default: { state = 0; break; }
			} break;
		}
		case 27: {
			switch (c) {
			case 'l': { state = 28; break; }
			default: { state = 0; break; }
			} break;
		}
		case 28: {
			switch (c) {
			case 'e': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 29: {
			switch (c) {
			case 'l': { state = 30; break; }
			default: { state = 0; break; }
			} break;
		}
		case 30: {
			switch (c) {
			case 'e': { state = 31; break; }
			default: { state = 0; break; }
			} break;
		}
		case 31: {
			switch (c) {
			case 't': { state = 32; break; }
			default: { state = 0; break; }
			} break;
		}
		case 32: {
			switch (c) {
			case 'e': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 33: {
			switch (c) {
			case 'l': { state = 34; break; }
			default: { state = 0; break; }
			} break;
		}
		case 34: {
			switch (c) {
			case 's': { state = 35; break; }
			default: { state = 0; break; }
			} break;
		}
		case 35: {
			switch (c) {
			case 'e': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 36: {
			switch (c) {
			case 'a': { state = 37; break; }
			case 'o': { state = 40; break; }
			case 'l': { state = 64; break; }
			default: { state = 0; break; }
			} break;
		}
		case 37: {
			switch (c) {
			case 'l': { state = 38; break; }
			default: { state = 0; break; }
			} break;
		}
		case 38: {
			switch (c) {
			case 's': { state = 39; break; }
			default: { state = 0; break; }
			} break;
		}
		case 39: {
			switch (c) {
			case 'e': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 40: {
			switch (c) {
			case 'r': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 41: {
			switch (c) {
			case 'n': { state = 42; break; }
			case 'f': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 42: {
			switch (c) {
			case 't': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 43: {
			switch (c) {
			case 'r': { state = 44; break; }
			case 'u': { state = 49; break; }
			default: { state = 0; break; }
			} break;
		}
		case 44: {
			switch (c) {
			case 'i': { state = 45; break; }
			default: { state = 0; break; }
			} break;
		}
		case 45: {
			switch (c) {
			case 'v': { state = 46; break; }
			default: { state = 0; break; }
			} break;
		}
		case 46: {
			switch (c) {
			case 'a': { state = 47; break; }
			default: { state = 0; break; }
			} break;
		}
		case 47: {
			switch (c) {
			case 't': { state = 48; break; }
			default: { state = 0; break; }
			} break;
		}
		case 48: {
			switch (c) {
			case 'e': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 49: {
			switch (c) {
			case 'b': { state = 50; break; }
			default: { state = 0; break; }
			} break;
		}
		case 50: {
			switch (c) {
			case 'l': { state = 51; break; }
			default: { state = 0; break; }
			} break;
		}
		case 51: {
			switch (c) {
			case 'i': { state = 52; break; }
			default: { state = 0; break; }
			} break;
		}
		case 52: {
			switch (c) {
			case 'c': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 53: {
			switch (c) {
			case 'e': { state = 54; break; }
			default: { state = 0; break; }
			} break;
		}
		case 54: {
			switch (c) {
			case 't': { state = 55; break; }
			default: { state = 0; break; }
			} break;
		}
		case 55: {
			switch (c) {
			case 'u': { state = 56; break; }
			default: { state = 0; break; }
			} break;
		}
		case 56: {
			switch (c) {
			case 'r': { state = 57; break; }
			default: { state = 0; break; }
			} break;
		}
		case 57: {
			switch (c) {
			case 'n': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 58: {
			switch (c) {
			case 'r': { state = 59; break; }
			default: { state = 0; break; }
			} break;
		}
		case 59: {
			switch (c) {
			case 'u': { state = 60; break; }
			default: { state = 0; break; }
			} break;
		}
		case 60: {
			switch (c) {
			case 'e': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 61: {
			switch (c) {
			case 'o': { state = 62; break; }
			default: { state = 0; break; }
			} break;
		}
		case 62: {
			switch (c) {
			case 'i': { state = 63; break; }
			default: { state = 0; break; }
			} break;
		}
		case 63: {
			switch (c) {
			case 'd': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 64: {
			switch (c) {
			case 'o': { state = 65; break; }
			default: { state = 0; break; }
			} break;
		}
		case 65: {
			switch (c) {
			case 'a': { state = 66; break; }
			default: { state = 0; break; }
			} break;
		}
		case 66: {
			switch (c) {
			case 't': { state = 1; break; }
			default: { state = 0; break; }
			} break;
		}
		case 68: {
			switch (c) {
			case '0': { state = 2; break; }
			case '1': { state = 2; break; }
			case '2': { state = 2; break; }
			case '3': { state = 2; break; }
			case '4': { state = 2; break; }
			case '5': { state = 2; break; }
			case '6': { state = 2; break; }
			case '7': { state = 2; break; }
			case '8': { state = 2; break; }
			case '9': { state = 2; break; }
			default: { state = 0; break; }
			} break;
		}
		case 69: {
			switch (c) {
			case '0': { state = 2; break; }
			case '1': { state = 2; break; }
			case '2': { state = 2; break; }
			case '3': { state = 2; break; }
			case '4': { state = 2; break; }
			case '5': { state = 2; break; }
			case '6': { state = 2; break; }
			case '7': { state = 2; break; }
			case '8': { state = 2; break; }
			case '9': { state = 2; break; }
			case '-': { state = 70; break; }
			case '+': { state = 70; break; }
			default: { state = 0; break; }
			} break;
		}
		case 70: {
			switch (c) {
			case '0': { state = 2; break; }
			case '1': { state = 2; break; }
			case '2': { state = 2; break; }
			case '3': { state = 2; break; }
			case '4': { state = 2; break; }
			case '5': { state = 2; break; }
			case '6': { state = 2; break; }
			case '7': { state = 2; break; }
			case '8': { state = 2; break; }
			case '9': { state = 2; break; }
			default: { state = 0; break; }
			} break;
		}
		}

		buffer += c;

		// Лексемы
		if (state > 0 && state < 4 && (is_delim(next) || is_sign(next))) {
			if (state != 2 || next != '.')
				return buffer;
		}

		// Знаки
		if ((state == 4 || state == 5) && !is_sign(next)) {
			return buffer;
		}

		// Разделители
		if (is_delim(c)) {
			return buffer;
		}

		// Идентификаторы
		if (buffer != "" && (state == 0 || state > 6 && state < 68) && (is_delim(next) || is_sign(next))) {
			state = 3; return buffer;
		}

		return "";
	}
};
