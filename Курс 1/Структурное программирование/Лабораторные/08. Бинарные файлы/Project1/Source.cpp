#include <iostream>
#include <fstream>

void file_gen(std::fstream &file) {
	srand(time(0));
	int count = 2 + rand() % 98;
	for (int i = 0; i < count; i++) {
		int num = rand() % 10;
		file.write((char*)&num, sizeof(num));
	}
}

void file_read(std::fstream& file) {
	file.seekg(0, std::ios::end);
	int size = (int)file.tellg();
	file.seekg(0, std::ios::beg);
	while (file.tellg() < size) {
		int num;
		file.read((char*)&num, sizeof(num));
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

void if_read(std::fstream& file, int request) {
	file.seekg(0, std::ios::end);
	int size = (int)file.tellg();
	file.seekg(0, std::ios::beg);
	int sum = 0;
	while (file.tellg() < size) {
		int num;
		file.read((char*)&num, sizeof(num));
		if (num == request) {
			sum++;
		}
	}
	std::cout << "Count: " << sum << std::endl;
}

void arr_gen(std::fstream& file, int size) {
	int** arr = new int* [size];
	for (int i = 0; i < size; i++) arr[i] = new int[size];
	srand(time(0));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) arr[i][j] = rand() % 10;
		file.write((char*) arr[i], sizeof(int) * size);
	}
}

int** arr_read(std::fstream& file, int size) {
	int** arr = new int* [size];
	for (int i = 0; i < size; i++) arr[i] = new int[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) file.read((char*)&arr[i][j], sizeof(int));
	return arr;
}

void even_arr(std::fstream& file, int **array, int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (array[i][j] % 2 == 0) file.write((char*)&array[i][j], sizeof(array[i][j]));
}

int main() {
	int n;
	std::cout << "Program number: "; std::cin >> n;
	switch (n) {
	case 1: {
		std::fstream f("file.bin", std::ios::binary | std::ios::out);
		file_gen(f);
		f.close();

		std::fstream f1("file.bin", std::ios::binary | std::ios::in);
		file_read(f1);
		int num;
		std::cout << "Enter int: "; std::cin >> num;
		if_read(f1, num);
		f1.close();
		break;
	}
	case 2: {
		const int size = 3;
		std::fstream f("f.bin", std::ios::binary | std::ios::out);
		arr_gen(f, size);
		f.close();

		int** arr;
		std::fstream f1("f.bin", std::ios::binary | std::ios::in);
		arr = arr_read(f1, size);
		f1.close();

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) std::cout << arr[i][j] << " ";
			std::cout << std::endl;
		}

		std::fstream f2("g.bin", std::ios::binary | std::ios::out);
		even_arr(f2, arr, size);
		f2.close();
	}
	}

	return 0;
}