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

ServerRoom::ServerRoom(Switch& device) {
    /*
     * Конструктор по умолчанию - создаёт первую "полку" с объектом Switch.
     */
    this->first = new Shelf;
    this->first->device = &device;
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

ServerRoom::Shelf* ServerRoom::get_shelf(ServerRoom* room, int shelf_id) {
    /*
     * Функция возвращает указатель на "полку" под некоторым номером.
     * (приватна)
     */
    Shelf* shelf = room->first;
    for (int i = 0; i < shelf_id; i++) {
        if (shelf != nullptr)
            shelf = shelf->next;
    }
    return shelf;
}

ServerRoom& ServerRoom::operator+(Switch& device) {
    /*
     * Оператор добавляет "полку" в конец комнаты.
     */
    this->last->next = new Shelf;
    this->last->next->device = &device;
    this->last = this->last->next;
    this->last->next = nullptr;
    return *this;
}

ServerRoom& ServerRoom::operator--(int count) {
    /*
     * Оператор удаляет последнее количество "полок".
     */
    for (int i = 0; i < count; i++) {
        Shelf* prev = get_shelf(this, get_room_size() - 1);
        prev->next = nullptr;
        delete this->last;
        this->last = prev;
    }
    return *this;
}

const Switch* ServerRoom::operator[](int index) {
    /*
     * Оператор возвращает указатель на объект Switch указанной "полки".
     */
    Shelf* shelf = get_shelf(this, index);
    return shelf->device;
}

bool operator==(ServerRoom& first, ServerRoom& second) {
    /*
     * Оператор проверяет равны ли две комнаты по размеру
     */
    return first.get_room_size() == second.get_room_size();
}

std::ostream& operator<<(std::ostream& stream, ServerRoom& room) {
    /*
     * Оператор печатает в консоль информацию обо всех устройствах в "комнате".
     */
    ServerRoom::Shelf* shelf = room.first;
    int size = room.get_room_size();
    for (int i = 0; i < size; i++) {
        ServerRoom::Shelf* shelf = room.get_shelf(&room, i);
        if (shelf != nullptr && shelf->device != nullptr) {
            stream << " * Shelf " << i << " device info:" << std::endl;
            shelf->device->print_info();
        } else
            stream << " * Shelf " << i << " is empty!" << std::endl;
        shelf = shelf->next;
    }
    return stream;
}

void ServerRoom::print(int shelf_id) {
    /*
     * Функция печатает в консоли информацию о "полке" и её содержимом.
     */
    Shelf* shelf = get_shelf(this, shelf_id);
    if (shelf != nullptr && shelf->device != nullptr) {
        std::cout << " * Shelf " << shelf_id << " device info:" << std::endl;
        shelf->device->print_info();
    } else
        std::cout << " * Shelf " << shelf_id << " is empty!" << std::endl;
}

void ServerRoom::sort() {
    /*
     * Функция сортирует объекты Switch по количеству поключенных устройств 
     * по возрастанию.
     */
    int room_size = get_room_size();
    for (int i = 0; i < room_size; i++)
        for (int j = 0; j < room_size - 1 - i; j++) {
            Shelf* current = get_shelf(this, j);
            if (current->device > current->next->device) { // Использован оператор меньше
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

const Switch** ServerRoom::get_array() {
    /*
     * Функция возвращает массив указателей на объекты Switch.
     */
    int size = get_room_size();
    const Switch** array = new const Switch*[size];
    for (int i = 0; i < size; i++)
        array[i] = (*this)[i];
    return array;
}
