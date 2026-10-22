#include <iostream>

struct person {
    std::string name;
    int age;
};

int main() {
    person per;
    per.age = 18;
    per.name = "Саня";
    std::cout << per.name << " " << per.age << std::endl;
    return 0;    
}