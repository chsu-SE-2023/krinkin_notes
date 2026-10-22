#include <iostream>

int main() {
    std::string s = "(()())((()))()";
    char stack[1000];
    int top = -1;
    bool flag = true;

    for (int i=0; i<s.length() && flag; i++) {
        switch (s[i]) {
            case '(': {
                stack[++top] = s[i];
                break;
            }
            case ')': {
                if (top >= 0) {
                    top--;
                } else {
                    flag = false;
                }
                break;
            }
        }
    }

    if (flag && top == -1) {
        std::cout << "YES!" << std::endl;
    } else {
        std::cout << "NO!" << std::endl;
    }

    return 0;
}