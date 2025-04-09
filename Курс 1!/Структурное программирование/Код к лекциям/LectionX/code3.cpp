#include <iostream>

class Stack {
private:
  char data[1000];
  int top;

public:
  Stack() { top = -1; }

  void nullStack() { top = -1; }

  void push(int value) { data[++top] = value; }

  int pop() { return data[top--]; }

  bool empty() { return top == -1; }
};

int main() {
  std::string s = "([()])";
  Stack st;
  bool flag = true;

  for (int i = 0; i < s.length() && flag; i++) {
    switch (s[i]) {
    case '(': {
    case '[':
      st.push(s[i]);
      break;
    }
    case ')': {
      if (st.empty() || st.pop() != '(') {
        flag = false;
      }
      break;
    }
    case ']': {
      if (st.empty() || st.pop() != '[') {
        flag = false;
      }
      break;
    }
    }
  }

  if (flag && st.empty()) {
    std::cout << "YES!" << std::endl;
  } else {
    std::cout << "NO!" << std::endl;
  }

  return 0;
}
