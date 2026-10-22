#include <iostream>
#include <fstream>

int main() {

    FILE *f;
    f = fopen("1.bin", "wb");
    int a = 120;
    fwrite(&a, sizeof(a), 1, f);
    fclose(f);
    
    f = fopen("1.bin", "rb");
    int b;
    fread(&b, sizeof(b), 1, f);
    fclose(f);

    std::cout << b << std::endl;

    return 0;
}