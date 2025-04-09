#include "some_class.h"
#include <iostream>

Pixel::Pixel() {
    x = 1;
    y = 1;
    mas = 1.1;
    color = "green";
}
Pixel::Pixel(int a, int b, char *c, float m) {
    x = a;
    y = b;
    mas = m;
    color = new char[strlen(c)+1];
    strcpy(color, c);
}
Pixel::Pixel(const Pixel &m) {
    x = m.x;
    y = m.y;
    mas = m.mas;
    color = new char[strlen(m.color)+1];
    strcpy(color, m.color);
}
Pixel::Pixel(int x) { x = x; }
Pixel::Pixel(float f) { mas = f; };
Pixel::Pixel(char c) { color = new char; };
Pixel::Pixel(char* c) { color = new char[strlen(c)+1]; }

int Pixel::get_x() const { return x; }
char* Pixel::get_color() const { return color; }
float Pixel::get_mas() const { return mas; };
void Pixel::set_x(int a) { x = a; };
void Pixel::set_y(int b) { y = b; };
void Pixel::set_color(char* c) { color = c; };
void Pixel::set_mas(float m) { mas = m; };
Pixel& Pixel::copy(const Pixel& m) {
    if (this != &m) {
        return (*this);
    }
    x = m.x;
    y = m.y;
    mas = m.mas;
    delete []color;
    color = new char[strlen(m.color)+1];
    strcpy(color, m.color);
}
Pixel Pixel::summa(Pixel a) {
    Pixel h;
    h.x = x + a.x;
    h.y = x + a.y;
    h.mas = mas + a.mas;
    h.color = new char[strlen(a.color)+1]; 
    strcpy(h.color, color);
    strcat(h.color, a.color);
    return h;
}