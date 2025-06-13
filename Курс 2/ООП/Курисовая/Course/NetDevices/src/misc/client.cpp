#include "client.h"

/**
* ����������� �� ���������
*/
Client::Client() {
	this->name = "";
	this->address = MAC_Address();
	this->bytes = nullptr;
	this->type = WIRED;
}

/**
* ����������� � �����������
*
* @param ��� �������
*/
Client::Client(std::string name) {
	this->name = name;
	this->address = MAC_Address();
	this->bytes = nullptr;
	this->type = WIRED;
}

/**
* ����������� � �����������
*
* @param MAC-�����
*/
Client::Client(MAC_Address address) {
	this->name = "";
	this->address = address;
	this->bytes = nullptr;
	this->type = WIRED;
}

/**
* ����������� � �����������
*
* @param ������ ����
*/
Client::Client(unsigned char* bytes) {
	this->name = "";
	this->address = MAC_Address();
	this->bytes = bytes;
	this->type = WIRED;
}

/**
* ����������� � �����������
*
* @param ��� �������
* @param MAC-�����
* @param ������ ����
* @param ��� ����������� (0 - WIRED, 1 - WIRELESS)
*/
Client::Client(std::string name, MAC_Address address, unsigned char* bytes, char type) {
	this->name = name;
	this->address = address;
	this->bytes = bytes;
	this->type = type;
}
/**
* ���������� ����������
*
* @param ��������� Client
*/
Client::Client(const Client& copy) {
	this->name = copy.name;
	this->address = copy.address;
	this->bytes = copy.bytes;
	this->type = copy.type;
}

/**
* �������������
*/
Client::~Client() {
	name = "";
	if (bytes) delete bytes;
}

/**
* ���������� ��������� ==
* 
* @param ������ ������
* @param ������ ������
* @return ��������� ���������
*/
bool operator==(const Client& first, const Client& second) {
	return first.address == second.address;
}

/**
* �����, ������������ MAC-����� �������
*
* @return MAC-�����
*/
MAC_Address Client::get_address() const {
	return address;
}

/**
* �����, ������������ ��� �������
*
* @return ��� �������
*/
std::string Client::get_name() const {
	return name;
}

/**
* �����, ������������ ��� ����������� �������
*
* @return ��� ����������� (0 - WIRED, 1 - WIRELESS)
*/
char Client::get_type() const {
	return this->type;
}

/**
* �����, ��������������� MAC-����� �������
*
* @param MAC-�����
*/
void Client::set_address(MAC_Address address) {
	this->address = address;
}

/**
* �����, ��������������� ��� �������
*
* @param ��� �������
*/
void Client::set_name(std::string) {
	this->name = name;
}

/**
* �����, ��������������� ��� ����������� �������
*
* @param ��� ����������� (0 - WIRED, 1 - WIRELESS)
*/
void Client::set_type(char type) {
	this->type = type;
}

/**
* �����, ������������ ����� �� ������� ����������
*
* @param ������� ����������
*/
void Client::send_to(NetDevice_I* device) {
	device->receive(this->bytes);
}

/**
* �����, ����������� ����� �� �������� ����������
* 
* ��������� ���������� ����� ������� � ���� �������,
* � ����� ���������� ��� ��������
*
* @param ������� ����������
* @return ������ ����
*/
const unsigned char* Client::receive_from(NetDevice_I* device) {
	this->bytes = device->get_bytes();
	return this->bytes;
}