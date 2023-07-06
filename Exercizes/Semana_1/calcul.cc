#include <iostream>
using namespace std;

int main()
{
	int x;
	double y;
	double a(0), b(0), c(0), d(0);

	x = 2;
	y = 4;
	a = x + y;	//suma
	b = x - y;	//resta
	c = x * y;	//producto
	d = x / y;	//division
	
	cout << "Depsues de varios calculos he obtenido: " << endl;
	cout << "- suma: " << a << endl;
	cout << "- resta: " << b << endl;
	cout << "- producto: " << c << endl;
	cout << "- division: " << d << endl;

	return 0;
}
