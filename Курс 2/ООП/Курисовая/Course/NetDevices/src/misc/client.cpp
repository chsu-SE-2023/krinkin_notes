#include "client.h"

/**
* Конструктор по умолчанию
*/
Client::Client() {
	this->name = "";
	this->address = MAC_Address();
	this->bytes = nullptr;
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
	this->bytes = nullptr;
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
	this->bytes = nullptr;
	this->type = WIRED;
}

/**
* Конструктор с параметрами
*
* @param массив байт
*/
Client::Client(unsigned char* bytes) {
	this->name = "";
	this->address = MAC_Address();
	this->bytes = bytes;
	this->type = WIRED;
}

/**
* Конструктор с параметрами
*
* @param имя клиента
* @param MAC-адрес
* @param массив байт
* @param тип подключения (0 - WIRED, 1 - WIRELESS)
*/
Client::Client(std::string name, MAC_Address address, unsigned char* bytes, char type) {
	this->name = name;
	this->address = address;
	this->bytes = bytes;
	this->type = type;
}
/**
* Копирующий коструктор
*
* @param экземпляр Client
*/
Client::Client(const Client& copy) {
	this->name = copy.name;
	this->address = copy.address;
	this->bytes = copy.bytes;
	this->type = copy.type;
}

/**
* Деконструктор
*/
Client::~Client() {
	name = "";
	if (bytes) delete bytes;
}

/**
* Перегрузка оператора ==
* 
* @param первый объект
* @param второй объект
* @return результат сравнения
*/
bool operator==(const Client& first, const Client& second) {
	return first.address == second.address;
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
* Метод, отправляющий байты на сетевое устройство
*
* @param сетевое устройство
*/
void Client::send_to(NetDevice* device) {
	device->receive(this->bytes);
}

/**
* Метод, принимающий байты от сетевого устройства
* 
* Сохраняет полученный адрес массива в поле объекта,
* а также возвращает его значение
*
* @param сетевое устройство
* @return массив байт
*/
const unsigned char* Client::receive_from(NetDevice* device) {
	this->bytes = device->get_bytes();
	return this->bytes;
}