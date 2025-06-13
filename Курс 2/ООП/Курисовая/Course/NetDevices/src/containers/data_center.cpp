#include <iostream>
#include "data_center.h"
#include "../devices/net_device.h"

DataCenter::DataCenter() : Container() {
	this->clients_total = 0;
}

//NetDevice*& ServerRoom::operator[](int index) {
//	return Container::operator[](index);
//}

void DataCenter::add(void* device) {
	Container::add(device);
}

std::vector<void*> DataCenter::get_vector() {
	return Container::get_vector();
}

void DataCenter::remove(int index) {

}

void DataCenter::print() {

}

int DataCenter::size() {
	return Container::size();
}

int DataCenter::get_total_devices() const {
	return clients_total;
}

void DataCenter::clear() {
	// TODO: Clear values
}
