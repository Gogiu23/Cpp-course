#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double h_init(0.00);
	double eps(0.00);
	int rebote(0);
	double g(9.81);
	cout << "Ingresa los valores de H0 (altura inicial al que se tira la pelota:" << endl;
	cin >> h_init;
	cout << "Ingresa el eps (coeficiente de rebote, entre 0 y 1)" << endl;
	cin >> eps;
	cout << "Ingresa el numero de rebotes:" << endl;
	cin >> rebote;	
	cout << endl;
	cout << "Has ingresado los valores: " << endl;
	cout << "altura inicial: " << h_init << endl;
	cout << "Eps: " << eps << endl;
	cout << "Numero de rebotes: " << rebote << endl;
	for (int fin_reb(0); fin_reb < rebote; ++fin_reb){
		double speed(0.00);
		speed = sqrt(2 * h_init * g);
		cout << "speed " << speed << endl;
		double speed_reb = (eps * speed) * (eps * speed);
		cout << "speed rebote: " << speed_reb << endl;
		h_init = speed_reb / (2 * g);
		cout << "altura final: " << h_init << endl;
	}
	return 0;
}
