#include <iostream>
#include <string>
#include "l_analyser.h"

/*
* Метод, возвращающий является ли разделителем
* заданный символ
*/
bool Analyser::is_delim(char c) {
	std::string delimers = " ,:;(){}'\"\n\0";
	return std::count(delimers.begin(), delimers.end(), c) > 0;
}

/*
* Метод, возвращающий является ли знаком
* заданный символ
*/
bool Analyser::is_sign(char c) {
	std::string signs = ".:[]<>+-/*=#&|";
	return std::count(signs.begin(), signs.end(), c) > 0;
}

/*
* Метод, сбрасывающий состояние конечного автомата
*/
void Analyser::clearState() {
	this->state = 0;
	this->buffer = "";
}

/*
* Метод, возвращающий состояние конечного автомата
*/
int Analyser::getState() const {
	return this->state;
}

/*
* Метод, лексического анализатора для удаления
* пробелов, переносов, комментариев
*/
char Analyser::space_filter(char c) {
	if (c == '	') return -1;
	switch (state) {
	case 0: {
		switch (c) {
		case '/': { state = 1; break; }
		case ' ': { state = 4; break; }
		case '\n': { state = 5; break; }
		case '\r': { state = 5; break; }
		default: { state = 0; break; }
		} break;
	}
	case 1: {
		switch (c) {
		case '/': { state = 1; break; }
		case '*': { state = 2; break; }
		case '\n': { state = 5; break; }
		case '\r': { state = 5; break; }
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
		case ' ': { state = 5; break; }
		case '\n': { state = 5; break; }
		case '\r': { state = 5; break; }
		default: { state = 0; break; }
		} break;
	}
	case 5: {
		switch (c) {
		case '/': { state = 1; break; }
		case ' ': { state = 5; break; }
		case '\n': { state = 5; break; }
		case '\r': { state = 5; break; }
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

/*
* Метод, лексического анализатора для разделения
* лексем и определения их типа
*/
std::string Analyser::lexem_filter(char c, char next) {
	switch (state) {
	case 0: {
		switch (c) { 
			// Ключевые слова
		case 'a': { state = 11; break; }
		case 'b': { state = 24; break; }
		case 'c': { state = 35; break; }
		case 'd': { state = 75; break; }
		case 'e': { state = 102; break; }
		case 'f': { state = 118; break; }
		case 'g': { state = 130; break; }
		case 'i': { state = 133; break; }
		case 'l': { state = 138; break; }
		case 'm': { state = 141; break; }
		case 'n': { state = 147; break; }
		case 'o': { state = 169; break; }
		case 'p': { state = 178; break; }
		case 'r': { state = 194; break; }
		case 's': { state = 227; break; }
		case 't': { state = 268; break; }
		case 'u': { state = 298; break; }
		case 'v': { state = 310; break; }
		case 'w': { state = 323; break; }
		case 'x': { state = 332; break; }

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
		case '<': { state = 3; break; }
		case '>': { state = 3; break; }

				// Знаки операций
		case '.': { state = 4; break; }
		case ',': { state = 4; break; }
		case '[': { state = 4; break; }
		case ']': { state = 4; break; }
		case '+': { state = 4; break; }
		case '-': { state = 4; break; }
		case '/': { state = 4; break; }
		case '*': { state = 4; break; }
		case '=': { state = 4; break; }
		case '#': { state = 4; break; }
		case '&': { state = 4; break; }
		case '|': { state = 4; break; }

				// Разделители
		case ' ': { state = 5; break; }
		case ':': { state = 5; break; }
		case ';': { state = 5; break; }
		case '{': { state = 5; break; }
		case '}': { state = 5; break; }
		case '(': { state = 5; break; }
		case ')': { state = 5; break; }
		case '\n': { state = 5; break; }
		case '\0': { state = 5; break; }

				 // Строки
		case '\'': { state = 6; break; }
		case '\"': { state = 6; break; }

		default: { state = 0; break; }
		} break;
	}
	case 1: {
		switch (c) {
		case '8': { state = 42; break; }
		case '1': { state = 44; break; }
		case '3': { state = 46; break; }
		case 'e': { state = 59; break; }
		case 'i': { state = 64; break; }
		case 'u': { state = 89; break; }

		case '_': { state = 19; break; }
		//case '_': { state = 67; break; }
		//case '_': { state = 162; break; }
		//case '_': { state = 176; break; }
		//case '_': { state = 242; break; }
		//case '_': { state = 334; break; }
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
		case 'e': { state = 9; break; }
		case 'E': { state = 9; break; }
		case '.': { state = 8; break; }
		default: { state = 0; break; }
		} break;
	}
	case 3: {
		switch (c) {
		case '=': { state = 7; break; }
		case '>': { state = 7; break; }
		case '<': { state = 7; break; }
		default: { state = 0; break; }
		} break;
	}
	case 4: {
		switch (c) {
		case '=': { state = 7; break; }
		case '+': { state = 7; break; }
		case '-': { state = 7; break; }
		case '>': { state = 7; break; }
		case '&': { state = 7; break; }
		case '|': { state = 7; break; }
		default: { state = 0; break; }
		} break;
	}
	case 5: {
		switch (c) {
		case ':': { state = 7; break; }
		default: { state = 0; break; }
		} break;
	}
	case 6: {
		switch (c) {
		case '\"': { state = 2; break; }
		case '\'': { state = 2; break; }
		default: { state = 6; break; }
		} break;
	}
	case 7: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 8: {
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
	case 9: {
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
		case '-': { state = 10; break; }
		case '+': { state = 10; break; }
		default: { state = 0; break; }
		} break;
	}
	case 10: {
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
	case 11: {
		switch (c) {
		case 'l': { state = 12; break; }
		case 'n': { state = 18; break; }
		case 's': { state = 21; break; }
		case 'u': { state = 22; break; }
		default: { state = 0; break; }
		} break;
	}
	case 12: {
		switch (c) {
		case 'i': { state = 13; break; }
		default: { state = 0; break; }
		} break;
	}
	case 13: {
		switch (c) {
		case 'g': { state = 14; break; }
		default: { state = 0; break; }
		} break;
	}
	case 14: {
		switch (c) {
		case 'n': { state = 15; break; }
		default: { state = 0; break; }
		} break;
	}
	case 15: {
		switch (c) {
		case 'a': { state = 16; break; }
		case 'o': { state = 17; break; }
		default: { state = 0; break; }
		} break;
	}
	case 16: {
		switch (c) {
		case 's': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 17: {
		switch (c) {
		case 'f': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 18: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 19: {
		switch (c) {
		case 'e': { state = 20; break; }
		default: { state = 0; break; }
		} break;
	}
	case 20: {
		switch (c) {
		case 'q': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 21: {
		switch (c) {
		case 'm': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 22: {
		switch (c) {
		case 't': { state = 23; break; }
		default: { state = 0; break; }
		} break;
	}
	case 23: {
		switch (c) {
		case 'o': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 24: {
		switch (c) {
		case 'i': { state = 25; break; }
		case 'o': { state = 30; break; }
		case 'r': { state = 32; break; }
		default: { state = 0; break; }
		} break;
	}
	case 25: {
		switch (c) {
		case 't': { state = 26; break; }
		default: { state = 0; break; }
		} break;
	}
	case 26: {
		switch (c) {
		case 'a': { state = 27; break; }
		case 'o': { state = 29; break; }
		default: { state = 0; break; }
		} break;
	}
	case 27: {
		switch (c) {
		case 'n': { state = 28; break; }
		default: { state = 0; break; }
		} break;
	}
	case 28: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 29: {
		switch (c) {
		case 'r': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 30: {
		switch (c) {
		case 'o': { state = 31; break; }
		default: { state = 0; break; }
		} break;
	}
	case 31: {
		switch (c) {
		case 'l': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 32: {
		switch (c) {
		case 'e': { state = 33; break; }
		default: { state = 0; break; }
		} break;
	}
	case 33: {
		switch (c) {
		case 'a': { state = 34; break; }
		default: { state = 0; break; }
		} break;
	}
	case 34: {
		switch (c) {
		case 'k': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 35: {
		switch (c) {
		case 'a': { state = 36; break; }
		case 'h': { state = 40; break; }
		case 'l': { state = 48; break; }
		case 'o': { state = 51; break; }
		default: { state = 0; break; }
		} break;
	}
	case 36: {
		switch (c) {
		case 's': { state = 37; break; }
		case 't': { state = 38; break; }
		default: { state = 0; break; }
		} break;
	}
	case 37: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 38: {
		switch (c) {
		case 'c': { state = 39; break; }
		default: { state = 0; break; }
		} break;
	}
	case 39: {
		switch (c) {
		case 'h': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 40: {
		switch (c) {
		case 'a': { state = 41; break; }
		default: { state = 0; break; }
		} break;
	}
	case 41: {
		switch (c) {
		case 'r': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 42: {
		switch (c) {
		case '_': { state = 43; break; }
		default: { state = 0; break; }
		} break;
	}
	case 43: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 44: {
		switch (c) {
		case '6': { state = 45; break; }
		default: { state = 0; break; }
		} break;
	}
	case 45: {
		switch (c) {
		case '_': { state = 43; break; }
		default: { state = 0; break; }
		} break;
	}
	case 46: {
		switch (c) {
		case '2': { state = 47; break; }
		default: { state = 0; break; }
		} break;
	}
	case 47: {
		switch (c) {
		case '_': { state = 43; break; }
		default: { state = 0; break; }
		} break;
	}
	case 48: {
		switch (c) {
		case 'a': { state = 49; break; }
		default: { state = 0; break; }
		} break;
	}
	case 49: {
		switch (c) {
		case 's': { state = 50; break; }
		default: { state = 0; break; }
		} break;
	}
	case 50: {
		switch (c) {
		case 's': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 51: {
		switch (c) {
		case 'm': { state = 52; break; }
		case 'n': { state = 54; break; }
		default: { state = 0; break; }
		} break;
	}
	case 52: {
		switch (c) {
		case 'p': { state = 53; break; }
		default: { state = 0; break; }
		} break;
	}
	case 53: {
		switch (c) {
		case 'l': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 54: {
		switch (c) {
		case 'c': { state = 55; break; }
		case 's': { state = 58; break; }
		case 't': { state = 71; break; }
		default: { state = 0; break; }
		} break;
	}
	case 55: {
		switch (c) {
		case 'e': { state = 56; break; }
		default: { state = 0; break; }
		} break;
	}
	case 56: {
		switch (c) {
		case 'p': { state = 57; break; }
		default: { state = 0; break; }
		} break;
	}
	case 57: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 58: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 59: {
		switch (c) {
		case 'v': { state = 60; break; }
		case 'x': { state = 62; break; }
		default: { state = 0; break; }
		} break;
	}
	case 60: {
		switch (c) {
		case 'a': { state = 61; break; }
		default: { state = 0; break; }
		} break;
	}
	case 61: {
		switch (c) {
		case 'l': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 62: {
		switch (c) {
		case 'p': { state = 63; break; }
		default: { state = 0; break; }
		} break;
	}
	case 63: {
		switch (c) {
		case 'r': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 64: {
		switch (c) {
		case 'n': { state = 65; break; }
		default: { state = 0; break; }
		} break;
	}
	case 65: {
		switch (c) {
		case 'i': { state = 66; break; }
		default: { state = 0; break; }
		} break;
	}
	case 66: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 67: {
		switch (c) {
		case 'c': { state = 68; break; }
		default: { state = 0; break; }
		} break;
	}
	case 68: {
		switch (c) {
		case 'a': { state = 69; break; }
		default: { state = 0; break; }
		} break;
	}
	case 69: {
		switch (c) {
		case 's': { state = 70; break; }
		default: { state = 0; break; }
		} break;
	}
	case 70: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 71: {
		switch (c) {
		case 'i': { state = 72; break; }
		default: { state = 0; break; }
		} break;
	}
	case 72: {
		switch (c) {
		case 'n': { state = 73; break; }
		default: { state = 0; break; }
		} break;
	}
	case 73: {
		switch (c) {
		case 'u': { state = 74; break; }
		default: { state = 0; break; }
		} break;
	}
	case 74: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 75: {
		switch (c) {
		case 'e': { state = 76; break; }
		case 'o': { state = 1; break; }
		case 'y': { state = 92; break; }
		default: { state = 0; break; }
		} break;
	}
	case 76: {
		switch (c) {
		case 'c': { state = 77; break; }
		case 'f': { state = 82; break; }
		case 'l': { state = 86; break; }
		default: { state = 0; break; }
		} break;
	}
	case 77: {
		switch (c) {
		case 'l': { state = 78; break; }
		default: { state = 0; break; }
		} break;
	}
	case 78: {
		switch (c) {
		case 't': { state = 79; break; }
		default: { state = 0; break; }
		} break;
	}
	case 79: {
		switch (c) {
		case 'y': { state = 80; break; }
		default: { state = 0; break; }
		} break;
	}
	case 80: {
		switch (c) {
		case 'p': { state = 81; break; }
		default: { state = 0; break; }
		} break;
	}
	case 81: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 82: {
		switch (c) {
		case 'a': { state = 83; break; }
		default: { state = 0; break; }
		} break;
	}
	case 83: {
		switch (c) {
		case 'u': { state = 84; break; }
		default: { state = 0; break; }
		} break;
	}
	case 84: {
		switch (c) {
		case 'l': { state = 85; break; }
		default: { state = 0; break; }
		} break;
	}
	case 85: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 86: {
		switch (c) {
		case 'e': { state = 87; break; }
		default: { state = 0; break; }
		} break;
	}
	case 87: {
		switch (c) {
		case 't': { state = 88; break; }
		default: { state = 0; break; }
		} break;
	}
	case 88: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 89: {
		switch (c) {
		case 'b': { state = 90; break; }
		default: { state = 0; break; }
		} break;
	}
	case 90: {
		switch (c) {
		case 'l': { state = 91; break; }
		default: { state = 0; break; }
		} break;
	}
	case 91: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 92: {
		switch (c) {
		case 'n': { state = 93; break; }
		default: { state = 0; break; }
		} break;
	}
	case 93: {
		switch (c) {
		case 'a': { state = 94; break; }
		default: { state = 0; break; }
		} break;
	}
	case 94: {
		switch (c) {
		case 'm': { state = 95; break; }
		default: { state = 0; break; }
		} break;
	}
	case 95: {
		switch (c) {
		case 'i': { state = 96; break; }
		default: { state = 0; break; }
		} break;
	}
	case 96: {
		switch (c) {
		case 'c': { state = 97; break; }
		default: { state = 0; break; }
		} break;
	}
	case 97: {
		switch (c) {
		case '_': { state = 98; break; }
		default: { state = 0; break; }
		} break;
	}
	case 98: {
		switch (c) {
		case 'c': { state = 99; break; }
		default: { state = 0; break; }
		} break;
	}
	case 99: {
		switch (c) {
		case 'a': { state = 100; break; }
		default: { state = 0; break; }
		} break;
	}
	case 100: {
		switch (c) {
		case 's': { state = 101; break; }
		default: { state = 0; break; }
		} break;
	}
	case 101: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 102: {
		switch (c) {
		case 'l': { state = 103; break; }
		case 'n': { state = 105; break; }
		case 'x': { state = 107; break; }
		default: { state = 0; break; }
		} break;
	}
	case 103: {
		switch (c) {
		case 's': { state = 104; break; }
		default: { state = 0; break; }
		} break;
	}
	case 104: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 105: {
		switch (c) {
		case 'u': { state = 106; break; }
		default: { state = 0; break; }
		} break;
	}
	case 106: {
		switch (c) {
		case 'm': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 107: {
		switch (c) {
		case 'p': { state = 108; break; }
		case 't': { state = 115; break; }
		default: { state = 0; break; }
		} break;
	}
	case 108: {
		switch (c) {
		case 'l': { state = 109; break; }
		case 'o': { state = 113; break; }
		default: { state = 0; break; }
		} break;
	}
	case 109: {
		switch (c) {
		case 'i': { state = 110; break; }
		default: { state = 0; break; }
		} break;
	}
	case 110: {
		switch (c) {
		case 'c': { state = 111; break; }
		default: { state = 0; break; }
		} break;
	}
	case 111: {
		switch (c) {
		case 'i': { state = 112; break; }
		default: { state = 0; break; }
		} break;
	}
	case 112: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 113: {
		switch (c) {
		case 'r': { state = 114; break; }
		default: { state = 0; break; }
		} break;
	}
	case 114: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 115: {
		switch (c) {
		case 'e': { state = 116; break; }
		default: { state = 0; break; }
		} break;
	}
	case 116: {
		switch (c) {
		case 'r': { state = 117; break; }
		default: { state = 0; break; }
		} break;
	}
	case 117: {
		switch (c) {
		case 'n': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 118: {
		switch (c) {
		case 'a': { state = 119; break; }
		case 'l': { state = 122; break; }
		case 'o': { state = 125; break; }
		case 'r': { state = 126; break; }
		default: { state = 0; break; }
		} break;
	}
	case 119: {
		switch (c) {
		case 'l': { state = 120; break; }
		default: { state = 0; break; }
		} break;
	}
	case 120: {
		switch (c) {
		case 's': { state = 121; break; }
		default: { state = 0; break; }
		} break;
	}
	case 121: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 122: {
		switch (c) {
		case 'o': { state = 123; break; }
		default: { state = 0; break; }
		} break;
	}
	case 123: {
		switch (c) {
		case 'a': { state = 124; break; }
		default: { state = 0; break; }
		} break;
	}
	case 124: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 125: {
		switch (c) {
		case 'r': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 126: {
		switch (c) {
		case 'i': { state = 127; break; }
		default: { state = 0; break; }
		} break;
	}
	case 127: {
		switch (c) {
		case 'e': { state = 128; break; }
		default: { state = 0; break; }
		} break;
	}
	case 128: {
		switch (c) {
		case 'n': { state = 129; break; }
		default: { state = 0; break; }
		} break;
	}
	case 129: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 130: {
		switch (c) {
		case 'o': { state = 131; break; }
		default: { state = 0; break; }
		} break;
	}
	case 131: {
		switch (c) {
		case 't': { state = 132; break; }
		default: { state = 0; break; }
		} break;
	}
	case 132: {
		switch (c) {
		case 'o': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 133: {
		switch (c) {
		case 'f': { state = 1; break; }
		case 'n': { state = 134; break; }
		default: { state = 0; break; }
		} break;
	}
	case 134: {
		switch (c) {
		case 'l': { state = 135; break; }
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 135: {
		switch (c) {
		case 'i': { state = 136; break; }
		default: { state = 0; break; }
		} break;
	}
	case 136: {
		switch (c) {
		case 'n': { state = 137; break; }
		default: { state = 0; break; }
		} break;
	}
	case 137: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 138: {
		switch (c) {
		case 'o': { state = 139; break; }
		default: { state = 0; break; }
		} break;
	}
	case 139: {
		switch (c) {
		case 'n': { state = 140; break; }
		default: { state = 0; break; }
		} break;
	}
	case 140: {
		switch (c) {
		case 'g': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 141: {
		switch (c) {
		case 'u': { state = 142; break; }
		default: { state = 0; break; }
		} break;
	}
	case 142: {
		switch (c) {
		case 't': { state = 143; break; }
		default: { state = 0; break; }
		} break;
	}
	case 143: {
		switch (c) {
		case 'a': { state = 144; break; }
		default: { state = 0; break; }
		} break;
	}
	case 144: {
		switch (c) {
		case 'b': { state = 145; break; }
		default: { state = 0; break; }
		} break;
	}
	case 145: {
		switch (c) {
		case 'l': { state = 146; break; }
		default: { state = 0; break; }
		} break;
	}
	case 146: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 147: {
		switch (c) {
		case 'a': { state = 148; break; }
		case 'e': { state = 155; break; }
		case 'o': { state = 156; break; }
		case 'u': { state = 164; break; }
		default: { state = 0; break; }
		} break;
	}
	case 148: {
		switch (c) {
		case 'm': { state = 149; break; }
		default: { state = 0; break; }
		} break;
	}
	case 149: {
		switch (c) {
		case 'e': { state = 150; break; }
		default: { state = 0; break; }
		} break;
	}
	case 150: {
		switch (c) {
		case 's': { state = 151; break; }
		default: { state = 0; break; }
		} break;
	}
	case 151: {
		switch (c) {
		case 'p': { state = 152; break; }
		default: { state = 0; break; }
		} break;
	}
	case 152: {
		switch (c) {
		case 'a': { state = 153; break; }
		default: { state = 0; break; }
		} break;
	}
	case 153: {
		switch (c) {
		case 'c': { state = 154; break; }
		default: { state = 0; break; }
		} break;
	}
	case 154: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 155: {
		switch (c) {
		case 'w': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 156: {
		switch (c) {
		case 'e': { state = 157; break; }
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 157: {
		switch (c) {
		case 'x': { state = 158; break; }
		default: { state = 0; break; }
		} break;
	}
	case 158: {
		switch (c) {
		case 'c': { state = 159; break; }
		default: { state = 0; break; }
		} break;
	}
	case 159: {
		switch (c) {
		case 'e': { state = 160; break; }
		default: { state = 0; break; }
		} break;
	}
	case 160: {
		switch (c) {
		case 'p': { state = 161; break; }
		default: { state = 0; break; }
		} break;
	}
	case 161: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 162: {
		switch (c) {
		case 'e': { state = 163; break; }
		default: { state = 0; break; }
		} break;
	}
	case 163: {
		switch (c) {
		case 'q': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 164: {
		switch (c) {
		case 'l': { state = 165; break; }
		default: { state = 0; break; }
		} break;
	}
	case 165: {
		switch (c) {
		case 'l': { state = 166; break; }
		default: { state = 0; break; }
		} break;
	}
	case 166: {
		switch (c) {
		case 'p': { state = 167; break; }
		default: { state = 0; break; }
		} break;
	}
	case 167: {
		switch (c) {
		case 't': { state = 168; break; }
		default: { state = 0; break; }
		} break;
	}
	case 168: {
		switch (c) {
		case 'r': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 169: {
		switch (c) {
		case 'p': { state = 170; break; }
		case 'r': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 170: {
		switch (c) {
		case 'e': { state = 171; break; }
		default: { state = 0; break; }
		} break;
	}
	case 171: {
		switch (c) {
		case 'r': { state = 172; break; }
		default: { state = 0; break; }
		} break;
	}
	case 172: {
		switch (c) {
		case 'a': { state = 173; break; }
		default: { state = 0; break; }
		} break;
	}
	case 173: {
		switch (c) {
		case 't': { state = 174; break; }
		default: { state = 0; break; }
		} break;
	}
	case 174: {
		switch (c) {
		case 'o': { state = 175; break; }
		default: { state = 0; break; }
		} break;
	}
	case 175: {
		switch (c) {
		case 'r': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 176: {
		switch (c) {
		case 'e': { state = 177; break; }
		default: { state = 0; break; }
		} break;
	}
	case 177: {
		switch (c) {
		case 'q': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 178: {
		switch (c) {
		case 'r': { state = 179; break; }
		case 'u': { state = 190; break; }
		default: { state = 0; break; }
		} break;
	}
	case 179: {
		switch (c) {
		case 'i': { state = 180; break; }
		case 'o': { state = 184; break; }
		default: { state = 0; break; }
		} break;
	}
	case 180: {
		switch (c) {
		case 'v': { state = 181; break; }
		default: { state = 0; break; }
		} break;
	}
	case 181: {
		switch (c) {
		case 'a': { state = 182; break; }
		default: { state = 0; break; }
		} break;
	}
	case 182: {
		switch (c) {
		case 't': { state = 183; break; }
		default: { state = 0; break; }
		} break;
	}
	case 183: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 184: {
		switch (c) {
		case 't': { state = 185; break; }
		default: { state = 0; break; }
		} break;
	}
	case 185: {
		switch (c) {
		case 'e': { state = 186; break; }
		default: { state = 0; break; }
		} break;
	}
	case 186: {
		switch (c) {
		case 'c': { state = 187; break; }
		default: { state = 0; break; }
		} break;
	}
	case 187: {
		switch (c) {
		case 't': { state = 188; break; }
		default: { state = 0; break; }
		} break;
	}
	case 188: {
		switch (c) {
		case 'e': { state = 189; break; }
		default: { state = 0; break; }
		} break;
	}
	case 189: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 190: {
		switch (c) {
		case 'b': { state = 191; break; }
		default: { state = 0; break; }
		} break;
	}
	case 191: {
		switch (c) {
		case 'l': { state = 192; break; }
		default: { state = 0; break; }
		} break;
	}
	case 192: {
		switch (c) {
		case 'i': { state = 193; break; }
		default: { state = 0; break; }
		} break;
	}
	case 193: {
		switch (c) {
		case 'c': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 194: {
		switch (c) {
		case 'e': { state = 195; break; }
		default: { state = 0; break; }
		} break;
	}
	case 195: {
		switch (c) {
		case 'f': { state = 196; break; }
		case 'g': { state = 201; break; }
		case 'i': { state = 206; break; }
		case 'q': { state = 219; break; }
		case 't': { state = 224; break; }
		default: { state = 0; break; }
		} break;
	}
	case 196: {
		switch (c) {
		case 'l': { state = 197; break; }
		default: { state = 0; break; }
		} break;
	}
	case 197: {
		switch (c) {
		case 'e': { state = 198; break; }
		default: { state = 0; break; }
		} break;
	}
	case 198: {
		switch (c) {
		case 'x': { state = 199; break; }
		default: { state = 0; break; }
		} break;
	}
	case 199: {
		switch (c) {
		case 'p': { state = 200; break; }
		default: { state = 0; break; }
		} break;
	}
	case 200: {
		switch (c) {
		case 'r': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 201: {
		switch (c) {
		case 'i': { state = 202; break; }
		default: { state = 0; break; }
		} break;
	}
	case 202: {
		switch (c) {
		case 's': { state = 203; break; }
		default: { state = 0; break; }
		} break;
	}
	case 203: {
		switch (c) {
		case 't': { state = 204; break; }
		default: { state = 0; break; }
		} break;
	}
	case 204: {
		switch (c) {
		case 'e': { state = 205; break; }
		default: { state = 0; break; }
		} break;
	}
	case 205: {
		switch (c) {
		case 'r': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 206: {
		switch (c) {
		case 'n': { state = 207; break; }
		default: { state = 0; break; }
		} break;
	}
	case 207: {
		switch (c) {
		case 't': { state = 208; break; }
		default: { state = 0; break; }
		} break;
	}
	case 208: {
		switch (c) {
		case 'e': { state = 209; break; }
		default: { state = 0; break; }
		} break;
	}
	case 209: {
		switch (c) {
		case 'r': { state = 210; break; }
		default: { state = 0; break; }
		} break;
	}
	case 210: {
		switch (c) {
		case 'p': { state = 211; break; }
		default: { state = 0; break; }
		} break;
	}
	case 211: {
		switch (c) {
		case 'r': { state = 212; break; }
		default: { state = 0; break; }
		} break;
	}
	case 212: {
		switch (c) {
		case 'e': { state = 213; break; }
		default: { state = 0; break; }
		} break;
	}
	case 213: {
		switch (c) {
		case 't': { state = 214; break; }
		default: { state = 0; break; }
		} break;
	}
	case 214: {
		switch (c) {
		case '_': { state = 215; break; }
		default: { state = 0; break; }
		} break;
	}
	case 215: {
		switch (c) {
		case 'c': { state = 216; break; }
		default: { state = 0; break; }
		} break;
	}
	case 216: {
		switch (c) {
		case 'a': { state = 217; break; }
		default: { state = 0; break; }
		} break;
	}
	case 217: {
		switch (c) {
		case 's': { state = 218; break; }
		default: { state = 0; break; }
		} break;
	}
	case 218: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 219: {
		switch (c) {
		case 'u': { state = 220; break; }
		default: { state = 0; break; }
		} break;
	}
	case 220: {
		switch (c) {
		case 'i': { state = 221; break; }
		default: { state = 0; break; }
		} break;
	}
	case 221: {
		switch (c) {
		case 'r': { state = 222; break; }
		default: { state = 0; break; }
		} break;
	}
	case 222: {
		switch (c) {
		case 'e': { state = 223; break; }
		default: { state = 0; break; }
		} break;
	}
	case 223: {
		switch (c) {
		case 's': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 224: {
		switch (c) {
		case 'u': { state = 225; break; }
		default: { state = 0; break; }
		} break;
	}
	case 225: {
		switch (c) {
		case 'r': { state = 226; break; }
		default: { state = 0; break; }
		} break;
	}
	case 226: {
		switch (c) {
		case 'n': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 227: {
		switch (c) {
		case 'h': { state = 228; break; }
		case 'i': { state = 231; break; }
		case 't': { state = 238; break; }
		case 'w': { state = 254; break; }
		case 'y': { state = 258; break; }
		default: { state = 0; break; }
		} break;
		}
	case 228: {
		switch (c) {
		case 'o': { state = 229; break; }
		default: { state = 0; break; }
		} break;
	}
	case 229: {
		switch (c) {
		case 'r': { state = 230; break; }
		default: { state = 0; break; }
		} break;
	}
	case 230: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 231: {
		switch (c) {
		case 'g': { state = 232; break; }
		case 'z': { state = 235; break; }
		default: { state = 0; break; }
		} break;
	}
	case 232: {
		switch (c) {
		case 'n': { state = 233; break; }
		default: { state = 0; break; }
		} break;
	}
	case 233: {
		switch (c) {
		case 'e': { state = 234; break; }
		default: { state = 0; break; }
		} break;
	}
	case 234: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 235: {
		switch (c) {
		case 'e': { state = 236; break; }
		default: { state = 0; break; }
		} break;
	}
	case 236: {
		switch (c) {
		case 'o': { state = 237; break; }
		default: { state = 0; break; }
		} break;
	}
	case 237: {
		switch (c) {
		case 'f': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 238: {
		switch (c) {
		case 'a': { state = 239; break; }
		case 'r': { state = 251; break; }
		default: { state = 0; break; }
		} break;
	}
	case 239: {
		switch (c) {
		case 't': { state = 240; break; }
		default: { state = 0; break; }
		} break;
	}
	case 240: {
		switch (c) {
		case 'i': { state = 241; break; }
		default: { state = 0; break; }
		} break;
	}
	case 241: {
		switch (c) {
		case 'c': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 242: {
		switch (c) {
		case 'a': { state = 243; break; }
		case 'c': { state = 248; break; }
		default: { state = 0; break; }
		} break;
	}
	case 243: {
		switch (c) {
		case 's': { state = 244; break; }
		default: { state = 0; break; }
		} break;
	}
	case 244: {
		switch (c) {
		case 's': { state = 245; break; }
		default: { state = 0; break; }
		} break;
	}
	case 245: {
		switch (c) {
		case 'e': { state = 246; break; }
		default: { state = 0; break; }
		} break;
	}
	case 246: {
		switch (c) {
		case 'r': { state = 247; break; }
		default: { state = 0; break; }
		} break;
	}
	case 247: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 248: {
		switch (c) {
		case 'a': { state = 249; break; }
		default: { state = 0; break; }
		} break;
	}
	case 249: {
		switch (c) {
		case 's': { state = 250; break; }
		default: { state = 0; break; }
		} break;
	}
	case 250: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 251: {
		switch (c) {
		case 'u': { state = 252; break; }
		default: { state = 0; break; }
		} break;
	}
	case 252: {
		switch (c) {
		case 'c': { state = 253; break; }
		default: { state = 0; break; }
		} break;
	}
	case 253: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 254: {
		switch (c) {
		case 'i': { state = 255; break; }
		default: { state = 0; break; }
		} break;
	}
	case 255: {
		switch (c) {
		case 't': { state = 256; break; }
		default: { state = 0; break; }
		} break;
	}
	case 256: {
		switch (c) {
		case 'c': { state = 257; break; }
		default: { state = 0; break; }
		} break;
	}
	case 257: {
		switch (c) {
		case 'h': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 258: {
		switch (c) {
		case 'n': { state = 259; break; }
		default: { state = 0; break; }
		} break;
	}
	case 259: {
		switch (c) {
		case 'c': { state = 260; break; }
		default: { state = 0; break; }
		} break;
	}
	case 260: {
		switch (c) {
		case 'h': { state = 261; break; }
		default: { state = 0; break; }
		} break;
	}
	case 261: {
		switch (c) {
		case 'r': { state = 262; break; }
		default: { state = 0; break; }
		} break;
	}
	case 262: {
		switch (c) {
		case 'o': { state = 263; break; }
		default: { state = 0; break; }
		} break;
	}
	case 263: {
		switch (c) {
		case 'n': { state = 264; break; }
		default: { state = 0; break; }
		} break;
	}
	case 264: {
		switch (c) {
		case 'i': { state = 265; break; }
		default: { state = 0; break; }
		} break;
	}
	case 265: {
		switch (c) {
		case 'z': { state = 266; break; }
		default: { state = 0; break; }
		} break;
	}
	case 266: {
		switch (c) {
		case 'e': { state = 267; break; }
		default: { state = 0; break; }
		} break;
	}
	case 267: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 268: {
		switch (c) {
		case 'e': { state = 269; break; }
		case 'h': { state = 275; break; }
		case 'r': { state = 287; break; }
		case 'y': { state = 289; break; }
		default: { state = 0; break; }
		} break;
	}
	case 269: {
		switch (c) {
		case 'm': { state = 270; break; }
		default: { state = 0; break; }
		} break;
	}
	case 270: {
		switch (c) {
		case 'p': { state = 271; break; }
		default: { state = 0; break; }
		} break;
	}
	case 271: {
		switch (c) {
		case 'l': { state = 272; break; }
		default: { state = 0; break; }
		} break;
	}
	case 272: {
		switch (c) {
		case 'a': { state = 273; break; }
		default: { state = 0; break; }
		} break;
	}
	case 273: {
		switch (c) {
		case 't': { state = 274; break; }
		default: { state = 0; break; }
		} break;
	}
	case 274: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 275: {
		switch (c) {
		case 'i': { state = 276; break; }
		case 'r': { state = 277; break; }
		default: { state = 0; break; }
		} break;
	}
	case 276: {
		switch (c) {
		case 's': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 277: {
		switch (c) {
		case 'e': { state = 278; break; }
		case 'o': { state = 286; break; }
		default: { state = 0; break; }
		} break;
	}
	case 278: {
		switch (c) {
		case 'a': { state = 279; break; }
		default: { state = 0; break; }
		} break;
	}
	case 279: {
		switch (c) {
		case 's': { state = 280; break; }
		default: { state = 0; break; }
		} break;
	}
	case 280: {
		switch (c) {
		case '_': { state = 281; break; }
		default: { state = 0; break; }
		} break;
	}
	case 281: {
		switch (c) {
		case 'l': { state = 282; break; }
		default: { state = 0; break; }
		} break;
	}
	case 282: {
		switch (c) {
		case 'o': { state = 283; break; }
		default: { state = 0; break; }
		} break;
	}
	case 283: {
		switch (c) {
		case 'c': { state = 284; break; }
		default: { state = 0; break; }
		} break;
	}
	case 284: {
		switch (c) {
		case 'a': { state = 285; break; }
		default: { state = 0; break; }
		} break;
	}
	case 285: {
		switch (c) {
		case 'l': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 286: {
		switch (c) {
		case 'w': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 287: {
		switch (c) {
		case 'u': { state = 288; break; }
		case 'y': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 288: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 289: {
		switch (c) {
		case 'p': { state = 290; break; }
		default: { state = 0; break; }
		} break;
	}
	case 290: {
		switch (c) {
		case 'e': { state = 291; break; }
		default: { state = 0; break; }
		} break;
	}
	case 291: {
		switch (c) {
		case 'd': { state = 292; break; }
		case 'i': { state = 294; break; }
		case 'n': { state = 295; break; }
		default: { state = 0; break; }
		} break;
	}
	case 292: {
		switch (c) {
		case 'e': { state = 293; break; }
		default: { state = 0; break; }
		} break;
	}
	case 293: {
		switch (c) {
		case 'f': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 294: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 295: {
		switch (c) {
		case 'a': { state = 296; break; }
		default: { state = 0; break; }
		} break;
	}
	case 296: {
		switch (c) {
		case 'm': { state = 297; break; }
		default: { state = 0; break; }
		} break;
	}
	case 297: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 298: {
		switch (c) {
		case 'n': { state = 299; break; }
		case 's': { state = 307; break; }
		default: { state = 0; break; }
		} break;
	}
	case 299: {
		switch (c) {
		case 'i': { state = 300; break; }
		case 's': { state = 302; break; }
		default: { state = 0; break; }
		} break;
	}
	case 300: {
		switch (c) {
		case 'o': { state = 301; break; }
		default: { state = 0; break; }
		} break;
	}
	case 301: {
		switch (c) {
		case 'n': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 302: {
		switch (c) {
		case 'i': { state = 303; break; }
		default: { state = 0; break; }
		} break;
	}
	case 303: {
		switch (c) {
		case 'g': { state = 304; break; }
		default: { state = 0; break; }
		} break;
	}
	case 304: {
		switch (c) {
		case 'n': { state = 305; break; }
		default: { state = 0; break; }
		} break;
	}
	case 305: {
		switch (c) {
		case 'e': { state = 306; break; }
		default: { state = 0; break; }
		} break;
	}
	case 306: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 307: {
		switch (c) {
		case 'i': { state = 308; break; }
		default: { state = 0; break; }
		} break;
	}
	case 308: {
		switch (c) {
		case 'n': { state = 309; break; }
		default: { state = 0; break; }
		} break;
	}
	case 309: {
		switch (c) {
		case 'g': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 310: {
		switch (c) {
		case 'i': { state = 311; break; }
		case 'o': { state = 316; break; }
		default: { state = 0; break; }
		} break;
	}
	case 311: {
		switch (c) {
		case 'r': { state = 312; break; }
		default: { state = 0; break; }
		} break;
	}
	case 312: {
		switch (c) {
		case 't': { state = 313; break; }
		default: { state = 0; break; }
		} break;
	}
	case 313: {
		switch (c) {
		case 'u': { state = 314; break; }
		default: { state = 0; break; }
		} break;
	}
	case 314: {
		switch (c) {
		case 'a': { state = 315; break; }
		default: { state = 0; break; }
		} break;
	}
	case 315: {
		switch (c) {
		case 'l': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 316: {
		switch (c) {
		case 'i': { state = 317; break; }
		case 'l': { state = 318; break; }
		default: { state = 0; break; }
		} break;
	}
	case 317: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 318: {
		switch (c) {
		case 'a': { state = 319; break; }
		default: { state = 0; break; }
		} break;
	}
	case 319: {
		switch (c) {
		case 't': { state = 320; break; }
		default: { state = 0; break; }
		} break;
	}
	case 320: {
		switch (c) {
		case 'i': { state = 321; break; }
		default: { state = 0; break; }
		} break;
	}
	case 321: {
		switch (c) {
		case 'l': { state = 322; break; }
		default: { state = 0; break; }
		} break;
	}
	case 322: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 323: {
		switch (c) {
		case 'c': { state = 324; break; }
		case 'h': { state = 329; break; }
		default: { state = 0; break; }
		} break;
	}
	case 324: {
		switch (c) {
		case 'h': { state = 325; break; }
		default: { state = 0; break; }
		} break;
	}
	case 325: {
		switch (c) {
		case 'a': { state = 326; break; }
		default: { state = 0; break; }
		} break;
	}
	case 326: {
		switch (c) {
		case 'r': { state = 327; break; }
		default: { state = 0; break; }
		} break;
	}
	case 327: {
		switch (c) {
		case '_': { state = 328; break; }
		default: { state = 0; break; }
		} break;
	}
	case 328: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 329: {
		switch (c) {
		case 'i': { state = 330; break; }
		default: { state = 0; break; }
		} break;
	}
	case 330: {
		switch (c) {
		case 'l': { state = 331; break; }
		default: { state = 0; break; }
		} break;
	}
	case 331: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 332: {
		switch (c) {
		case 'o': { state = 333; break; }
		default: { state = 0; break; }
		} break;
	}
	case 333: {
		switch (c) {
		case 'r': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 334: {
		switch (c) {
		case 'e': { state = 335; break; }
		default: { state = 0; break; }
		} break;
	}
	case 335: {
		switch (c) {
		case 'q': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	}

	buffer += c;

	// Лексемы
	if (state > 0 && state < 3 && (is_delim(next) || is_sign(next))) {
		if (state != 2 || next != '.')
			return buffer;
	}

	// Знаки
	if ((state == 3 || state == 4) && !is_sign(next)) {
		return buffer;
	}
	if (state == 7) {
		if (c == '=') state = 3;
		else state = 4;
		return buffer;
	}

	// Разделители
	if (state == 5) {
		return buffer;
	}

	// Идентификаторы
	if (buffer != "" && (state == 0 || state > 10) && (is_delim(next) || is_sign(next))) {
		state = -1; return buffer;
	}

	return "";
}

