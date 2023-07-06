#include <iostream>
using namespace std;

int main()
{
	cout << "Donnez l'heure de début de la location (un entier) : ";
	int debut;
	cin >> debut;

	cout << "Donnez l'heure de fin de la location (un entier) : ";
	int fin;
	cin >> fin;

	/*****************************************************
	 * Compléter le code à partir d'ici
	 *****************************************************/

	if ((debut > 24 or debut < 0) or (fin > 24 or fin < 0))
	{
		cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
		return 0;
	}
	else if (debut == fin)
	{
		cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
		return 0;
	}
	else if (fin < debut)
	{
		cout << "Bizarre, le début de la location est après la fin ..." << endl;
		return 0;
	}

	cout << "Vous avez loué votre vélo pendant" << endl;
	int low_tarif(1);
	int h_tarif(2);
	int hours_lt(0);
	int hours_ht(0);
	int resultat(0);

	if (fin <= 17 and fin >= 7)
	{
		if (debut >= 7)
		{
			hours_ht = fin - debut;
			resultat = hours_ht * h_tarif;
		}
		else
		{
			hours_lt = -(debut - 7);
			hours_ht = fin - 7;
			resultat = ((debut - 7) * -low_tarif) + (hours_ht * 2);
		}
	}
	else if (fin > 17)
	{
		hours_lt = fin - 17;
		if (debut >= 17)
		{
			hours_lt = fin - debut;
			resultat = hours_lt * 1;
		}
		else if (debut >= 7 and debut < 17)
		{
			hours_ht = 17 - debut;
		}
		else
		{
			hours_lt += 7 - debut;
			hours_ht = 10;
		}
		resultat = (hours_lt * 1) + (hours_ht * 2);
	}
	else if (fin < 7)
	{
		hours_lt = fin - debut;
		resultat = hours_lt * 1;
	}

	if (hours_lt > 0)
	{
		cout << hours_lt;
		cout << " heure(s) au tarif horaire de 1" 
			<< " franc(s)" << endl;
	}
	if (hours_ht > 0)
	{	cout << hours_ht;
		cout << " heure(s) au tarif horaire de 2"
			<< " franc(s)" << endl;
	}
	cout << "Le montant total à payer est de " << resultat
		<< " franc(s)." << endl;

	/*******************************************
	 * Ne rien modifier après cette ligne.
	 *******************************************/

	return 0;
}
