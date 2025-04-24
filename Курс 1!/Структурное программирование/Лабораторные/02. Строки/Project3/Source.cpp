#include <iostream>
#include <sstream>
#include <windows.h>

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char str[100];
	char seps[2] = ",";
	int lenght;

	std::cout << "¬ведите строку: "; gets_s(str);
	std::cout << "¬ведите длину: "; std::cin >> lenght;

	char* token = strtok(str, seps);

	while (token != NULL) {
		if (strlen(token) < lenght) {
			std::cout << token << std::endl;
		}
		token = strtok(NULL, seps);
	}

	return 0;
}