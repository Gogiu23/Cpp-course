#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double h_init(0.00);
	double eps(0.00);
	double h_final(0.00);
	int rebote(0);
	double g(9.81);
	cout << "Ingresa los valores de H0 (altura inicial al que se tira la pelota):" << endl;
	do {
		cin >> h_init;
		if (h_init <= 0) {
			cout << "Por favor inserta valores positivos mayores a zero" << endl;
		}
	}
	while (h_init <= 0);
	cout << "Ingresa el eps (coeficiente de rebote, entre 0 y 1)" << endl;
	do {
		cin >> eps;
		if (eps < 0 or eps > 1) {
			cout << "Error, inserta un valor entre 0 y 1" << endl;
		}
	}
	while (eps < 0 or eps > 1);
	cout << "Ingresa el numero de rebotes:" << endl;
	do {
		cin >> h_final;	
		if (h_final < 0 or h_final >= h_init) {
			cout << "Solo valores positivos o por debajo de la altura final!!" << endl;
		}
	} while (h_final < 0 or h_final >= h_init);
	cout << endl;
	cout << "Has ingresado los valores: " << endl;
	cout << "altura inicial: " << h_init << " cm" << endl;
	cout << "Eps: " << eps << endl;
	cout << "Numero de altura final: " << h_final << " cm" << endl;
	do{
		double speed(0.00);
		speed = sqrt(2.00 * h_init * g);
		double speed_reb = (eps * speed) * (eps * speed);
		h_init = speed_reb / (2.00 * g);
//		cout << "h_init:" << h_init << endl;
		++rebote;
	} while (h_init >= h_final);
	cout << "rebotes requeridos: " << rebote << endl;
	return 0;
}
