#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "introducir los valores a0, a1 y a2: " << endl;
	double a0, a1, a2;
	cin >> a0 >> a1 >> a2;
	cout << "los valores son:" << endl;
	cout << "a0 = " << a0 << endl;
	cout << "a1 = " << a1 << endl;
	cout << "a2 = " << a2 << endl;

	cout << "Calculamos Q" << endl;
	double Q(0.0);
	double R(0.0);
	double D(0.0);
	double S(0.0);
	double T(0.0);
	double z1(0.0);
	double z2(0.0);
	Q = ((3 * a1) - (a2 * a2)) / 9;
	R = ((9 * a2 * a1) - (27 * a0) - (2 * (a2 * a2 * a2))) / 54;
	D = (Q * Q * Q) + (R * R);
	cout << "Valor de D: " << D << endl;

	if (D < 0)
	{
		cout << "________________________________________" << endl;
		cout << "Tenemos 3 soluciones:" << endl;
		z1 = 2.0 * sqrt(-Q) * cos(0.0 / 3.0) - a2/3.0;
		cout << "valor de z1 es: " << z1 << endl;
		z2 = 2.0 * sqrt(-Q) * cos((0.0 + 2.0 * M_PI)/3.0)-a2/3.0;
		cout << "valor de z2 es: " << z2 << endl;
		double z3(0.0);
		z3 = 2.0 * sqrt(-Q) * cos((0.0 + 4.0 * M_PI)/3.0) - a2/3.0;
		cout << "valor de z3 es: " << z3 << endl;
	}
	else
	{
		cout << "________________________________________" << endl;
		double s(R + sqrt(Q));
		if (s == 0.0)
			S = 0.0;
		else if (s < 0)
			S = -pow(-s , 1.0/3.0);
		else if (s > 0.0)
			S = pow(s, 1.0/3.0);
		s = (R + sqrt(D));
		if (s == 0.0)
			T = 0.0;
		else if (s < 0)
			T = -pow(-s, 1.0/3.0);
		else if (s > 0)
			T =-pow(s, 1.0/3.0);
		if (D == 0 and S + T != 0)
		{
			cout << "Solo tenemos dos soluciones:" << endl;
			z1 = S + T - (a2/3.0);
			z2 = - ((S + T)/2.0)-(a2/3.0);
			cout << "valor de z1 es: " << z1 << endl;
			cout << "valor de z2 es: " << z2 << endl;
		}
		else
		{
			cout << "Solo hay una solucion:" << endl;
			z1 = S + T - (a2/3.0);
			cout << "valor de z1 es: " << z1 << endl;
		}
	}
		return 0;
	}
