#include <iostream>
auto f(auto i) {
  return "";
}

int main() {
  const char *s = f(1);
  return 0;
}