#include "client.h"

/**
* Конструктор по умолчанию
*/
Client::Client() {
	this->name = "";
	this->address = MAC_Address();
	this->packets = nullptr;
	this->type = WIRED;
}

/**
* Конструктор с параметрами
*
* @param имя клиента
*/
Client::Client(std::string name) {
	this->name = name;
	this->address = MAC_Address();
	this->packets = nullptr;
	this->type = WIRED;
}

/**
* Конструктор с параметрами
*
* @param MAC-адрес
*/
Client::Client(MAC_Address address) {
	this->name = "";
	this->address = address;
	this->packets = nullptr;
	this->type = WIRED;
}

/**
* Конструктор с параметрами
*
* @param массив пакетов
*/
Client::Client(double* packets) {
	this->name = "";
	this->address = MAC_Address();
	this->packets = packets;
	this->type = WIRED;
}

/**
* Конструктор с параметрами
*
* @param имя клиента
* @param MAC-адрес
* @param массив пакетов
* @param тип подключения (0 - WIRED, 1 - WIRELESS)
*/
Client::Client(std::string name, MAC_Address address, double* packets, char type) {
	this->name = name;
	this->address = address;
	this->packets = packets;
	this->type = type;
}
/**
* Копирующий коструктор
*
* @param экземпляр Client
*/
Client::Client(Client& copy) {
	this->name = copy.name;
	this->address = copy.address;
	this->packets = copy.packets;
	this->type = copy.type;
}

/**
* Деконструктор
*/
Client::~Client() {
	name = "";
	if (packets) delete packets;
}

/**
* Метод, возвращающий MAC-адрес клиента
*
* @return MAC-адрес
*/
MAC_Address Client::get_address() const {
	return address;
}

/**
* Метод, возвращающий имя клиента
*
* @return имя клиента
*/
std::string Client::get_name() const {
	return name;
}

/**
* Метод, возвращающий тип подключения клиента
*
* @return тип подключения (0 - WIRED, 1 - WIRELESS)
*/
char Client::get_type() const {
	return this->type;
}

/**
* Метод, устанавливающий MAC-адрес клиента
*
* @param MAC-адрес
*/
void Client::set_address(MAC_Address address) {
	this->address = address;
}

/**
* Метод, устанавливающий имя клиента
*
* @param имя клиента
*/
void Client::set_name(std::string) {
	this->name = name;
}

/**
* Метод, устанавливающий тип подключения клиента
*
* @param тип подключения (0 - WIRED, 1 - WIRELESS)
*/
void Client::set_type(char type) {
	this->type = type;
}

/**
* Метод, отправляющий пакеты на сетевое устройство
*
* @param сетевое устройство
*/
void Client::send_to(NetDevice* device) {
	device->receive(this->packets);
}

/**
* Метод, принимающий пакеты от сетевого устройства
* 
* Сохраняет полученный адрес массива в поле объекта,
* а также возвращает его значение
*
* @param сетевое устройство
* @return массив пакетов
*/
const double* Client::receive_from(NetDevice* device) {
	this->packets = device->get_packets();
	return this->packets;
}