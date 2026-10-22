#include <iostream>

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int main() {
    const int a = 100;
    char str[a] = "SOME BEAUTIFUL STRING :)";
    char new_str[a];
    int len = strlen(str);

    std::cout << str << std::endl;

    for (int i=0;i<len;i++) {
        new_str[len-i-1] = str[i];
    }
    std::cout << "DUMB WAY: " << new_str << std::endl;

    new_str[len] = '\0';

    char *func_str = strrev(str);
    std::cout << "FUNC WAY: " << func_str << std::endl; 

    char *str1;
    strcpy(str1, strrev(str));
    std::cout << str1 << std::endl;

    return 0;
}