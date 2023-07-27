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
	ajouter_chiffre_droit(nombre, repetitions_chiffre);
	ajouter_chiffre_droit(nombre, chiffre);
}

int lire_et_dire(int nombre)
{
	int num_fin(0);

	while (nombre)
	{
		int repetitions = 1;
		int digit = separer_chiffre_gauche(nombre);
		int temp = nombre;
		while (digit == separer_chiffre_gauche(temp))
		{
			++repetitions;
			separer_chiffre_gauche(nombre);
		}
		dire_chiffre(num_fin, repetitions, digit);
	}
	return num_fin;
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
