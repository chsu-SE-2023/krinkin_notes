//VARIANT 15

#include <iostream>

int main() {

	// Const

	double x = 23;
	double y = 20;
	double z = 2;

	double t = abs(pow(x, (y/x)) - sqrt(y/x));
	double u = (y - x) * ((y - (z / (y - x) / (1 + pow(y - x, 2)))));

	std::cout << "\nConst:\n";
	std::cout << "t = " << t << "\nu = " << u << std::endl;

	// C++ IO
	std::cout << "\nC++ IO:\n";

	std::cout << "x = "; std::cin >> x;
	std::cout << "y = "; std::cin >> y;
	std::cout << "z = "; std::cin >> z;

	t = abs(pow(x, (y / x)) - sqrt(y / x));
	u = (y - x) * ((y - (z / (y - x) / (1 + pow(y - x, 2)))));

	std::cout << "t = " << t << std::endl;
	std::cout << "u = " << u << std::endl;

	// C IO

	std::cout << "\nC IO:\n";

	printf("x = "); scanf("%lf", &x);
	printf("y = "); scanf("%lf", &y);
	printf("z = "); scanf("%lf", &z);

	t = abs(pow(x, (y / x)) - sqrt(y / x));
	u = (y - x) * ((y - (z / (y - x) / (1 + pow(y - x, 2)))));

	printf("t = %lf\n", t); 
	printf("u = %lf\n", u);

	return 0;
}