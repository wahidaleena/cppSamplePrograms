#include <iostream>
#include <object.h>
using namespace std;

 int main()
 {
      Test o1, o2;
      float secondDataOfObject2;

      o1.insertIntegerData(12);
      secondDataOfObject2 = o2.insertFloatData();

      cout << "You entered " << secondDataOfObject2;
      return 0;
 }