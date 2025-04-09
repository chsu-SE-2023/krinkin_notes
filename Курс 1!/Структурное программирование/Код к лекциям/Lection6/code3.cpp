#include <iostream>
#include <fstream>

int main() {

    FILE *f;
    char *str = new char[100];
    f = fopen("3.bin", "rt");

    while (!feof(f)) {
        fgets(str, 100, f);
        // fscanf(f, "%s", str);
        std::cout << str; // << std::endl;
    }

    fclose(f);
    std::cout << std::endl;
    return 0;
}