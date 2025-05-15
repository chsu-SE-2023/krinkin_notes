#include "client.h"

/**
* ����������� �� ���������
*/
Client::Client() {
	this->name = "";
	this->address = MAC_Address();
	this->packets = nullptr;
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
	this->packets = nullptr;
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
	this->packets = nullptr;
	this->type = WIRED;
}

/**
* ����������� � �����������
*
* @param ������ �������
*/
Client::Client(double* packets) {
	this->name = "";
	this->address = MAC_Address();
	this->packets = packets;
	this->type = WIRED;
}

/**
* ����������� � �����������
*
* @param ��� �������
* @param MAC-�����
* @param ������ �������
* @param ��� ����������� (0 - WIRED, 1 - WIRELESS)
*/
Client::Client(std::string name, MAC_Address address, double* packets, char type) {
	this->name = name;
	this->address = address;
	this->packets = packets;
	this->type = type;
}
/**
* ���������� ����������
*
* @param ��������� Client
*/
Client::Client(Client& copy) {
	this->name = copy.name;
	this->address = copy.address;
	this->packets = copy.packets;
	this->type = copy.type;
}

/**
* �������������
*/
Client::~Client() {
	name = "";
	if (packets) delete packets;
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
* �����, ������������ ������ �� ������� ����������
*
* @param ������� ����������
*/
void Client::send_to(NetDevice* device) {
	device->receive(this->packets);
}

/**
* �����, ����������� ������ �� �������� ����������
* 
* ��������� ���������� ����� ������� � ���� �������,
* � ����� ���������� ��� ��������
*
* @param ������� ����������
* @return ������ �������
*/
const double* Client::receive_from(NetDevice* device) {
	this->packets = device->get_packets();
	return this->packets;
}