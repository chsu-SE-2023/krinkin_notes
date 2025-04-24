#include <iostream>
#include <sstream>

struct AEROFLOT
{
	std::string destination;
	std::string out_date;
	std::string out_time;
};

int main() {
	setlocale(LC_ALL, "Russian");
	const int n = 5;
	AEROFLOT* arr[n];
	std::string buff;
	for (int i = 0;i < n;i++) {
		int num = i+1;
		arr[i] = new AEROFLOT;
		std::cout << "[—амолЄт " << num << "] ¬ведите место назначени€: "; std::getline(std::cin, arr[i]->destination);
		std::cout << "[—амолЄт " << num << "] ¬ведите дату и врем€ вылета самолЄта: "; std::cin >> arr[i]->out_date >> arr[i]->out_time;
		std::getline(std::cin, buff);
	}

	std::cout << std::endl;

	std::string needed;
	std::cout << "ѕункт назначени€: "; std::getline(std::cin, needed);

	int plane_num = 0;

	for (int i = 0; i < n;i++) {
		if (arr[i]->destination == needed) {
			int num = i + 1;
			std::cout << "—амолЄт " << num << " вылетает в " << arr[i]->out_date << " " << arr[i]->out_time << std::endl;
			plane_num++;
		}
	}

	if (!plane_num) {
		std::cout << "—амолЄты не найдены!" << std::endl;
	}

	return 0;
}