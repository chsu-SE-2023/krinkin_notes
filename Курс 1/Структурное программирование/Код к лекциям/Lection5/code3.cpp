#include <iostream>

void geron(double a, double b, double c, double &dest) {
    double p = (a + b + c) / 2;
    dest = sqrt(p*(p-a)*(p-b)*(p-c));
}

int main() {
    double a, b, c, d, e, d1, d2, s, s1, s2, s3;

    std::cout << "Set a, b, c, d, e, d1, d2:" << std::endl;
    std::cin >> a >> b >> c >> d >> e >> d1 >> d2;

    geron(e, a, d1, s1);
    geron(d1, b, d2, s2);
    geron(d2, c, d, s3);

    s = s1 + s2 + s3;

    std::cout << "s = " << s << std::endl;

    return 0;
}