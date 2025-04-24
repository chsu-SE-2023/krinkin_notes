#pragma once
#include "router.h"
#include "net_room.h"
#include <map>

class Stats {
private:
	std::map<const Router*, int> routers;
	friend class Tests;
	int clients_total;
public:
	Stats();
	~Stats();
	void to_template(ServerRoom<Router>*) const;
	void to_map(ServerRoom<Router>*, int = 1, int = 0, bool = false);
	void to_map(Router*, int);
	void increase(Router*, int);
	void decrease(Router*, int);
	void remove(Router*);
	void print() const;
	int get_count(Router*);
	int get_total() const;
	int get_total_devices() const;
	void clear();
};
