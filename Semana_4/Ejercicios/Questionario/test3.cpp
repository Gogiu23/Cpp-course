#include <iostream>
using namespace std;

int a(1);

int f(int& p, int q)
{
	a = p + q;
	p = a * q;

	return p + q + a;
}

void g()
{
	int a(3);
	 cout << f(a, a) << endl;
	 cout << a << endl;
}

int main()
{
	g();
	cout << a << endl;
	return 0;
}
