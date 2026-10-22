#include <iostream>
#include <fstream>

int main() {
    int num;
    std::cout << "Select method (1. C, 2. C++): ";
    std::cin >> num;

    switch (num) {
        case 1: {
            const int max = 1000; int count = 0;
            char line[max];
            FILE * file = fopen("rar.txt", "rt");

            while (fgets(line, max, file) != NULL) {
                int len = strlen(line);
                if (line[len - 1] == '\n') {
                    if (line[len - 2] == line[0]) count++;
                } else {
                    if (line[len - 1] == line[0]) count++;
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
                if (text[text.length() - 1] == '\n') {
                    if (text[text.length() - 2] == 'a') count++;
                } else {
                    if (text[text.length() - 1] == 'a') count++;
                }
            }

            std::cout << std::endl << "* Count of strings: " << count << std::endl;
            break;
        }
    }

    return 0;
}