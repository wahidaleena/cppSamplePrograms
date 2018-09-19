#include <stdlib.h>
#include <iostream>

class Test
{
	public:
		Test( long inVal )
			: mVal( inVal ){}

		long TimesOne() const;
		long TimesTwo() const;
		long TimesThree() const;
	private:
		long mVal;
};

typedef long (Test::*Multiplier)() const;

int main( int argc, char **argv )
{
	using std::cerr;
	using std::endl;
	using std::cout;

	if ( argc != 3 ){
		cerr  << "Usage: PtrTest value factor"  << endl;
		return 1;
	}

	Multiplier funcPtr;

	switch( atol( argv[ 2 ] ) ){
		case 1:
			funcPtr = &Test::TimesOne;
			break;
		case 2:
			funcPtr = &Test::TimesTwo;
			break;
		case 3:
			funcPtr = &Test::TimesThree;
			break;
		default:
			cerr << "PtrTest: factor must range from 1 to 3"  << endl;
			return 1;
	}

	cout  << "sizeof( funcPtr )="  << sizeof( funcPtr )  << endl;

	Test myTest( atol( argv[ 1 ] ) );

	cout << "result="  << (myTest.*funcPtr)()  <<endl;

	return 0;
}

long Test::TimesOne() const
{
	return mVal;
}

long Test::TimesTwo() const
{
	return 2 * mVal;
}

long Test::TimesThree() const
{
	return 3 * mVal;
}