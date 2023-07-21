#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n(0);
	int D(0);
	cout << "Ingresa un numero estrictamente entero y positivo" << endl;
	cin >> n;
	if (n % 2 == 0 and n != 2)
		cout << n << " no es primo porque es divisible por 2" << endl;
	else if (n <= sqrt(n))
	{
		if (n % n == 0)
		{
			D = n - 1;
			while (n % D == 0)
				--D;
			cout << "no es primo porque es divisible por " << D << endl;
		}
		else
			cout << "es primo" << endl;
	}
	return 0;
}
