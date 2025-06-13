#include "address.h"
#include <iomanip>
#include <sstream>
#include <ios>

/**
* Конструктор по умолчанию. Создаёт адрес 00:00:00:00:00:00
*/
MAC_Address::MAC_Address() {
	values.fill(0);
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
* Оператор, проверяюий идентичны ли два MAC-адреса
*
* @param первый MAC-адрес
* @param второй MAC-адрес
*/
bool operator== (const MAC_Address& first, const MAC_Address& second) {
    return first.values == second.values;
}

/**
* Оператор, проверяюий различны ли два MAC-адреса
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
		ss << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << (unsigned int)std::int8_t(values[i]) << ':';
	ss << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << (unsigned int)std::int8_t(values[values.size()-1]);
	return ss.str();
}

/**
* Метод, случайно генерирующий MAC-адресс
*
* @param семя для генератора случайных чисел
*/
void MAC_Address::generate(unsigned int seed) {
	srand(seed);
	for (int i = 0; i < values.size(); i++)
		values[i] = rand() % 255;
}
