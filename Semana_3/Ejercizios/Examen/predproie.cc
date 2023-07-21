#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
	// Réduire le format d'affichage
	cout << setprecision(4);

	// Paramètres
	double taux_croissance_lapins(0.3);
	double taux_attaque(0.01);
	double taux_croissance_renards(0.008);
	double taux_mortalite(0.1);
	int duree(50);

	double renards_i(0.0);//zorros
	double lapins_i(0.0);//conejos

	/*****************************************************
	 * Compléter le code à partir d'ici
	 *****************************************************/

	// ===== PARTIE 1 =====
	// Saisie des populations initiales

	do {
		cout << "Combien de renards au départ (>= 2) ? ";
		cin >> renards_i;
	} while (renards_i < 2.00);

	do {
		cout << "Combien de lapins au départ  (>= 5) ? ";
		cin >> lapins_i;
	} while (lapins_i < 5.00);

	// ===== PARTIE 2 =====
	// Première simulation
	cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;
	double kill_fox(0.00);
	double rabbit_f(0.00);
	double new_rabbits(0.00);
	double fox_f(0.00);

	for (int init(1); init <= 50; ++init){
		new_rabbits = 1.0 + taux_croissance_lapins;
		kill_fox = taux_attaque * renards_i;
		rabbit_f = (new_rabbits - kill_fox);
		fox_f = taux_attaque * lapins_i * taux_croissance_renards;
		
		lapins_i = lapins_i * rabbit_f;
		renards_i = renards_i * (1.0 + fox_f - taux_mortalite);
		if (lapins_i < 0 or renards_i < 0)
		{
			lapins_i = 0.00;
			renards_i = 0.00;
		}
		cout << "Aprés " << init << " mois, il y a " << lapins_i << " lapins et " << renards_i << " renards" << endl;
	}

	// ===== PARTIE 3 =====
	// Variation du taux d'attaque
	cout << endl;

	cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";

	cout << "taux d'attaque à la fin  en % (entre ";
	cout << " et 6) ? ";

	cout << "Les renards ont été en voie d'extinction" << endl;
	cout << "mais la population est remontée ! Ouf !" << endl;
	cout << "et les renards ont disparu :-(" << endl;
	cout << "Les lapins ont été en voie d'extinction" << endl;
	cout << "mais la population est remontée ! Ouf !" << endl;
	cout << "et les lapins ont disparu :-(" << endl;
	cout << "Les lapins et les renards ont des populations stables." << endl;

	/*******************************************
	 * Ne rien modifier après cette ligne.
	 *******************************************/

	return 0;
}
