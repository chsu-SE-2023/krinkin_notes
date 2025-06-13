#pragma once
#include "../devices/net_device.h"
#include "container.h"

class DataCenter : private Container {
private:
	int clients_total;
public:
	DataCenter();
	//NetDevice*& operator[](int);
	void add(void*);
	std::vector<void*> get_vector();
	void remove(int);
	void print();
	int size();
	int get_total_devices() const;
	void clear();
};
