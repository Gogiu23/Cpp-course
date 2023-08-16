#include <iostream>
using namespace std;

int main() {
	double valor1(0.00);
	double valor2(23.00);
	double valor3(7.00);
	double * choix;

	int num(0);
	do {
	cout << "Elije un numero entre 1 y 3 ";
	cin >> num;
	} while (num < 1 || num > 3);
	if (num == 1)
	{
		choix = &valor1;
	}
	else if (num == 2 ) {
		choix = &valor2;
	}
	else {
		choix = &valor3;
	}
	cout << "Has elegido el valor " << num << " que equivale a: " << *choix << endl;
	return 0;
}
