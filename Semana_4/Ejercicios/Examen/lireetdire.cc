#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
	int dix(1);
	int temp(nombre);
	while (temp >= 10) {
		dix  *= 10;
		temp /= 10;
	}
	nombre %= dix;
	return temp;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
	nombre *= 10;
	nombre += chiffre;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
	while (repetitions_chiffre) {
		ajouter_chiffre_droit(nombre, chiffre);
		--repetitions_chiffre;
	}
}

int lire_et_dire(int nombre)
{
	int digit(0);
	int repetitions(1);

	while (nombre)
	{
		digit = separer_chiffre_gauche(nombre);
		int digit2 = separer_chiffre_gauche(nombre);
		if (digit == digit2)
			++repetitions;
		dire_chiffre(digit, repetitions, digit);
	}
	return digit;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
	while (fois-- > 0) {
		nombre = lire_et_dire(nombre);
	}
}

int main()
{
	int nombre(1);
	int fois(1);
	cin >> nombre >> fois;
	repeter_lire_et_dire(nombre, fois);
	cout << nombre << endl;
	return 0;
}
