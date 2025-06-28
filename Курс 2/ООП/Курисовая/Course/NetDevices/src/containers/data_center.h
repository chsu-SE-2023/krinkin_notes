#pragma once
#include "../devices/net_device.h"
#include "container.h"

class DataCenter : private Container {
private:
	int clients_total;
public:
	DataCenter();
	NetDevice_I* operator[](int);
	void add(void*);
	void clear();
	int count(void*);
	int get_total_devices() const;
	std::vector<void*> get_vector();
	void seek(int);
	int size();
};
