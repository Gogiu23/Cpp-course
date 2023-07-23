#include <iostream>
using namespace std;

int main()
{
	double s0(0.00);
	double r(0.00);
	double ir(0.00);
	double i(0.00);
	int month(1);

	do{
		cout << "Ingresa los valores de: " << endl;
		cout << "Importe inicial: ";
		cin >> s0;
		cout << endl;
	} while (s0 < 0);
	do {
		cout << "Cantidad devuelta cada mes (r): ";
		cin >> r;
		cout << endl;
	} while (r < 0);
	do {
		cout << "Tipo de interes mensual: ";
		cin >> ir;
		cout << endl;
	} while (ir < 0 or ir > 1);
	
	for (double s(s0); s >= 0; s -= r)
	{
		i += ir * s;
		++month;
	}
	cout << "El taso de interes acumulado del banco despues de " << month \
		<< " meses es de " << i << " euros" << endl; 
}
		
