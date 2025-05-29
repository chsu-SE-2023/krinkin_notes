#include <iostream>
#include <string>
#include <vector>
#include "l_analyser.h"

/**
* Метод, возвращающий является ли разделителем
* заданный символ
* 
* @param проверяемый символ
* @return результат проверки
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
* 
* @param проверяемый символ
* @return результат проверки
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
* Метод, возвращающий является ли специальным
* заданный символ
*
* @param проверяемый символ
* @return результат проверки
*/
bool Analyser::check_special(System::String^ string) {
	std::string signs = "!\"@#№$%:^?&*\\/|~`";
	for each (char c in string) {
		if (std::count(signs.begin(), signs.end(), c) > 0)
			return true;
	}
	return false;
}

/*
* Метод, возвращающий входит ли следующий символ в валидную лексему
* 
* @param проверяемый символ
* @return результат проверки
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
}

/*
* Метод, возвращающий является ли знаком
* заданный символ по состояниям
* 
* @return результат проверки
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
}

Analyser::Analyser(Analyser* copy) {
	this->buffer = copy->buffer;
	this->is_id = copy->is_id;
	this->state = copy->state;
	this->check_next = copy->check_next;
}

/**
* Метод, сбрасывающий состояние конечного автомата
*/
void Analyser::clear_state() {
	this->state = 0;
	this->buffer = "";
	this->is_id = false;
}

/**
* Метод, последнюю ошибку конечного автомата
*
* @return ошибка автомата
*/
std::string Analyser::get_error() {
	return this->error;
};

/**
* Метод, возвращающий состояние конечного автомата
* 
* @return состояние автомата
*/
int Analyser::get_state() const {
	return this->state;
}

/**
* Метод, устанавливающий состояние конечного автомата
* 
* @param состояние автомата
*/
void Analyser::set_state(int state) {
	this->state = state;
}

/**
* Метод, лексического анализатора для удаления
* пробелов, переносов, комментариев
* 
* @param символ из текста
* @param следующий символ из текста
* @return символ или -1, если символ не должен входить в конечный результат
*/
char Analyser::space_filter(char c, char next) {
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

/**
* Метод, лексического анализатора для разделения
* лексем и определения их типа
* 
* @param символ из текста
* @param следующий символ из текста
* @return лексема или пустая строка, если лексема не найдена
*/
std::string Analyser::lexem_filter(char c, char next) {
	switch (state) {
	case 0: {
		switch (c) { 
			// Ключевые слова
		case 'a': { state = 61; break; }
		case 'b': { state = 74; break; }
		case 'c': { state = 85; break; }
		case 'd': { state = 125; break; }
		case 'e': { state = 152; break; }
		case 'f': { state = 168; break; }
		case 'g': { state = 180; break; }
		case 'i': { state = 183; break; }
		case 'l': { state = 188; break; }
		case 'm': { state = 191; break; }
		case 'n': { state = 197; break; }
		case 'o': { state = 219; break; }
		case 'p': { state = 228; break; }
		case 'r': { state = 244; break; }
		case 's': { state = 277; break; }
		case 't': { state = 318; break; }
		case 'u': { state = 348; break; }
		case 'v': { state = 360; break; }
		case 'w': { state = 373; break; }
		case 'x': { state = 382; break; }

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
		case '_': { state = 69; break; }
		case '8': { state = 92; break; }
		case '1': { state = 94; break; }
		case '3': { state = 96; break; }
		case 'e': { state = 109; break; }
		case 'i': { state = 114; break; }
		//case '_': { state = 117; break; }
		//case 'u': { state = 139; break; }
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
		case '0': { state = 9; break; }
		case '1': { state = 9; break; }
		case '2': { state = 9; break; }
		case '3': { state = 9; break; }
		case '4': { state = 9; break; }
		case '5': { state = 9; break; }
		case '6': { state = 9; break; }
		case '7': { state = 9; break; }
		case '8': { state = 9; break; }
		case '9': { state = 9; break; }
		case '-': { state = 5; break; }
		case '+': { state = 5; break; }
		default: { state = 0; break; }
		} break;
	}
	case 5: {
		switch (c) {
		case '0': { state = 9; break; }
		case '1': { state = 9; break; }
		case '2': { state = 9; break; }
		case '3': { state = 9; break; }
		case '4': { state = 9; break; }
		case '5': { state = 9; break; }
		case '6': { state = 9; break; }
		case '7': { state = 9; break; }
		case '8': { state = 9; break; }
		case '9': { state = 9; break; }
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
	case 9: { //Константа вида xE-xx
		switch (c) {
		case '0': { state = 9; break; }
		case '1': { state = 9; break; }
		case '2': { state = 9; break; }
		case '3': { state = 9; break; }
		case '4': { state = 9; break; }
		case '5': { state = 9; break; }
		case '6': { state = 9; break; }
		case '7': { state = 9; break; }
		case '8': { state = 9; break; }
		case '9': { state = 9; break; }
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
		case 'l': { state = 62; break; }
		case 'n': { state = 68; break; }
		case 's': { state = 71; break; }
		case 'u': { state = 72; break; }
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
		case 'g': { state = 64; break; }
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
		case 'a': { state = 66; break; }
		case 'o': { state = 67; break; }
		default: { state = 0; break; }
		} break;
	}
	case 66: {
		switch (c) {
		case 's': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 67: {
		switch (c) {
		case 'f': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 68: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 69: {
		switch (c) {
		case 'e': { state = 70; break; }
		default: { state = 0; break; }
		} break;
	}
	case 70: {
		switch (c) {
		case 'q': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 71: {
		switch (c) {
		case 'm': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 72: {
		switch (c) {
		case 't': { state = 73; break; }
		default: { state = 0; break; }
		} break;
	}
	case 73: {
		switch (c) {
		case 'o': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 74: {
		switch (c) {
		case 'i': { state = 75; break; }
		case 'o': { state = 80; break; }
		case 'r': { state = 82; break; }
		default: { state = 0; break; }
		} break;
	}
	case 75: {
		switch (c) {
		case 't': { state = 76; break; }
		default: { state = 0; break; }
		} break;
	}
	case 76: {
		switch (c) {
		case 'a': { state = 77; break; }
		case 'o': { state = 79; break; }
		default: { state = 0; break; }
		} break;
	}
	case 77: {
		switch (c) {
		case 'n': { state = 78; break; }
		default: { state = 0; break; }
		} break;
	}
	case 78: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 79: {
		switch (c) {
		case 'r': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 80: {
		switch (c) {
		case 'o': { state = 81; break; }
		default: { state = 0; break; }
		} break;
	}
	case 81: {
		switch (c) {
		case 'l': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 82: {
		switch (c) {
		case 'e': { state = 83; break; }
		default: { state = 0; break; }
		} break;
	}
	case 83: {
		switch (c) {
		case 'a': { state = 84; break; }
		default: { state = 0; break; }
		} break;
	}
	case 84: {
		switch (c) {
		case 'k': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 85: {
		switch (c) {
		case 'a': { state = 86; break; }
		case 'h': { state = 90; break; }
		case 'l': { state = 98; break; }
		case 'o': { state = 101; break; }
		default: { state = 0; break; }
		} break;
	}
	case 86: {
		switch (c) {
		case 's': { state = 87; break; 
		case 't': { state = 88; break; }
		default: { state = 0; break; }
		} break;
	}
	case 87: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 88: {
		switch (c) {
		case 'c': { state = 89; break; }
		default: { state = 0; break; }
		} break;
	}
	case 89: {
		switch (c) {
		case 'h': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 90: {
		switch (c) {
		case 'a': { state = 91; break; }
		default: { state = 0; break; }
		} break;
	}
	case 91: {
		switch (c) {
		case 'r': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 92: {
		switch (c) {
		case '_': { state = 93; break; }
		default: { state = 0; break; }
		} break;
	}
	case 93: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 94: {
		switch (c) {
		case '6': { state = 92; break; }
		default: { state = 0; break; }
		} break;
	}
	case 95: {
		switch (c) {
		case '_': { state = 93; break; }
		default: { state = 0; break; }
		} break;
	}
	case 96: {
		switch (c) {
		case '2': { state = 92; break; }
		default: { state = 0; break; }
		} break;
	}
	case 97: {
		switch (c) {
		case '_': { state = 93; break; }
		default: { state = 0; break; }
		} break;
	}
	case 98: {
		switch (c) {
		case 'a': { state = 99; break; }
		default: { state = 0; break; }
		} break;
	}
	case 99: {
		switch (c) {
		case 's': { state = 100; break; }
		default: { state = 0; break; }
		} break;
	}
	case 100: {
		switch (c) {
		case 's': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 101: {
		switch (c) {
		case 'm': { state = 102; break; }
		case 'n': { state = 104; break; }
		default: { state = 0; break; }
		} break;
	}
	case 102: {
		switch (c) {
		case 'p': { state = 103; break; }
		default: { state = 0; break; }
		} break;
	}
	case 103: {
		switch (c) {
		case 'l': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 104: {
		switch (c) {
		case 'c': { state = 105; break; }
		case 's': { state = 108; break; }
		case 't': { state = 121; break; }
		default: { state = 0; break; }
		} break;
	}
	case 105: {
		switch (c) {
		case 'e': { state = 106; break; }
		default: { state = 0; break; }
		} break;
	}
	case 106: {
		switch (c) {
		case 'p': { state = 107; break; }
		default: { state = 0; break; }
		} break;
	}
	case 107: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 108: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 109: {
		switch (c) {
		case 'v': { state = 110; break; }
		case 'x': { state = 112; break; }
		default: { state = 0; break; }
		} break;
	}
	case 110: {
		switch (c) {
		case 'a': { state = 111; break; }
		default: { state = 0; break; }
		} break;
	}
	case 111: {
		switch (c) {
		case 'l': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 112: {
		switch (c) {
		case 'p': { state = 113; break; }
		default: { state = 0; break; }
		} break;
	}
	case 113: {
		switch (c) {
		case 'r': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 114: {
		switch (c) {
		case 'n': { state = 115; break; }
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
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 117: {
		switch (c) {
		case 'c': { state = 118; break; }
		default: { state = 0; break; }
		} break;
	}
	case 118: {
		switch (c) {
		case 'a': { state = 119; break; }
		default: { state = 0; break; }
		} break;
	}
	case 119: {
		switch (c) {
		case 's': { state = 120; break; }
		default: { state = 0; break; }
		} break;
	}
	case 120: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 121: {
		switch (c) {
		case 'i': { state = 122; break; }
		default: { state = 0; break; }
		} break;
	}
	case 122: {
		switch (c) {
		case 'n': { state = 123; break; }
		default: { state = 0; break; }
		} break;
	}
	case 123: {
		switch (c) {
		case 'u': { state = 124; break; }
		default: { state = 0; break; }
		} break;
	}
	case 124: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 125: {
		switch (c) {
		case 'e': { state = 126; break; }
		case 'o': { state = 1; break; }
		case 'y': { state = 142; break; }
		default: { state = 0; break; }
		} break;
	}
	case 126: {
		switch (c) {
		case 'c': { state = 127; break; }
		case 'f': { state = 132; break; }
		case 'l': { state = 136; break; }
		default: { state = 0; break; }
		} break;
	}
	case 127: {
		switch (c) {
		case 'l': { state = 128; break; }
		default: { state = 0; break; }
		} break;
	}
	case 128: {
		switch (c) {
		case 't': { state = 129; break; }
		default: { state = 0; break; }
		} break;
	}
	case 129: {
		switch (c) {
		case 'y': { state = 130; break; }
		default: { state = 0; break; }
		} break;
	}
	case 130: {
		switch (c) {
		case 'p': { state = 131; break; }
		default: { state = 0; break; }
		} break;
	}
	case 131: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 132: {
		switch (c) {
		case 'a': { state = 133; break; }
		default: { state = 0; break; }
		} break;
	}
	case 133: {
		switch (c) {
		case 'u': { state = 134; break; }
		default: { state = 0; break; }
		} break;
	}
	case 134: {
		switch (c) {
		case 'l': { state = 135; break; }
		default: { state = 0; break; }
		} break;
	}
	case 135: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 136: {
		switch (c) {
		case 'e': { state = 137; break; }
		default: { state = 0; break; }
		} break;
	}
	case 137: {
		switch (c) {
		case 't': { state = 138; break; }
		default: { state = 0; break; }
		} break;
	}
	case 138: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 139: {
		switch (c) {
		case 'b': { state = 140; break; }
		default: { state = 0; break; }
		} break;
	}
	case 140: {
		switch (c) {
		case 'l': { state = 141; break; }
		default: { state = 0; break; }
		} break;
	}
	case 141: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 142: {
		switch (c) {
		case 'n': { state = 143; break; }
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
		case 'm': { state = 145; break; }
		default: { state = 0; break; }
		} break;
	}
	case 145: {
		switch (c) {
		case 'i': { state = 146; break; }
		default: { state = 0; break; }
		} break;
	}
	case 146: {
		switch (c) {
		case 'c': { state = 147; break; }
		default: { state = 0; break; }
		} break;
	}
	case 147: {
		switch (c) {
		case '_': { state = 148; break; }
		default: { state = 0; break; }
		} break;
	}
	case 148: {
		switch (c) {
		case 'c': { state = 149; break; }
		default: { state = 0; break; }
		} break;
	}
	case 149: {
		switch (c) {
		case 'a': { state = 150; break; }
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
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 152: {
		switch (c) {
		case 'l': { state = 153; break; }
		case 'n': { state = 155; break; }
		case 'x': { state = 157; break; }
		default: { state = 0; break; }
		} break;
	}
	case 153: {
		switch (c) {
		case 's': { state = 154; break; }
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
		case 'u': { state = 156; break; }
		default: { state = 0; break; }
		} break;
	}
	case 156: {
		switch (c) {
		case 'm': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 157: {
		switch (c) {
		case 'p': { state = 158; break; }
		case 't': { state = 165; break; }
		default: { state = 0; break; }
		} break;
	}
	case 158: {
		switch (c) {
		case 'l': { state = 159; break; }
		case 'o': { state = 163; break; }
		default: { state = 0; break; }
		} break;
	}
	case 159: {
		switch (c) {
		case 'i': { state = 160; break; }
		default: { state = 0; break; }
		} break;
	}
	case 160: {
		switch (c) {
		case 'c': { state = 161; break; }
		default: { state = 0; break; }
		} break;
	}
	case 161: {
		switch (c) {
		case 'i': { state = 162; break; }
		default: { state = 0; break; }
		} break;
	}
	case 162: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 163: {
		switch (c) {
		case 'r': { state = 164; break; }
		default: { state = 0; break; }
		} break;
	}
	case 164: {
		switch (c) {
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 165: {
		switch (c) {
		case 'e': { state = 166; break; }
		default: { state = 0; break; }
		} break;
	}
	case 166: {
		switch (c) {
		case 'r': { state = 167; break; }
		default: { state = 0; break; }
		} break;
	}
	case 167: {
		switch (c) {
		case 'n': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 168: {
		switch (c) {
		case 'a': { state = 169; break; }
		case 'l': { state = 172; break; }
		case 'o': { state = 175; break; }
		case 'r': { state = 176; break; }
		default: { state = 0; break; }
		} break;
	}
	case 169: {
		switch (c) {
		case 'l': { state = 170; break; }
		default: { state = 0; break; }
		} break;
	}
	case 170: {
		switch (c) {
		case 's': { state = 171; break; }
		default: { state = 0; break; }
		} break;
	}
	case 171: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 172: {
		switch (c) {
		case 'o': { state = 173; break; }
		default: { state = 0; break; }
		} break;
	}
	case 173: {
		switch (c) {
		case 'a': { state = 174; break; }
		default: { state = 0; break; }
		} break;
	}
	case 174: {
		switch (c) {
		case 't': { state = 1; break; }
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
		case 'i': { state = 177; break; }
		default: { state = 0; break; }
		} break;
	}
	case 177: {
		switch (c) {
		case 'e': { state = 178; break; }
		default: { state = 0; break; }
		} break;
	}
	case 178: {
		switch (c) {
		case 'n': { state = 179; break; }
		default: { state = 0; break; }
		} break;
	}
	case 179: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 180: {
		switch (c) {
		case 'o': { state = 181; break; }
		default: { state = 0; break; }
		} break;
	}
	case 181: {
		switch (c) {
		case 't': { state = 182; break; }
		default: { state = 0; break; }
		} break;
	}
	case 182: {
		switch (c) {
		case 'o': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 183: {
		switch (c) {
		case 'f': { state = 1; break; }
		case 'n': { state = 184; break; }
		default: { state = 0; break; }
		} break;
	}
	case 184: {
		switch (c) {
		case 'l': { state = 185; break; }
		case 't': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 185: {
		switch (c) {
		case 'i': { state = 186; break; }
		default: { state = 0; break; }
		} break;
	}
	case 186: {
		switch (c) {
		case 'n': { state = 187; break; }
		default: { state = 0; break; }
		} break;
	}
	case 187: {
		switch (c) {
		case 'e': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 188: {
		switch (c) {
		case 'o': { state = 189; break; }
		default: { state = 0; break; }
		} break;
	}
	case 189: {
		switch (c) {
		case 'n': { state = 190; break; }
		default: { state = 0; break; }
		} break;
	}
	case 190: {
		switch (c) {
		case 'g': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
			// ##############################################################
	case 191: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 192: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 193: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 194: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 195: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 196: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 197: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 198: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 199: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 200: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 201: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 202: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 203: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 204: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 205: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 206: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 207: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 208: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 209: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 210: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 211: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 212: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 213: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 214: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 215: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 216: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 217: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 218: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 219: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 220: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 221: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 222: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 223: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 224: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 225: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 226: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 227: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 228: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 229: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 230: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 231: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 232: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 233: {
		switch (c) {
		case 'd': { state = 1; break; }
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
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 236: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 237: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 238: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 239: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 240: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 241: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 242: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 243: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 244: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 245: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 246: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 247: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 248: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 249: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 250: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 251: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 252: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 253: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 254: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 255: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 256: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 257: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 258: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 259: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 260: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 261: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 262: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 263: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 264: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 265: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 266: {
		switch (c) {
		case 'd': { state = 1; break; }
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
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 269: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 270: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 271: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 272: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 273: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 274: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 275: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 276: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 277: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 278: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 279: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 280: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 281: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 282: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 283: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 284: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 285: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 286: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 287: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 288: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 289: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 290: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 291: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 292: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 293: {
		switch (c) {
		case 'd': { state = 1; break; }
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
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 296: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 297: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 298: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 299: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 300: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 301: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 302: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 303: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 304: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 305: {
		switch (c) {
		case 'd': { state = 1; break; }
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
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 308: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 309: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 310: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 311: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 312: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 313: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 314: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 315: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 316: {
		switch (c) {
		case 'd': { state = 1; break; }
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
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 319: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 320: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 321: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 322: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 323: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 324: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 325: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 326: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 327: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 328: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 329: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 330: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 331: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 332: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 333: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 334: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 335: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 336: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 337: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 338: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 339: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 340: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 341: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 342: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 343: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 344: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 345: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 346: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 347: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 348: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 349: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 350: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 351: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 352: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 353: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 354: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 355: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 356: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 357: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 358: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 359: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 360: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 361: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 362: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 363: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 364: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 365: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 366: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 367: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 368: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 369: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 370: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 371: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 372: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 373: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 374: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 375: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 376: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 377: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 378: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 379: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 380: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 381: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 382: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 383: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 384: {
		switch (c) {
		case 'd': { state = 1; break; }
		default: { state = 0; break; }
		} break;
	}
	case 385: {
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
	if ((state == 1 || state == 2 || state == 9) && (is_delim(next) || is_sign(next)) && !is_id) {
		if ((state != 2 && state != 9) || next != '.') {
			if (state == 9) state = 2;
			return buffer;
		}
	}

	// Знаки
	if ((state > 10 && state <= 60) && (!is_next_valid(next) || is_multisign()) && !is_id) {
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
	if (buffer != "" && (is_id || state > 60) && (is_delim(next) || (is_sign(next) && !is_next_valid(next)))) {
		state = 3; return buffer;
	}

	if ((state >= 3 && state <= 5) && (is_delim(next) || (is_sign(next) && !is_next_valid(next)))) {
		this->error = "Неверная константа: " + buffer;
		clear_state();
		return "error";
	}

	return "";
}

