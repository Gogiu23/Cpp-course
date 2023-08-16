#include <iostream>
using namespace std;

int main() {
	int a;
	int b;
	int * p;

	a = 1;
	b = 2;
	b = a;
	p = 0;

	cout << a << " " << b << " " << *p << endl;
}
