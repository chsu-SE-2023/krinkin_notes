// Variant 15

#include <iostream>

int main() {

    int program_num;

    std::cout << "Program number: "; std::cin >> program_num;
    switch (program_num) 
    {
        case 1:
            double a, b;
            std::cout << "a = "; std::cin >> a;
            std::cout << "b = "; std::cin >> b;

            if (b <= a) b = 0;
            
            std::cout << std::endl;
            std::cout << "a = " << a << std::endl << "b = " << b << std::endl;
            break;
        case 2:
            double c;
            std::cout << "a = "; std::cin >> a;
            std::cout << "b = "; std::cin >> b;
            std::cout << "c = "; std::cin >> c;

            std::cout << std::endl;
            if (a >= 0) a = pow(a, 3); std::cout << "a = " << a << std::endl;
            if (b >= 0) b = pow(b, 3); std::cout << "b = " << b << std::endl;
            if (c >= 0) c = pow(c, 3); std::cout << "c = " << c << std::endl;
            break;
        case 3:
            double x = 1.825;
            double y = 18;
            double z = -3.298;

            double t = abs(pow(x,y/x)-sqrt(y-x));
            double u = (y-x)*((y-(z/(y-x)))/(1+pow(y-z,2)));

            std::cout << "t = " << t << std::endl;
            std::cout << "u = " << u << std::endl;

            if (t>u) std::cout << "True" << std::endl;
            if (t<u) std::cout << "False" << std::endl;
            break;
    }

    return 0;
}