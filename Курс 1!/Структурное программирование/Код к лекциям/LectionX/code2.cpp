#include <iostream>

struct Stack {
  char data[1000];
  int top;
};

void nullStack(Stack &st) { st.top = -1; }

void push(Stack &st, int value) { st.data[++st.top] = value; }

int pop(Stack &st) { return st.data[st.top--]; }

bool empty(Stack &st) { return st.top == -1; }

int main() {
  std::string s = "(()())((()))()";
  Stack st;
  nullStack(st);
  bool flag = true;

  for (int i = 0; i < s.length() && flag; i++) {
    switch (s[i]) {
    case '(': {
      push(st, s[i]);
      break;
    }
    case ')': {
      if (!empty(st)) {
        pop(st);
      } else {
        flag = false;
      }
      break;
    }
    }
  }

  if (flag && empty(st)) {
    std::cout << "YES!" << std::endl;
  } else {
    std::cout << "NO!" << std::endl;
  }

  return 0;
}
