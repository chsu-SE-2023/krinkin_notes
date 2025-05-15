#pragma once
#include "../devices/net_device.h"
#include "container.h"
#include "net_room.h"

class Stats : private Container {
private:
	int clients_total;
public:
	Stats();
	~Stats();
	void to_template(ServerRoom<NetDevice>*) const;
	void to_map(ServerRoom<NetDevice>*, int = 1, int = 0, bool = false);
	void to_map(NetDevice&, int);
	void increase(NetDevice&, int);
	void decrease(NetDevice&, int);
	void remove(NetDevice&);
	void print() const;
	int size(NetDevice&);
	int get_total() const;
	int get_total_devices() const;
	void clear();
};
