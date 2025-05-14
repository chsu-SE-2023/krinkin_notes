#include "network.h"
#include "net_room.h"
#include <iostream>

int main() {

    Switch sw1 = Switch(new int[11]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, 11);
    Switch sw2 = Switch(new int[2]{1, 2}, 2);
    Switch sw3 = Switch(new int[8]{1, 2, 3, 4, 5, 6, 7, 8}, 8);
    Switch sw4 = Switch(new int[5]{65, 53, 52, 24, 78});
    Switch sw5 = Switch(new int[5]{76, 98, 12, 5, 7});
    Switch sw6 = Switch(new int[6] {6, 6, 6, 6, 6, 6}, 6);
    Switch sw7 = Switch(new int[9] {6, 6, 6, 6, 6, 6, 6, 6, 6}, 9);
    Switch sw8 = Switch(new int[12] {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, 12);

    ServerRoom cab1 = ServerRoom(&sw1);
    cab1.add(&sw2);
    cab1.add(&sw3);
    cab1.add(&sw4);
    cab1.add(&sw5);
    cab1.add(&sw6);
    cab1.add(&sw7);
    cab1.add(&sw8);
    std::cout << "# INITIAL" << std::endl;
    for (int i = 0; i < cab1.get_room_size(); i++)
        cab1.print(i);

    std::cout << "#SEARCH TEST" << std::endl;
    cab1.search(new int[5]{76, 98, 12, 5, 7})->print_info();

    cab1.del();
    cab1.del();
    cab1.del();
    cab1.sort();

    std::cout << "# DELETE AND SORT" << std::endl;
    for (int i = 0; i < cab1.get_room_size(); i++)
        cab1.print(i);

    std::cout << "# ARRAY TEST" << std::endl;
    const Switch** array = cab1.get_array();
    for (int i = 0; i < cab1.get_room_size(); i++)
        array[i]->print_info();

    return 0;
}
