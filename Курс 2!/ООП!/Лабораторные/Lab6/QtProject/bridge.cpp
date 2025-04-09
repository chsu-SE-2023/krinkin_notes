#include "bridge.h"

void Bridge::set_defaults() {};
Bridge::Bridge() {};
Bridge::Bridge(const int* address) {};
Bridge::Bridge(const double* packets, int* address) {};
Bridge::Bridge(Bridge& copy) {};
Bridge::~Bridge() {};
void Bridge::connect() {};
void Bridge::disconnect() {};
void Bridge::print_info() const {};
int* Bridge::get_address() const {};
int Bridge::get_connected() const {};
void Bridge::set_address(const int*) {};
