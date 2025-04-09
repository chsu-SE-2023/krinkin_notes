#include <iostream>
#include <string>

int main() {
    std::string str = "MAXIMUS";
    std::string new_str = "";

    for (int i=0;i<str.length();i++) {
        new_str=str[i]+new_str;
    }

    std::cout << new_str << std::endl; 

    return 0;
}