#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double h_init(0.00);
	double eps(0.00);
	int rebote(0);
	double g(9.81);
	cout << "Ingresa los valores de H0 (altura inicial al que se tira la pelota):" << endl;
	do {
		cin >> h_init;
		if (h_init <= 0) {
			cout << "Por favor inserta valores positivos mayores a zero" << endl;
		}
	}
	while (h_init < 0);
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
		cin >> rebote;	
		if (rebote < 0) {
			cout << "Solo valores positivos!!" << endl;
		}
	} while (rebote < 0);
	cout << endl;
	cout << "Has ingresado los valores: " << endl;
	cout << "altura inicial: " << h_init << " cm" << endl;
	cout << "Eps: " << eps << endl;
	cout << "Numero de rebotes: " << rebote << endl;
	for (int fin_reb(0); fin_reb < rebote; ++fin_reb){
		double speed(0.00);
		speed = sqrt(2 * h_init * g);
//		cout << "speed " << speed << endl;
		double speed_reb = (eps * speed) * (eps * speed);
//		cout << "speed rebote: " << speed_reb << endl;
		h_init = speed_reb / (2 * g);
	}
	cout << "altura final: " << h_init << " cm" << endl;
	return 0;
}
