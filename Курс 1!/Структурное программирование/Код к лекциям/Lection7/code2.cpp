#include <iostream>
#include <fstream>

int main() {
    int n1=72, n2;
    std::fstream f("1.bin", std::ios::binary|std::ios::out);
    f.write((char*)&n1, sizeof(n1));
    f.close();

    std::fstream f1("1.bin", std::ios::binary|std::ios::in);
    f1.read((char*)&n2, sizeof(n2));
    f1.close();

    std::cout << (char) n2 << std::endl;
    return 0;
}