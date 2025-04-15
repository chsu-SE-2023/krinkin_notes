#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <deque>

struct Cell {
	int x;
	int y;
	int weight;
	Cell* parent;
	Cell(int x, int y, int w, Cell* p) { // Конструктор
		this->x = x; this->y = y; weight = w; parent = p;
	}
};

// Возвращает не посещены ли повторно уже посещённые столбцы / строки
bool is_valid(Cell* cell, int size) {
	bool* visited_x = new bool[size]();
	bool* visited_y = new bool[size]();
	bool valid = true;
	while (cell->parent != nullptr) {
		//if (cell->x != cell->parent->x) visited_x[cell->x] = true;
		if (cell->y != cell->parent->y) visited_y[cell->y] = true;
		//if (visited_x[cell->parent->x]) valid = false;
		if (visited_y[cell->parent->y]) valid = false;
		cell = cell->parent;
	}
	return valid;
}

Cell* get_path(int** matrix, int n) {
	int center = n / 2;
	int directions[4][2] = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}}; // Вверх Вниз Влево Вправо
	int min_sum = INT_MAX;
	Cell* best_path = nullptr;

	std::deque<Cell*> queue;

	Cell* c_center = new Cell(center, center, matrix[center][center], nullptr);
	queue.push_back(c_center);

	// Просчёт ячеек
	while (!queue.empty()) {
		Cell* cell = queue.front();
		queue.pop_front();

		if (cell->x == 0 || cell->y == 0 || cell->x == n - 1 || cell->y == n - 1) { // Края массива
			if (cell->weight < min_sum) {
				min_sum = cell->weight;
				best_path = cell;
			}
			continue;
		}

		// Проход по возможным направлениям
		for (int i = 0; i < 4; i++) {
			int nx = cell->x + directions[i][0];
			int ny = cell->y + directions[i][1];

			if (0 <= nx < n && 0 <= ny < n && is_valid(cell, n)) { // Не край ли и валиден ли путь?
				Cell* new_cell = new Cell(nx, ny, cell->weight + matrix[nx][ny], cell);
				queue.push_back(new_cell);
			}
		}
	}
	return best_path;
}

int main() {

	std::ifstream file("input.txt");
	if (!file.is_open()) {
		std::cout << "input.txt cannot be opened!" << std::endl;
		return 255;
	}
	
	int size;
	file >> size;

	if (size % 2 == 0) {
		std::cout << "Array size must be odd!" << std::endl;
		return 255;
	}
	
	int** array = new int* [size]();
	for (int i = 0; i < size; i++)
		array[i] = new int[size];
	std::string line;

	// Преобразование содержимого файла в массив
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			file >> array[i][j];
	file.close();

	Cell* path_end = get_path(array, size);

	std::cout << "Min path: " << path_end->weight << std::endl;
	
	// Карта пройденного пути
	bool** path = new bool* [size](); 
	for (int i = 0; i < size; i++)
		path[i] = new bool[size]();
	while (path_end->parent != nullptr) {
		path[path_end->x][path_end->y] = true;
		path_end = path_end->parent;
	}
	path[path_end->x][path_end->y] = true;

	// Вывод пути по карте
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (path[i][j]) std::cout << "\033[0;31m" << array[i][j] << "\033[0m ";
			else std::cout << array[i][j] << " ";

		}
		std::cout << std::endl;
	}
	return 0;
}

