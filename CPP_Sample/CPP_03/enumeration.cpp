#include "iostream"

using namespace std;

int main()
{
    enum Day {Sunday, Monday, Tuesday};
    enum Month {January, February, March};

    Day d = Monday;
    Month m = February;

    if (d == m)
	std::cout << "Monday == February\n";  // This will be printed out
    else
	std::cout << "Monday != February\n";
}
