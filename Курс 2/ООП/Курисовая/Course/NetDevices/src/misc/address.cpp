#include "address.h"
#include <iomanip>
#include <sstream>
#include <ios>

/**
* Конструктор по умолчанию. Создаёт случайный адрес
*/
MAC_Address::MAC_Address() {
	generate();
}

/**
* Конструктор с параметром
* 
* @param массив значений
*/
MAC_Address::MAC_Address(std::array<unsigned char, 6> values) {
	this->values = values;
}

/**
* Конструктор с параметром
*
* @param адрес в виде строки
*/
MAC_Address::MAC_Address(std::string str) {
	std::istringstream isstream(str);
	std::string part;
	int size = 0;
	while (std::getline(isstream, part, ':') && size < 6) {
		int value = std::stoi(part, nullptr, 16);
		if (value > 255) throw std::overflow_error("MAC Address part was bigger than one byte");
		values[size] = value;
		size++;
	}
	if (size != 6) throw std::length_error("MAC Address string was incorrect");
}

/**
* Копирующий конструтор
*
* @param ссылка на экземпляр MAC_Address
*/
MAC_Address::MAC_Address(const MAC_Address& copy) {
	this->values = copy.values;
}

/**
* Перегрузка оператора больше
*
* @param первый MAC-адрес
* @param второй MAC-адрес
*/
bool operator>(const MAC_Address& first, const MAC_Address& second) {
	for (int i = 0; i < first.values.size(); i++) {
		if (first.values[i] != second.values[i])
			return first.values[i] > second.values[i];
	}
	return false;
}

/**
* Перегрузка оператора меньше
*
* @param первый MAC-адрес
* @param второй MAC-адрес
*/
bool operator<(const MAC_Address& first, const MAC_Address& second) {
	for (int i = 0; i < first.values.size(); i++) {
		if (first.values[i] != second.values[i]) 
			return first.values[i] < second.values[i];
	}
	return false;
}

/**
* Перегрузка оператора больше или равно
*
* @param первый MAC-адрес
* @param второй MAC-адрес
*/
bool operator>=(const MAC_Address& first, const MAC_Address& second) {
	for (int i = 0; i < first.values.size(); i++) {
		if (first.values[i] != second.values[i])
			return first.values[i] > second.values[i];
	}
	return true;
}

/**
* Перегрузка оператора меньше или равно
*
* @param первый MAC-адрес
* @param второй MAC-адрес
*/
bool operator<=(const MAC_Address& first, const MAC_Address& second) {
	for (int i = 0; i < first.values.size(); i++) {
		if (first.values[i] != second.values[i])
			return first.values[i] < second.values[i];
	}
	return true;
}

/**
* Оператор, проверяющий идентичны ли два MAC-адреса
*
* @param первый MAC-адрес
* @param второй MAC-адрес
*/
bool operator== (const MAC_Address& first, const MAC_Address& second) {
    return first.values == second.values;
}

/**
* Оператор, проверяющий различны ли два MAC-адреса
*
* @param первый MAC-адрес
* @param второй MAC-адрес
*/
bool operator!= (const MAC_Address& first, const MAC_Address& second) {
    return first.values != second.values;
}

/**
* Метод, возвращающий MAC-адрес как строку
*
* @return MAC-адрес как std::string
*/
std::string MAC_Address::as_string() {
	std::stringstream ss;
	for (int i = 0; i < values.size() - 1; i++)
		ss << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(static_cast<uint8_t>(values[i])) << ':';
	ss << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(static_cast<uint8_t>(values[values.size()-1]));
	return ss.str();
}

/**
* Метод, случайно генерирующий MAC-адресс
*
* @param семя для генератора случайных чисел
*/
void MAC_Address::generate() {
	for (int i = 0; i < values.size(); i++)
		values[i] = rand() % 255;
}
