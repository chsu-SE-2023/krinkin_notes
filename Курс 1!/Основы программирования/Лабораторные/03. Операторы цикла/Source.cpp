// Variant 15

#include <iostream>
#include <string>

int main(){

    int number, n, count, x, k, tmp = 0;
    double res = 1;

    std::cout << "Program number: "; std::cin >> number;

    switch (number){

        case 1:
            std::cout << "N = "; std::cin >> n;

            // Циклом for
            std::cout << "* for: " << std::endl;
            count = 0;
            for (int i=1000;i<n;i++) {
                int num = i;
                int orig_num = num;
                bool has7 = 0;
                bool has9 = 0;
                if (num % 45 == 0) {
                    for (num /= 10;num / 10 != 0;num /= 10) {
                        if (num % 10 == 7) has7 = 1;
                        if (num % 10 == 9) has9 = 1;
                    }
                    if (has7 & has9) {
                        count++; 
                        std::cout << orig_num << std::endl;
                    }
                }
            }

            std::cout << "Numbers: " << count << std::endl;

            // Циклом while
            std::cout << "* while: " << std::endl;
            count = 0;
            tmp = 1000;
            while (tmp < n) {
                int num = tmp;
                int orig_num = num;
                bool has7 = 0;
                bool has9 = 0;
                if (num % 45 == 0) {
                    num /= 10;
                    while (num / 10 != 0) {
                        if (num % 10 == 7) has7 = 1;
                        if (num % 10 == 9) has9 = 1;
                        num /= 10;
                    }
                    if (has7 & has9) {
                        count++; 
                        std::cout << orig_num << std::endl;
                    }
                }
                tmp++;
            }
            std::cout << "Numbers: " << count << std::endl;

            break;
        
        case 2:
            std::cout << "x = "; std::cin >> x;
            std::cout << "k = "; std::cin >> k;

            for (int n1=2;n1<=k;n1++){
                res *= (sin(2*n1-1) * pow(x,n1))/(pow(2*n1-1,2));
            }
            std::cout << "Z = " << res << std::endl;
            break;
    }
    return 0;
}