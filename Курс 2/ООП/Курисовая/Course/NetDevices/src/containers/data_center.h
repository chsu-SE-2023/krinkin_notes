#pragma once
#include "../devices/repeater.h"
#include "container.h"
#include "server_room.h"

class DataCenter : private Container {
public:
	DataCenter();
	ServerRoom<Repeater>* operator[](int);
	void add(void*);
	void clear();
	int count(void*);
	int get_total_devices();
	std::vector<void*> get_vector();
	void seek(int);
	int size();
};
