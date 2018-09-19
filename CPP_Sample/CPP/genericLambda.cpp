#include <iostream>

struct unnamed_lambda
{
  template<typename T, typename U>
    auto operator()(T x, U y) const {return x + y;}
};

int main()
{

auto lambda = unnamed_lambda{};
}