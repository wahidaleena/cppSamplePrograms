#include "iostream"

using namespace std;


struct Point {
    Point() {}
    Point(int x, int y): x_(x), y_(y) {} 
    int x_, y_;
};

union U {
    int z;
    double w;
    Point p; // Invalid in C++03; valid in C++11.
    U() {} // Due to the Point member, a constructor definition is now needed.
    U(const Point& pt) : p(pt) {} // Construct Point object using initializer list.
    U& operator=(const Point& pt) { new(&p) Point(pt); return *this; } // Assign Point object using placement 'new'.
};

int main()
{
}
