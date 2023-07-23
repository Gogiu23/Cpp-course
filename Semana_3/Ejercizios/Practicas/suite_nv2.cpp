#include <iostream>
using namespace std;

int num1(1);
int num2(2);

int foo1(int val){
	val = val + 1;
	return val;
}

int foo2(int& val){
	val = val + 1;
	num1 = num2 + 1;
	return val - 1;
}

int foo3(int& val){
	int num2(2);
	num2 = num2 + 1;
	return foo1(3 * num1) + foo2(val);
}

unsigned int bidule(unsigned int x, unsigned int y)
{
	unsigned int z(0);

	while (y >= 1) {
		if ((y % 2) == 0) {
			x = x * 2;
			y = y / 2;
		} else {
			z = z + x;
			y = y -1;
		}
	}
	return z + 1;
}

int main()
{

	int num1(3);
	 cout << "resultat 1 : " << foo3(num1) <<  endl;
	 cout << "resultat 2 : " << num1 <<  endl;
	 cout << "resultat 3 : " << num2 <<  endl;

	return 0;
}
