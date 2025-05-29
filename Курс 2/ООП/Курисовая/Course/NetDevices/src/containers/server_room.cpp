#include <iostream>
#include "server_room.h"
#include "../devices/net_device.h"

ServerRoom::ServerRoom() : Container() {
	this->clients_total = 0;
}

ServerRoom::~ServerRoom() {
	clear();
}

//NetDevice*& ServerRoom::operator[](int index) {
//	return Container::operator[](index);
//}

void ServerRoom::add(NetDevice* device) {
	Container::add(device);
}

void ServerRoom::remove(int index) {

}

void ServerRoom::print() {

}

int ServerRoom::size() {
	return Container::size();
}

int ServerRoom::get_total_devices() const {
	return clients_total;
}

void ServerRoom::clear() {
	Container::~Container();
}
