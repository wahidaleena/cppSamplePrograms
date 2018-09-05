#include "iostream"

using namespace std;

int main()
{
char *    a = u8"string";   // UTF-8 string
char16_t* b = u"string";    // UTF-16
char32_t* c = U"string";    // UTF-32
char*     r = R"string";    // raw string
}
