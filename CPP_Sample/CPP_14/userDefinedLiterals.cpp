#include <iostream>
int main()
{

auto str = "hello world"s; // auto deduces string
auto dur = 60s;            // auto deduces chrono::seconds
auto z   = 1i;             // auto deduces complex<double>
}
