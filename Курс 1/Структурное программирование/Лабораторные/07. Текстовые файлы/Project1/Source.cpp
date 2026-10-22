#include <iostream>
#include <fstream>
#include <string>

int main() {
    int num;
    std::cout << "Select method (1. C, 2. C++): ";
    std::cin >> num;

    switch (num) {
    case 1: {
        int size = 100;
        FILE* file = fopen("file.txt", "rt");
        char* text = new char[size];
        int count = 0;

        while (!feof(file)) {
            fgets(text, size, file);
            if (text[strlen(text) - 1] == '\n') {
                if (text[strlen(text) - 2] == 'a') count++;
            }
            else {
                if (text[strlen(text) - 1] == 'a') count++;
            }

        }
        fclose(file);

        std::cout << std::endl << "* Count of strings: " << count << std::endl;
        break;
    }
    case 2: {
        std::string text;
        std::ifstream file("file.txt");
        int count = 0;

        while (!file.eof()) {
            getline(file, text);
            if (text[text.length() - 1] == 'a') count++;
        }

        std::cout << std::endl << "* Count of strings: " << count << std::endl;
        break;
    }
    }

    return 0;
}