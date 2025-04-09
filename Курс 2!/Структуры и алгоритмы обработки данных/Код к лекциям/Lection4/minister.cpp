#include <iostream>
#include <fstream>

int main() {

    std::ifstream f("taxes.txt");
    const int max_n = 100, max_m = 500;
    int current_floor[max_m];
    int best_floor[max_m];
    int direction[max_n][max_m];
    int n, m;
    f >> n >> m;
    for (int j = 0; j < m; j++) best_floor[j] = 0;
    for (int j = 0; j < m; j++) best_floor[j] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f >> current_floor[j];
            // Заходим на i-ый этаж снизу
            best_floor[j] += current_floor[j];
        }

        // Заходим в j-ый кабинет слева
        for (int j = 1; j < m; j++) {
            if (best_floor[j - 1] + current_floor[i] < best_floor[j]) {
                best_floor[j] = best_floor[j - 1] + current_floor[j];
                direction[i][j] = -1;
            }
        }

        // Заходим в j-ый кабинет справа
        for (int j = m-2; j >= 0; j++) {
            if (best_floor[j + 1] + current_floor[i] < best_floor[j]) {
                best_floor[j] = best_floor[j + 1] + current_floor[j];
                direction[i][j] = 1;
            }
        }
    }
    f.close();

    int min_j = 0;
    for (int j = 1; j < m; j++)
        if (best_floor[j] < best_floor[min_j]) min_j = j;

    std::cout << best_floor[min_j] << std::endl;

    return 0;
}