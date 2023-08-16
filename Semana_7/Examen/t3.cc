#include <iostream>
using namespace std;

int main() {
	int a;
	int b;
	int * q;
	int * p;

	a = 1;
	b = 2;
	p = &a;
	q = &b;
	p = q;
	q = p;

	cout << a << " " << b << " " << *p << endl;
}
