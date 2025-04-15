#include <iostream>
#include <random>

class Queue {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head, * tail;

public:
    Queue() {
        head = NULL;
        tail = NULL;
    }

    bool is_empty() const {
        return head == NULL;
    }

    void print() const {
        if (!is_empty()) {
            Node* tmp = head;
            while (tmp->next) {
                std::cout << tmp->data << " ";
                tmp = tmp->next;
            }
            std::cout << tmp->data << std::endl;
        }
        else {
            std::cout << "Empty" << std::endl;
        }
    }

    void add(int value) {
        if (is_empty()) {
            head = new Node;
            head->data = value;
            head->next = NULL;
            tail = head;
        }
        else {
            tail->next = new Node;
            tail = tail->next;
            tail->data = value;
            tail->next = NULL;
        }
    }

    int remove() {
        if (is_empty()) {
            std::cout << "Queue is empty";
            return NULL;
        }
        int d = head->data;
        Node* tmp = head;
        head = head->next;
        delete(tmp);
        return d;
    }

    void clear() {
        Node* tmp;
        while (!is_empty()) {
            tmp = head;
            head = head->next;
            delete(tmp);
        }
    }

};

class ArrayQueue {
private:
    int head, tail, size;
    int* data;

    int next(int n) const {
        return (n + 1) % size;
    }

public:
    ArrayQueue(int capacity) {
        size = capacity + 1;
        data = new int[size];
        clear();
    }

    bool is_empty() const {
        return next(tail) == head;
    }

    void print() const {
        if (!is_empty()) {
            for (int i = 0; i < next(tail); i++)
                std::cout << data[i] << " ";
            std::cout << std::endl;
        }
        else {
            std::cout << "Empty" << std::endl;
        }
    }

    void add(int value) {
        if (next(next(tail)) == head) {
            std::cout << "Queue overflow";
        }
        else {
            tail = next(tail);
            data[tail] = value;
        }
    }

    int remove() {
        if (is_empty()) {
            std::cout << "Queue is empty";
            return NULL;
        }

        int d = data[head];
        head = next(head);
        return d;
    }

    void clear() {
        head = 0;
        tail = size - 1;
    }
};

class Stack {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* top;

public:

    Stack() {
        top = NULL;
    }

    bool is_empty() const {
        return top == NULL;
    }

    void print() const {
        if (!is_empty()) {
            Node* tmp = top;
            while (tmp->next) {
                std::cout << tmp->data << " ";
                tmp = tmp->next;
            }
            std::cout << tmp->data << std::endl;
        }
        else {
            std::cout << "Empty" << std::endl;
        }
    }

    void push(int value) {
        Node* tmp = new Node;
        tmp->next = top;
        top = tmp;
        top->data = value;
    }

    int pop() {
        if (!is_empty()) {
            Node* tmp = top;
            int d = top->data;
            top = top->next;
            delete(tmp);
            return d;
        }
        return NULL;
    }

    void clear() {
        Node* tmp;
        while (!is_empty()) {
            tmp = top;
            top = top->next;
            delete(tmp);
        }
    }
};

class ArrayStack {
private:
    int top;
    int* data;
    int used;
    int capacity;

public:
    ArrayStack(int size) {
        data = new int[size];
        capacity = size;
        top = -1;
    }

    bool is_empty() const {
        return top == -1;
    }

    bool is_full() const {
        return top >= capacity;
    }

    void print() const {
        if (!is_empty()) {
            for (int i = top - 1; i >= 0; i--)
                std::cout << data[i] << " ";
            std::cout << std::endl;
        }
        else {
            std::cout << "Empty" << std::endl;
        }
    }

    void push(int value) {
        if (is_full()) {
            std::cout << "Stack overflow!";
        }
        else {
            data[++top] = value;
        }
    }

    int pop() {
        if (!is_empty()) {
            return data[top--];
        }
        return NULL;
    }

    void clear() {
        top = -1;
    }
};

// =========================================================================

// Динамическими списками
void task(Queue queue1, Queue queue2, Stack stack) {

    // Заполнение
    for (int i = 0; i < rand() % 1000; i++)
        queue1.add(rand() % 100);
    for (int i = 0; i < rand() % 1000; i++)
        queue2.add(rand() % 100);

    // Вывод очередей на экран
    std::cout << " - Queue 1: ";
    queue1.print();
    std::cout << " - Queue 2: ";
    queue2.print();

    // Поиск минимума
    int min = queue2.remove();
    while (!queue2.is_empty()) {
        int elem = queue2.remove();
        if (elem < min)
            min = elem;
    }
    std::cout << " - Queue 2 min: " << min << std::endl;

    // Формирование стека по условию
    while (!queue1.is_empty()) {
        int elem = queue1.remove();
        if (min != 0) {
            if (elem % min == 0)
                stack.push(elem);
        }
    }
    std::cout << " - Stack: ";
    stack.print();
}

// Массивами
void task(ArrayQueue queue1, ArrayQueue queue2, ArrayStack stack) {

    // Заполнение
    for (int i = 0; i < rand() % 1000; i++)
        queue1.add(rand() % 100);
    for (int i = 0; i < rand() % 1000; i++)
        queue2.add(rand() % 100);

    // Вывод очередей на экран
    std::cout << " - Queue 1: ";
    queue1.print();
    std::cout << " - Queue 2: ";
    queue2.print();

    // Поиск минимума
    int min = queue2.remove();
    while (!queue2.is_empty()) {
        int elem = queue2.remove();
        if (elem < min)
            min = elem;
    }
    std::cout << " - Queue 2 min: " << min << std::endl;

    // Формирование стека по условию
    while (!queue1.is_empty()) {
        int elem = queue1.remove();
        if (min != 0) {
            if (elem % min == 0)
                stack.push(elem);
        }
    }
    std::cout << " - Stack: ";
    stack.print();
}

int main() {

    srand(time(0));

    // Динамическими списками
    std::cout << "* Dynamic lists:" << std::endl;
    Queue q1;
    Queue q2;
    Stack s;

    task(q1, q2, s);
    std::cout << std::endl;

    // Массивами
    std::cout << "* Arrays:" << std::endl;
    ArrayQueue aq1 = ArrayQueue(0);
    ArrayQueue aq2 = ArrayQueue(0);
    ArrayStack as = ArrayStack(0);

    task(aq1, aq2, as);

    return 0;
}