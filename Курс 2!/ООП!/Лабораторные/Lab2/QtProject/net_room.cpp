#include "net_room.h"
#include <iostream>

ServerRoom::ServerRoom() {
    /*
     * Конструктор по умолчанию - создаёт пустую первую "полку".
     */
    this->first = new Shelf;
    this->first->device = nullptr;
    this->first->next = nullptr;
    this->last = this->first;
}

ServerRoom::ServerRoom(const Switch* device) {
    /*
     * Конструктор по умолчанию - создаёт первую "полку" с объектом Switch.
     */
    this->first = new Shelf;
    this->first->device = device;
    this->first->next = nullptr;
    this->last = this->first;
}

ServerRoom::~ServerRoom() {
    /*
     * Декоструктор - удаляет все структуры-"полки", не затронув хранящиеся
     * в них объекты типа Switch.
     */
    Shelf* current = this->first;
    Shelf* to_delete = nullptr;
    while (current->next != nullptr) {
        to_delete = current;
        current = current->next;
        delete to_delete;
    }
    delete current;
}

ServerRoom::Shelf* ServerRoom::get_shelf(int shelf_id) {
    /*
     * Функция возвращает указатель на "полку" под некоторым номером.
     * (приватна)
     */
    Shelf* shelf = this->first;
    for (int i = 0; i < shelf_id; i++) {
        if (shelf != nullptr)
            shelf = shelf->next;
    }
    return shelf;
}

void ServerRoom::add(const Switch* device) {
    /*
     * Функция добавляет "полку" в конец комнаты.
     */
    this->last->next = new Shelf;
    this->last->next->device = device;
    this->last = this->last->next;
    this->last->next = nullptr;
}

void ServerRoom::del() {
    /*
     * Функция удаляет последнюю "полку".
     */
    Shelf* prev = get_shelf(get_room_size() - 1);
    prev->next = nullptr;
    delete this->last;
    this->last = prev;
}

void ServerRoom::print(int shelf_id) {
    /*
     * Функция печатает в консоли информацию о "полке" и её содержимом.
     */
    Shelf* shelf = get_shelf(shelf_id);
    if (shelf != nullptr && shelf->device != nullptr) {
        std::cout << " * Shelf " << shelf_id << " device info:" << std::endl;
        shelf->device->print_info();
    } else {
        std::cout << " * Shelf " << shelf_id << " is empty!" << std::endl;
    }
}

void ServerRoom::sort() {
    /*
     * Функция сортирует объекты Switch по количеству поключенных устройств 
     * по возрастанию.
     */
    int room_size = get_room_size();
    for (int i = 0; i < room_size; i++)
        for (int j = 0; j < room_size - 1 - i; j++) {
            Shelf* current = get_shelf(j);
            if (current->device->clients_count() > current->next->device->clients_count()) {
                const Switch* tmp;
                tmp = current->next->device;
                current->next->device = current->device;
                current->device = tmp;
            }
        }
}

const Switch* ServerRoom::search(int* address) {
    /*
     * Функция поиска объекта Switch по адресу. Возвращает адрес объекта
     * или nullptr, если объект не найден.
     */
    Shelf* current = this->first;
    while (current->next != nullptr) {
        for (int i = 0; i < 5; i++) {
            if (current->device->get_address()[i] != address[i]) {
                current = current->next;
                continue;
            }
        }
        return current->device;
    }
    return nullptr;
}

int ServerRoom::get_room_size() {
    /*
     * Функция возвращает количество "полок" в комнате.
     */
    int count = 0;
    Shelf* current = this->first;
    while (current->next != nullptr) {
        if (current != nullptr)
            current = current->next;     
    count++;
    }
    return count;
}

const Switch* ServerRoom::get_device(int shelf_id) {
    /*
     * Функция возвращает указатель на объект Switch указанной "полки".
     */
    Shelf* shelf = get_shelf(shelf_id);
    return shelf->device;
}

const Switch** ServerRoom::get_array() {
    /*
     * Функция возвращает массив указателей на объекты Switch.
     */
    int size = get_room_size();
    const Switch** array = new const Switch*[size];
    for (int i = 0; i < size; i++) {
        array[i] = get_device(i);
    }
    return array;
}
