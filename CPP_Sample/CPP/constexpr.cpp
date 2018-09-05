#include <iostream>

using namespace std;
constexpr int g() { return 7; }  // OK
int main()
{
int b[5 + g()];    // create an array of 12 ints
}

