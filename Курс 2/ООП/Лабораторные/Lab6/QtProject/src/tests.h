#pragma once
#include "router.h"
#include "switch.h"
#include <string>
#include <vector>
#include <array>

class Tests {
private:
    const double* packets = new double[10] {15.6, 10.4, 54.32, 4.54, 31.542, 4.5, 45.7, 2.5, 24.5, 3.2};
    std::array<int, 32> clients = {1, 2, 3};
    std::array<int, 5> address = {10, 11, 12, 13, 14};
    std::string ssid = "CoolWLAN";
    std::string passwd = "qwerty123";
    std::string protocol = "sftp://";
    bool wpa = false;
    Switch* s_def;
    Switch** s_units;
    Router* r_def;
    Router** r_units;
    constexpr static const char* errors[100] = {
        "PASS",                                            // 0
        "FAIL (Switch->connected is not equal)",           // 1
        "FAIL (Switch->clients is not equal)",             // 2
        "FAIL (Switch->address is not equal)",             // 3
        "FAIL (Switch->packets is not equal)",             // 4
        "FAIL (Router->connected is not equal)",           // 5
        "FAIL (Router->clients is not equal)",             // 6
        "FAIL (Router->address is not equal)",             // 7
        "FAIL (Router->packets is not equal)",             // 8
        "FAIL (Router->ssid is not equal)",                // 9
        "FAIL (Router->passwd is not equal)",              // 10
        "FAIL (Router->wpa is not equal)",                 // 11
        "FAIL (Switch container failed to save object)",   // 12
        "FAIL (Router container failed to save object)",   // 13
        "FAIL (Switch container failed to find object)",   // 14
        "FAIL (Router container failed to find object)",   // 15
        "FAIL (Switch container sorting is wrong)",        // 16
        "FAIL (Router container sorting is wrong)",        // 17
        "FAIL (Operator + is wrong for Switch)",           // 18
        "FAIL (Operator -- is wrong for Switch)",          // 19
        "FAIL (Operator [] is wrong for Switch)",          // 20
        "FAIL (Operator == is wrong for Switch)",          // 21
        "FAIL (Operator + is wrong for Router)",           // 22
        "FAIL (Operator -- is wrong for Router)",          // 23
        "FAIL (Operator [] is wrong for Router)",          // 24
        "FAIL (Operator == is wrong for Router)",          // 25
        "FAIL (Objects is not added to the template)",     // 26
        "FAIL (std::map is not clears)",                   // 27
        "FAIL (Wrong increase result)",                    // 28
        "FAIL (Wrong decrease result)",                    // 29
        "FAIL (Object is not deleted from std::map)",      // 30
        "FAIL (Clients count is not right)",               // 31
    };

public:

    Tests();
    ~Tests();
    const char* memory();
    const char* data();
    const char* container();
    const char* search();
    const char* sort();
    const char* opers();
    const char* stats();
};
