#pragma once
#include <vector>

class Repeater {

protected:
    const std::vector<double>* packets;

public:
    Repeater();
    Repeater(const std::vector<double>*&); // packets
    Repeater(Repeater&); // copy
    ~Repeater();
    void send_to(Repeater&);
    void receive(const std::vector<double>*&);
};
