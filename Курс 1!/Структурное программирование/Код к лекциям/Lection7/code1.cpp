#include <iostream>
#include <fstream>

int main() {
    std::ofstream f("1.txt");
    for (int i=1;i<=10;i++) {
        f << i << ". Kostya crocodile" << std::endl;
    }
    f.close();


    std::string str;
    std::ifstream f1("1.txt");
    while (!f1.eof()) {
        getline(f1, str);
        std::cout << str << std::endl;
    } 

    std::cout << std::endl;
    return 0;
}