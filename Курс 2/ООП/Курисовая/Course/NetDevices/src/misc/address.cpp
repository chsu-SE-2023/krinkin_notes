#include "address.h"
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
* Оператор, проверяюий идентичны ли два MAC-адреса
*
* @param первый MAC-адрес
* @param второй MAC-адрес
*/
bool operator== (MAC_Address& first, MAC_Address& second) {
    return first.values == second.values;
}

/**
* Оператор, проверяюий различны ли два MAC-адреса
*
* @param первый MAC-адрес
* @param второй MAC-адрес
*/
bool operator!= (MAC_Address& first, MAC_Address& second) {
    return first.values != second.values;
}

/**
* Метод, возвращающий MAC-адрес как строку
*
* @return MAX-адрес как std::string
*/
std::string MAC_Address::as_string() {
	std::stringstream ss;
	for (int i = 0; i < values.size() - 1; i++)
		ss << std::hex << (unsigned int)std::int8_t(values[i]) << ':';
	ss << std::hex << (unsigned int)std::int8_t(values[values.size()-1]);
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
