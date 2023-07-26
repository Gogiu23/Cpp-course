#include <iostream>
using namespace std;

double moyenne(double a, double b);

int main()
{
	double a(0.00);
	double b(0.00);
	cout << "Inserte dos valores: " << endl;
	cin >> a >> b;
	cout << "la media es " << moyenne(a, b)  << endl;
	return 0;
}

double moyenne(double a, double b)
{
	return (a + b)/2;
}
