#include <iostream>
#include <string>
#include <vector>
#include "l_analyser.h"

/*
* Метод, возвращающий является ли разделителем
* заданный символ
*/
bool Analyser::is_delim(char c) {
	/*if (check_next) {
		Analyser* checker = new Analyser();
		checker->check_next = false;
		checker->lexem_filter(c, c);
		int state = checker->state;
		delete checker;
		return state == 6;
	}
	return false;*/
	std::string delimers = " ,:;(){}'\"\n\0";
	return std::count(delimers.begin(), delimers.end(), c) > 0;
}

/*
* Метод, возвращающий является ли знаком
* заданный символ
*/
bool Analyser::is_sign(char c) {
	/*if (check_next) {
		Analyser* checker = new Analyser();
		checker->check_next = false;
		checker->lexem_filter(c, c);
		int state = checker->state;
		delete checker;
		return (state == 4 || state == 5);
	}
	return false;*/
	std::string signs = ".:[]<>+-/*=#&";
	return std::count(signs.begin(), signs.end(), c) > 0;
}
/*
* Метод, возвращающий входит ли следующий символ в валидную лексему
*/
bool Analyser::is_next_valid(char c) {
	if (check_next) {
		Analyser* checker = new Analyser(this);
		checker->check_next = false;
		checker->lexem_filter(c, c);
		int state = checker->state;
		delete checker;
		return state > 0 && state <= 6 && state != 3;
	}
	return true;
};

/*
* Метод, возвращающий является ли знаком
* заданный символ по состояниям
*/
bool Analyser::is_multisign() {
	std::vector<int> n_states = { 
		11, 13, 16, 21, 23, 25, 27, 
		29, 33, 37, 40, 43, 44, 46, 
		48, 49, 51, 52, 53
	};
	return std::count(n_states.begin(), n_states.end(), state) == 0;
}

Analyser::Analyser() {
	this->buffer = "";
	this->is_id = false;
	this->state = 0;
};

Analyser::Analyser(Analyser* copy) {
	this->buffer = copy->buffer;
	this->is_id = copy->is_id;
	this->state = copy->state;
	this->check_next = copy->check_next;
};

/*
* Метод, сбрасывающий состояние конечного автомата
*/
void Analyser::clearState() {
	this->state = 0;
	this->buffer = "";
	this->is_id = false;
}

/*
* Метод, возвращающий состояние конечного автомата
*/
int Analyser::getState() const {
	return this->state;
}
/*
* Метод, устанавливающий состояние конечного автомата
*/
void Analyser::setState(int state) {
	this->state = state;
};

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
		case 'a': { state = 61; break; }
		case 'b': { state = 64; break; }
		case 'c': { state = 70; break; }
		case 'd': { state = 78; break; }
		case 'e': { state = 86; break; }
		case 'f': { state = 89; break; }
		case 'i': { state = 94; break; }
		case 'p': { state = 96; break; }
		case 'r': { state = 106; break; }
		case 't': { state = 111; break; }
		case 'v': { state = 114; break; }

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
		case '<': { state = 29; break; }
		case '>': { state = 33; break; }

				// Знаки операций
		case '=': { state = 11; break; }
		case '+': { state = 13; break; }
		case '-': { state = 16; break; }
		case '*': { state = 21; break; }
		case '/': { state = 23; break; }
		case '%': { state = 25; break; }
		case '!': { state = 27; break; }
		case '&': { state = 37; break; }
		case '|': { state = 40; break; }
		case '~': { state = 43; break; }
		case '^': { state = 44; break; }
		case '.': { state = 46; break; }
		case ',': { state = 48; break; }
		case ':': { state = 49; break; }
		case '[': { state = 51; break; }
		case ']': { state = 52; break; }
		case '#': { state = 53; break; }

				// Разделители
		case ' ': { state = 6; break; }
		case ';': { state = 6; break; }
		case '{': { state = 6; break; }
		case '}': { state = 6; break; }
		case '(': { state = 6; break; }
		case ')': { state = 6; break; }
		case '\n': { state = 6; break; }

				 // Строки
		case '\'': { state = 7; break; }
		case '\"': { state = 8; break; }

		default: { state = 0; break; }
		} break;
	}
	case 1: { // Ключевые слова
		switch (c) {
		case 'u': { state = 79; break; }
		default: { state = 0; break; }
		} break;
	}
	case 2: { // Константы
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
		case 'e': { state = 4; break; }
		case 'E': { state = 4; break; }
		case '.': { state = 3; break; }
		default: { state = 0; break; }
		} break;
	}
	case 3: {
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
	case 4: {
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
		case '-': { state = 5; break; }
		case '+': { state = 5; break; }
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
		default: { state = 0; break; }
		} break;
	}
	case 6: { // Разделители
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 7: { // Строковый литерал ''
		switch (c) {
		case '\'': { state = 2; break; }
		default: { state = 7; break; }
		} break;
	}
	case 8: { // Строковый литерал ""
		switch (c) {
		case '\"': { state = 2; break; }
		default: { state = 8; break; }
		} break;
	}
	case 9: { // Не занято
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 10: { // Не занято
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 11: {
		switch (c) {
		case '=': { state = 12; break; }
		default: { state = 0; break; }
		} break;
	}
	case 12: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 13: {
		switch (c) {
		case '+': { state = 14; break; }
		case '=': { state = 15; break; }
		default: { state = 0; break; }
		} break;
	}
	case 14: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 15: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 16: {
		switch (c) {
		case '-': { state = 17; break; }
		case '=': { state = 18; break; }
		case '>': { state = 19; break; }
		default: { state = 0; break; }
		} break;
	}
	case 17: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 18: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 19: {
		switch (c) {
		case '*': { state = 20; break; }
		default: { state = 0; break; }
		} break;
	}
	case 20: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 21: {
		switch (c) {
		case '=': { state = 22; break; }
		default: { state = 0; break; }
		} break;
	}
	case 22: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 23: {
		switch (c) {
		case '=': { state = 24; break; }
		default: { state = 0; break; }
		} break;
	}
	case 24: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 25: {
		switch (c) {
		case '=': { state = 26; break; }
		default: { state = 0; break; }
		} break;
	}
	case 26: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 27: {
		switch (c) {
		case '=': { state = 28; break; }
		default: { state = 0; break; }
		} break;
	}
	case 28: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 29: {
		switch (c) {
		case '=': { state = 30; break; }
		case '<': { state = 31; break; }
		default: { state = 0; break; }
		} break;
	}
	case 30: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 31: {
		switch (c) {
		case '=': { state = 32; break; }
		default: { state = 0; break; }
		} break;
	}
	case 32: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 33: {
		switch (c) {
		case '=': { state = 34; break; }
		case '>': { state = 35; break; }
		default: { state = 0; break; }
		} break;
	}
	case 34: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 35: {
		switch (c) {
		case '=': { state = 36; break; }
		default: { state = 0; break; }
		} break;
	}
	case 36: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 37: {
		switch (c) {
		case '&': { state = 38; break; }
		case '=': { state = 38; break; }
		default: { state = 0; break; }
		} break;
	}
	case 38: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 39: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 40: {
		switch (c) {
		case '|': { state = 41; break; }
		case '=': { state = 42; break; }
		default: { state = 0; break; }
		} break;
	}
	case 41: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 42: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 43: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 44: {
		switch (c) {
		case '=': { state = 45; break; }
		default: { state = 0; break; }
		} break;
	}
	case 45: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 46: {
		switch (c) {
		case '*': { state = 47; break; }
		default: { state = 0; break; }
		} break;
	}
	case 47: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 48: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 49: {
		switch (c) {
		case ':': { state = 50; break; }
		default: { state = 0; break; }
		} break;
	}
	case 50: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 51: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 52: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 53: {
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 54: { // Не занято
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 55: { // Не занято
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 56: { // Не занято
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 57: { // Не занято
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 58: { // Не занято
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 59: { // Не занято
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 60: { // Не занято
		switch (c) {
		default: { state = 0; break; }
		} break;
	}
	case 61: {
		switch (c) {
		case 'u': { state = 62; break; }
		default: { state = 0; break; }
		} break;
	}
	case 62: {
		switch (c) {
		case 't': { state = 63; break; }
		default: { state = 0; break; }
		} break;
	}
	case 63: {
		switch (c) {
		case 'o': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 64: {
		switch (c) {
		case 'r': { state = 65; break; }
		case 'o': { state = 68; break; }
		default: { state = 0; break; }
		} break;
	}
	case 65: {
		switch (c) {
		case 'e': { state = 66; break; }
		default: { state = 0; break; }
		} break;
	}
	case 66: {
		switch (c) {
		case 'a': { state = 67; break; }
		default: { state = 0; break; }
		} break;
	}
	case 67: {
		switch (c) {
		case 'k': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 68: {
		switch (c) {
		case 'o': { state = 69; break; }
		default: { state = 0; break; }
		} break;
	}
	case 69: {
		switch (c) {
		case 'l': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 70: {
		switch (c) {
		case 'l': { state = 71; break; }
		case 'h': { state = 74; break; }
		case 'a': { state = 76; break; }
		default: { state = 0; break; }
		} break;
	}
	case 71: {
		switch (c) {
		case 'a': { state = 72; break; }
		default: { state = 0; break; }
		} break;
	}
	case 72: {
		switch (c) {
		case 's': { state = 73; break; }
		default: { state = 0; break; }
		} break;
	}
	case 73: {
		switch (c) {
		case 's': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 74: {
		switch (c) {
		case 'a': { state = 75; break; }
		default: { state = 0; break; }
		} break;
	}
	case 75: {
		switch (c) {
		case 'r': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 76: {
		switch (c) {
		case 's': { state = 77; break; }
		default: { state = 0; break; }
		} break;
	}
	case 77: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 78: {
		switch (c) {
		case 'o': { state = 1; break; }
		case 'e': { state = 82; break; }
		default: { state = 0; break; }
		} break;
	}
	case 79: {
		switch (c) {
		case 'b': { state = 80; break; }
		default: { state = 0; break; }
		} break;
	}
	case 80: {
		switch (c) {
		case 'l': { state = 81; break; }
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
		case 'l': { state = 83; break; }
		default: { state = 0; break; }
		} break;
	}
	case 83: {
		switch (c) {
		case 'e': { state = 84; break; }
		default: { state = 0; break; }
		} break;
	}
	case 84: {
		switch (c) {
		case 't': { state = 85; break; }
		default: { state = 0; break; }
		} break;
	}
	case 85: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 86: {
		switch (c) {
		case 'l': { state = 87; break; }
		default: { state = 0; break; }
		} break;
	}
	case 87: {
		switch (c) {
		case 's': { state = 88; break; }
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
		case 'a': { state = 90; break; }
		case 'o': { state = 93; break; }
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
		case 's': { state = 92; break; }
		default: { state = 0; break; }
		} break;
	}
	case 92: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 93: {
		switch (c) {
		case 'r': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 94: {
		switch (c) {
		case 'n': { state = 95; break; }
		case 'f': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 95: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 96: {
		switch (c) {
		case 'r': { state = 97; break; }
		case 'u': { state = 102; break; }
		default: { state = 0; break; }
		} break;
	}
	case 97: {
		switch (c) {
		case 'i': { state = 98; break; }
		default: { state = 0; break; }
		} break;
	}
	case 98: {
		switch (c) {
		case 'v': { state = 99; break; }
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
		case 't': { state = 101; break; }
		default: { state = 0; break; }
		} break;
	}
	case 101: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 102: {
		switch (c) {
		case 'b': { state = 103; break; }
		default: { state = 0; break; }
		} break;
	}
	case 103: {
		switch (c) {
		case 'l': { state = 104; break; }
		default: { state = 0; break; }
		} break;
	}
	case 104: {
		switch (c) {
		case 'i': { state = 105; break; }
		default: { state = 0; break; }
		} break;
	}
	case 105: {
		switch (c) {
		case 'c': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 106: {
		switch (c) {
		case 'e': { state = 107; break; }
		default: { state = 0; break; }
		} break;
	}
	case 107: {
		switch (c) {
		case 't': { state = 108; break; }
		default: { state = 0; break; }
		} break;
	}
	case 108: {
		switch (c) {
		case 'u': { state = 109; break; }
		default: { state = 0; break; }
		} break;
	}
	case 109: {
		switch (c) {
		case 'r': { state = 110; break; }
		default: { state = 0; break; }
		} break;
	}
	case 110: {
		switch (c) {
		case 'n': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 111: {
		switch (c) {
		case 'r': { state = 112; break; }
		default: { state = 0; break; }
		} break;
	}
	case 112: {
		switch (c) {
		case 'u': { state = 113; break; }
		default: { state = 0; break; }
		} break;
	}
	case 113: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 114: {
		switch (c) {
		case 'o': { state = 115; break; }
		default: { state = 0; break; }
		} break;
	}
	case 115: {
		switch (c) {
		case 'i': { state = 116; break; }
		default: { state = 0; break; }
		} break;
	}
	case 116: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	}

	buffer += c;

	if (state == 0)
		is_id = true; // Если автомат перешёл в состояние S=0, то вся лексема - иденификатор

	// Ключевые слова и константы
	if ((state == 1 || state == 2) && (is_delim(next) || is_sign(next)) && !is_id && c) {
		if (state != 2 || next != '.')
			return buffer;
	}

	// Знаки
	if ((state > 10 && state <= 60) && (!is_next_valid(next) || is_multisign()) && !is_id && c) {
		if ((state >= 28 && state <= 30) || (state >= 33 && state <= 34) || state == 12) {
			state = 4;
			return buffer;
		}
		state = 5;
		return buffer;
	}

	// Разделители
	if (state == 6) {
		return buffer;
	}

	// Идентификаторы
	if (buffer != "" && (is_id || state > 60) && (is_delim(next) || is_sign(next))) {
		state = 3; return buffer;
	}

	return "";
}

