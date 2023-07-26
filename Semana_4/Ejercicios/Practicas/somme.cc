#include <iostream>
using namespace std;

int somme(int a);//prototipo

int main()
{
	int a(0);
	char answer('n');
	do{
		do{
			cout << "Inserte un numero: ";
			cin >> a;
			cout << endl;
			cout << "la suma es de " << somme(a) << endl;
		}	while (a < 0 and a > 9);
		do{
			cout << "Quieres volver a empezar (y/n): ";
			cin >> answer;
		}while (answer != 'y' and answer != 'n');
	} while (answer == 'y');
	return 0;
}

int somme(int a)
{
	if (a <= 0)
		return 0;
	return (a + somme(a-1));
}
