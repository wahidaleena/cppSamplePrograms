#include <iostream>

using namespace std;

class Animals
{
	public:
		virtual void sound()
		{
			cout << "This is parent class" << endl;
		}
};

class Dogs : public Animals
{
	public:
		virtual void sound()
		{
			cout << "Dogs bark" << endl;
		}
};

int main()
{
	Animals *a;
	Dogs b;
	a = &b;
	a->sound();
	return 0;
}