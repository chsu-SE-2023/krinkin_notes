#include <iostream>
#include <iomanip>
#include <cstdarg>
#include <sstream>
#include <random>
#include <chrono>
#include <string>
#include <vector>

class Sorting {
private:
	std::vector<int> random;
	std::vector<int> sorted;
	std::vector<int> reverse;

	void pushDown(std::vector<int>& array, int root, int bottom) {
		int done = 0, maxChild;
		while ((root * 2 + 1 <= bottom) && (!done)) {
			if (root * 2 + 1 == bottom) maxChild = root * 2 + 1;
			else if (array[root * 2 + 1] > array[root * 2 + 2]) maxChild = root * 2 + 1;
			else maxChild = root * 2 + 2;
			if (array[root] < array[maxChild]) {
				std::swap(array[root], array[maxChild]);
				root = maxChild;
			}
			else done = 1;
		}
	}

public:

	Sorting(int size) {
		random = {};
		for (int i = 0; i < size; i++)
			random.push_back(rand() % 10);
		sorted = {};
		for (int i = 0; i < size; i++)
			sorted.push_back(i);
		reverse = {};
		for (int i = 1; i < size; i++)
			reverse.push_back(size - i);
	}

	// Функции для получения копий массивов
	std::vector<int> get_random() { return random; }
	std::vector<int> get_sorted() { return sorted; }
	std::vector<int> get_reverse() { return reverse; }

	// Вывод массива
	void print(std::vector<int>& array, int iter = -1) {
		if (iter != -1) { 
			std::cout.width(4);
			std::cout << std::to_string(iter) + ". ";
		}
		std::cout << "[ ";
		for (int el : array)
			std::cout << std::to_string(el) + " ";
		std::cout << ']' << std::endl;
	}

	double direct(std::vector<int>& array, bool demo = false) {
		auto t1 = std::chrono::steady_clock::now();
		int iter = 0;
		for (int i = 1; i < array.size(); i++) {
			int x = array[i], j = i;
			while (j != 0 && x < array[j - 1]) {
				// Demo print
				if (demo) this->print(array, iter++);
				array[j] = array[j - 1]; 
				j--;
			}
			array[j] = x;
		}
		// Demo print
		if (demo) this->print(array, iter++);
		auto t2 = std::chrono::steady_clock::now();
		std::chrono::duration<double, std::milli> dur = t2 - t1;
		return dur.count();
	}

	double shell(std::vector<int>& array, bool demo = false) {
		auto t1 = std::chrono::steady_clock::now();
		int iter = 0;
		int step = array.size() / 2;
		while (step > 0) {
			for (int i = 0; i < array.size() - step; i++) {
				int j = i;
				while (j >= 0 && array[j] > array[j + step]) {
					// Demo print
					if (demo) this->print(array, iter++);
					std::swap(array[j], array[j + step]);
					j -= step;
				}
			}
			step /= 2;
		}
		// Demo print
		if (demo) this->print(array, iter++);
		auto t2 = std::chrono::steady_clock::now();
		std::chrono::duration<double, std::milli> dur = t2 - t1;
		return dur.count();
	}

	double pyramid(std::vector<int>& array, bool demo = false) {
		auto t1 = std::chrono::steady_clock::now();
		int iter = 0;
		for (int i = array.size() / 2 - 1; i >= 0; i--) {
			// Demo print
			if (demo) this->print(array, iter++);
			pushDown(array, i, array.size() - 1);
		}
		for (int i = array.size() - 1; i >= 0; i--) {
			// Demo print
			if (demo) this->print(array, iter++);
			std::swap(array[0], array[i]);
			pushDown(array, 0, i - 1);
		}
		// Demo print
		if (demo) this->print(array, iter++);
		auto t2 = std::chrono::steady_clock::now();
		std::chrono::duration<double, std::milli> dur = t2 - t1;
		return dur.count();
	}
};

class Table {
private:
	char cell_ceil = 196;
	char cell_wall = 179;
	char cell_cross = 197;
	int cell_size;
	int width;
public:
	Table(int cell_size, int width) {
		this->cell_size = cell_size;
		this->width = width;
	}

	void print_ceiling() {
		std::cout << cell_cross;
		for (int i = 0; i < width; i++)
			std::cout << std::string(cell_size, cell_ceil) << cell_cross;
		std::cout << std::endl;
	}

	void print_header(std::vector<std::string> values) {
		std::cout << cell_wall;
		for (int i = 0; i < width; ++i) {
			std::cout.width(cell_size);
			std::cout << values[i];
			std::cout << cell_wall;
		}
		std::cout << std::endl;
	}

	void print_cell(std::string name, std::vector<double> values) {
		std::cout << cell_wall;
		std::cout.width(cell_size);
		std::cout << name << cell_wall;
		for (int i = 0; i < width-1; ++i) {
			std::ostringstream stream;
			stream.precision(3);
			stream << std::fixed << values[i];
			std::cout.width(cell_size);
			std::cout << stream.str() + "ms";
			std::cout << cell_wall;
		}
		std::cout << std::endl;
	}
};

int main() {
	srand(time(0));

	int d_size = 10;
	Sorting d_sorting(d_size);
	std::vector<int> d_input;
	std::cout << std::endl << "Direct sorting demo:" << std::endl;
	d_input = d_sorting.get_random();
	d_sorting.direct(d_input, true);
	std::cout << std::endl << "Shell sorting demo:" << std::endl;
	d_input = d_sorting.get_random();
	d_sorting.shell(d_input, true);
	std::cout << std::endl << "Pyramid sorting demo:" << std::endl;
	d_input = d_sorting.get_random();
	d_sorting.pyramid(d_input, true);
	
	int size = 0;
	std::cout << std::endl << "Input arrays size: "; std::cin >> size;
	Sorting sorting(size);
	std::vector<int> input;

	input = sorting.get_random();
	double r_direct = sorting.direct(input);
	input = sorting.get_sorted();
	double s_direct = sorting.direct(input);
	input = sorting.get_reverse();
	double v_direct = sorting.direct(input);

	input = sorting.get_random();
	double r_shell = sorting.shell(input);
	input = sorting.get_sorted();
	double s_shell = sorting.shell(input);
	input = sorting.get_reverse();
	double v_shell = sorting.shell(input);

	input = sorting.get_random();
	double r_pyramid = sorting.pyramid(input);
	input = sorting.get_sorted();
	double s_pyramid = sorting.pyramid(input);
	input = sorting.get_reverse();
	double v_pyramid = sorting.pyramid(input);

	std::cout << "Result table:" << std::endl;
	std::ostringstream stream;
	stream.precision(3);
	stream << std::fixed << std::max(
		{ r_direct,  s_direct,  v_direct,
		  r_shell,   s_shell,   v_shell,
		  r_pyramid, s_pyramid, v_pyramid
		});
	int cell_size = stream.str().size();
	Table table(cell_size + 2, 4);

	table.print_ceiling();
	table.print_header({ "", "Random", "Sorted", "Reverse" });
	table.print_ceiling();
	table.print_cell("Direct", { r_direct, s_direct, v_direct });
	table.print_ceiling();
	table.print_cell("Shell", { r_shell, s_shell, v_shell });
	table.print_ceiling();
	table.print_cell("Pyramid", { r_pyramid, s_pyramid, v_pyramid });
	table.print_ceiling();
	
	return 0;
}