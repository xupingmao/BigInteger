#include "BigInteger.h"
#include "BigInteger.cpp"

int main(int argc, char const* argv[]) {
	BigInteger a ("100");
	BigInteger b ("456");
	
	BigInteger c ("0");
	c = a + b;
	cout << c.GetValue() << endl;
	
	c = a - b;
	cout << c.GetValue() << endl;
	
	c = a * b;
	cout << c.GetValue() << endl;
	
	c = a / b;
	cout << c.GetValue() << endl;
	
	return 0;
}
