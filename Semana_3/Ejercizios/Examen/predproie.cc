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

	double renards_i(0.0);
	double lapins_i(0.0);

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
	double renards_p2 = renards_i;
	double lapins_p2 = lapins_i;

	for (int init(1); init <= 50; ++init){
		new_rabbits = 1.0 + taux_croissance_lapins;
		kill_fox = taux_attaque * renards_p2;
		rabbit_f = (new_rabbits - kill_fox);
		fox_f = taux_attaque * lapins_p2 * taux_croissance_renards;

		lapins_p2 = lapins_p2 * rabbit_f;
		renards_p2 = renards_p2 * (1.0 + fox_f - taux_mortalite);
		if (lapins_p2 < 0 or renards_p2 < 0)
		{
			lapins_p2 = 0.00;
			renards_p2 = 0.00;
		}
		cout << "Aprés " << init << " mois, il y a " << lapins_p2 << " lapins et " \
			<< renards_p2 << " renards" << endl;
	}

	// ===== PARTIE 3 =====
	// Variation du taux d'attaque
	cout << endl;
	//	cout << "Zorros y conejos " << renards_i << " " << lapins_i << endl;

	do {
		cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
		cin >> taux_attaque;
	} while (taux_attaque < 0.50 or taux_attaque > 6.00);

	double taux_attaque_final(0.00);

	do {
		cout << "taux d'attaque à la fin  en % (entre " << taux_attaque;
		cout << " et 6) ? ";
		cin >> taux_attaque_final;
	} while (taux_attaque_final > 6);

	taux_attaque /= 100;
	taux_attaque_final /= 100;

	while (taux_attaque <= taux_attaque_final)
	{
		bool perill_zorros(false);
		bool save_zorros(false);
		bool perill_conejos(false);
		bool save_conejos(false);
		bool extinction_zorros(false);
		bool extinction_conejos(false);
		bool extincion_masiva(false);
		renards_p2 = renards_i;
		lapins_p2 = lapins_i;
		for (int init(1); init <= 50; ++init){
			new_rabbits = 1.0 + taux_croissance_lapins;
			kill_fox = taux_attaque * renards_p2;
			rabbit_f = (new_rabbits - kill_fox);
			fox_f = taux_attaque * lapins_p2 * taux_croissance_renards;

			lapins_p2 = lapins_p2 * rabbit_f;
			renards_p2 = renards_p2 * (1.0 + fox_f - taux_mortalite);
			if (lapins_p2 < 0 or renards_p2 < 0)
			{
				lapins_p2 = 0.00;
				renards_p2 = 0.00;
			}
			if (renards_p2 < 5.00 or lapins_p2 < 5.00)
			{
				if (renards_p2 < 5.00)
					perill_zorros = true;
				if (lapins_p2 < 5.00)
					perill_conejos = true;
			}
			if (renards_p2 > 5.00 or lapins_p2 > 5.00)
			{
				if (renards_p2 >= 5.00 and perill_zorros)
					save_zorros = true;
				if (lapins_p2 >= 5.00 and perill_conejos)
					save_conejos = true;
			}
			if (renards_p2 < 2 or lapins_p2 < 2)
			{
				if (renards_p2 < 2)
				{
					extinction_zorros = true;
					renards_p2 = 0.00;
				}
				if (lapins_p2 < 2)
				{
					extinction_conejos = true;
					lapins_p2 = 0.00;
				}
			}
			if (lapins_p2 == 0.00 and renards_p2 == 0.00)
			{
				cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;
				cout << "Aprés " << init << " mois, il y a " << lapins_p2 << " lapins et " \
					<< renards_p2 << " renards" << endl;
				extincion_masiva = true;
				break ;
			}
		}
		if (!extincion_masiva)
		{
			cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;
			cout << "Aprés " << duree << " mois, il y a " << lapins_p2 << " lapins et " \
				<< renards_p2 << " renards" << endl;
		}
		if (perill_zorros)
			cout << "Les renards ont été en voie d'extinction" << endl;
		if (save_zorros)
			cout << "mais la population est remontée ! Ouf !" << endl;
		if (extinction_zorros)
			cout << "et les renards ont disparu :-(" << endl;
		if (perill_conejos)
			cout << "Les lapins ont été en voie d'extinction" << endl;
		if (save_conejos)
			cout << "mais la population est remontée ! Ouf !" << endl;
		if (extinction_conejos)
			cout << "et les lapins ont disparu :-(" << endl;
		if (!perill_conejos and !perill_zorros and !extinction_conejos and !extinction_zorros)
			cout << "Les lapins et les renards ont des populations stables." << endl;
		taux_attaque += 0.01;
	}

	/*******************************************
	 * Ne rien modifier après cette ligne.
	 *******************************************/

	return 0;
}
