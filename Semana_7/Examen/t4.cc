#include <iostream>
using namespace std;

int main() {
	int a(7);
	int b(3);
	int * q;
	int * p;

	p = &b;
	cout << "1. " << a << " " << *p << endl;

	q = p;
	
	*q = a;

	cout << "2. " << *q << endl;

	p = q;
	*p = a;

	cout << "3. " << *q << endl;

	p = &b;
	a = *q;
	p = p+1;
	cout << "4. " << *q << endl;
	// cout << a << " " << b << " " << *p << endl;
}
