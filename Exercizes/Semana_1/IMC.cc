#include <iostream>
using namespace std;

int main()
{
	double peso(83);
	double altura(1.76);

	cout << "Valor de peso (en Kg): ";
	cin >> peso;
	cout << "Altura (en m): ";
	cin >> altura;

	double imc(peso / (altura * altura));

	cout << "Para el peso " << peso
		<< " kg y " << altura << " el IMC es de "
		<< imc << endl;
	return 0;
}
