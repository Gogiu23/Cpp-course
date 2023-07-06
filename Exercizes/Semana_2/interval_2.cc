#include <iostream>
using namespace std;

int main()
{
	cout << "Entra un numero con decimales (usa '.'en lugar de ','): " << endl;
	double x;
	cin >> x;
	if (x > 0)
	{
		if (x < 3 and x >= 1)
		{
			cout << "x esta dentro del intervalo" << endl;
		}
		else
			cout << "x esta fuera del intervalo" << endl;
	}
	else
	{
		if (x >= -10 and x <= -2)
		{
			cout << "x esta dentro del intervalo" << endl;
		}
		else
			cout << "x esta fuera del intervalo" << endl;
	}
	return 0;
}
