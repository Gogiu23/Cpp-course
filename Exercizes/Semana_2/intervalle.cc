#include <iostream>
using namespace std;

int main()
{
	cout << "Ingresa un valor con decimales: ";
	double x;
	cin >> x;
	if (x >= -1 and x < 1)
		cout << "x pertenece al intervalo I" << endl;
	else
		cout << "x no pertenece al intervalo I" << endl;
	return 0;
}

