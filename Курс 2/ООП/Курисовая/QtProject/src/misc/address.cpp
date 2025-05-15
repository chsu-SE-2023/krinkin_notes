#include "address.h"
#include <sstream>
#include <ios>

/**
* ����������� �� ���������. ������ ����� 00:00:00:00:00:00
*/
MAC_Address::MAC_Address() {
	values.fill(0);
}

/**
* ����������� � ����������
* 
* @param ������ ��������
*/
MAC_Address::MAC_Address(std::array<unsigned char, 6> values) {
	this->values = values;
}

/**
* �����, ������������ MAC-����� ��� ������
*
* @return MAX-����� ��� std::string
*/
std::string MAC_Address::as_string() {
	std::stringstream ss;
	for (int i = 0; i < values.size() - 1; i++)
		ss << std::hex << (unsigned int)std::int8_t(values[i]) << ':';
	ss << std::hex << (unsigned int)std::int8_t(values[values.size()-1]);
	return ss.str();
}

/**
* �����, �������� ������������ MAC-������
*
* @param ���� ��� ���������� ��������� �����
*/
void MAC_Address::generate(unsigned int seed) {
	srand(seed);
	for (int i = 0; i < values.size(); i++)
		values[i] = rand() % 255;
}