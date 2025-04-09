#include <iostream>
#include <fstream>

int main() {

    FILE *f;
    const int n=5;
    f = fopen("2.bin", "wb");
    int a[n] = {9, 42, 120, 52, 31};
    fwrite(&a, sizeof(a), 1, f);
    fclose(f);
    
    f = fopen("2.bin", "rb");
    int b[n];
    fread(&b, sizeof(b), 1, f);
    fclose(f);

    for (int i=0;i<n;i++) {
        std::cout << b[i] << std::endl;
    }

    return 0;
}