#include <iostream>
using namespace std;

int demander_nombre(int min = 0, int max = 100);

int main()
{
	int n = demander_nombre();
	cout << n << endl;
	return 0;
}

int demander_nombre(int min, int max)
{
	int n(0);
	do{
	cout << "Inserte un numero: ";
	cin >> n;
	} while (n < min or n > max);
	return n;
}

