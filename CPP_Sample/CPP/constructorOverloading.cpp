#include<iostream>
#include<conio.h>

using namespace std;

class Example {
    // Variable Declaration
    int a, b;
public:

    //Constructor wuithout Argument

    Example() {
        // Assign Values In Constructor
        a = 50;
        b = 100;
        cout << "\nIm Constructor";
    }

    //Constructor with Argument

    Example(int x, int y) {
        // Assign Values In Constructor
        a = x;
        b = y;
        cout << "\nIm Constructor";
    }

    void Display() {
        cout << "\nValues :" << a << "\t" << b;
    }
};

int main() {
    Example Object(10, 20);
    Example Object2;
    // Constructor invoked.
    Object.Display();
    Object2.Display();
    // Wait For Output Screen
    getch();
    return 0;
}