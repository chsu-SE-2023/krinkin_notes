#include "repeater.h"
#include <vector>

Repeater::Repeater() {
    this->packets = nullptr;
};
Repeater::Repeater(const std::vector<double>*& packets) {
    this->packets = packets;
};
Repeater::Repeater(Repeater& copy) {
    copy.packets = this->packets;
};
Repeater::~Repeater() {
    delete this->packets;
};
void Repeater::send_to(Repeater& dest) {
    dest.packets = this->packets;
};
void Repeater::receive(const std::vector<double>*& packets) {
    this->packets = packets;
};
