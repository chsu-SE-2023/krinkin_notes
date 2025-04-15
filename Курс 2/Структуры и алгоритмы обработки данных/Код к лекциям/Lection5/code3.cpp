#include <iostream>
#include <fstream>

class MyGraph {
private:
    int gr[100][100]; // Можно заменить на динамический
    int metka[100];
    int n;
    int num;

    void obhod(int i) {
        metka[i] = num++;
        for (int j = 0; j < n; j++)
            if (gr[i][j] != 0 && metka[j] == 0)
                obhod(j);
    }

public:
    MyGraph(std::string name) {
        std::ifstream f(name);
        f >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                f >> gr[i][j];
        f.close();
        for (int i = 0; i < n; i++)
            metka[i] = 0;
    }

    void glubina() {
        num = 1;
        for (int i = 0; i < n; i++)
            if (metka[i] == 0)
                obhod(i);
    }

    void vivodMetka() {
        for (int i = 0; i < n; i++)
            std::cout << metka[i] << " ";
        std::cout << std::endl;
    }
};

int main() {
    MyGraph g("input.txt");
    g.glubina();
    g.vivodMetka();
    
    return 0;
}