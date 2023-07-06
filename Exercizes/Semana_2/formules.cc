#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "Entra un numero real: " << endl;
	double x;
	cin >> x;

	cout << "Expression 1:" << endl;
	if ((1.00 - exp(x)) != 0)
	{
		double resultado(0.00);
		resultado = x / (1.00 - exp(x));
		cout << "El resultado es " << resultado << endl;
	}
	else
		cout << "indefinido matematicamente" << endl;
	cout << endl << "_______________________________" << endl;
	cout << "Expression 2:" << endl;
	double resultado2(0.00);
	if (x > 0 and x != 1)
	{
		resultado2 = x * log(x) * exp(2.0/(x-1.0));
		cout << "El resultado de la expression 2 es: " << resultado2 << endl;
	}
	else
		cout << "indefinido matematicamente" << endl;
	cout << endl << "_______________________________" << endl;
	cout << "Expression 3:" << endl;

	if ((2.0 - x) != 0 and ((sqrt(x * x - 8.0 * x) >= 0)))
	{
		resultado2 = (-x - sqrt(x * x - 8.0 * x)) / (2.0 - x);
		cout << "El resultado de la expression 3 es: " << resultado2 << endl;
	}
	else
		cout << "indefinido matematicamente" << endl;
	cout << endl << "_______________________________" << endl;

	resultado2 = log(x * x - 1.0 / x);
	double resultado3(0.0);
	resultado3 = sin(x) - (x/20.0);
	resultado2 = sqrt(resultado3 * resultado2);
	if (x != 0 and (resultado3 * resultado2 > 0))
	{
		cout << "El resultado de la expression 4 es: " << resultado2 << endl;
	}
	else
		cout << "indefinido matematicamente" << endl;
	cout << endl << "_______________________________" << endl;
	return 0;
}
