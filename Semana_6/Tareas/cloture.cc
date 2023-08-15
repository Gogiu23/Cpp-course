#include <iostream>
#include <vector>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/
typedef vector<vector<int> > Carte;
struct Position {
	size_t i; 
	size_t j;
};


bool binaire(Carte const& carte); 
void affiche(Carte const& carte);
bool verifie_et_modifie(Carte& carte);
bool is_a_pond(Carte const& carte, Position cor);
double count_mid_map(Carte carte, Position& cor);
double count_first_line(Carte carte, Position& cor);
double count_last_line(Carte carte, Position& cor);
void ajoute_unique(vector<int>& ensemble, int valeur);
bool convexite_lignes(Carte& carte, vector<int> const& labels_bords);
bool convexite_lignes(Carte& carte);
double longueur_cloture(Carte const& carte, double echelle = 2.5);

void ajoute_unique(vector<int>& ensemble, int valeur)
{
}

bool convexite_lignes(Carte& carte, vector<int> const& labels_bords)
{
	return true;
}

bool convexite_lignes(Carte& carte)
{
	return true;
}

double count_first_line(Carte carte, Position& cor)
{
	double result(0.00);
	while (cor.j < carte[cor.i].size())
	{
		if (carte[cor.i][cor.j] == 1)
		{
			++result;
			if (carte[cor.i][cor.j-1] == 0 || cor.j == 0) {
				++result;
			}
			if (carte[cor.i][cor.j+1] == 0 && cor.j << carte[cor.i].size()) {
				++result;
			}
			if (carte[cor.i+1][cor.j] == 0) {
				++result;
			}
		}
		++(cor.j);
	}
	return result;
}

double count_last_line(Carte carte, Position& cor)
{
	double result(0.00);
	while (cor.j < carte[cor.i].size())
	{
		if (carte[cor.i][cor.j] == 1)
		{
			++result;
			if (carte[cor.i-1][cor.j] == 0) {
				++result;
			}
			if (carte[cor.i][cor.j-1] == 0 || cor.j == 0) {
				++result;
			}
			if (carte[cor.i][cor.j+1] == 0 && cor.j < carte[cor.i].size()) {
				++result;
			}
		}
		++(cor.j);
	}
	return result;
}

double count_mid_map(Carte carte, Position& cor)
{
	double result(0.00);
	while (cor.j < carte[cor.i].size()) {
		if (carte[cor.i][cor.j] == 1)
		{
			if (carte[cor.i-1][cor.j] == 0)
				++result;
			if (carte[cor.i][cor.j+1] == 0 && cor.j < carte[cor.i].size()) {
				++result;
			}
			if (carte[cor.i+1][cor.j] == 0) {
				++result;
			}
			if (carte[cor.i][cor.j-1] == 0 || cor.j == 0) {
				++result;
			}
		}
		++(cor.j);
	}
	return result;
}

double longueur_cloture(Carte const& carte, double echelle)
{
	Position cor;
	cor.i = 0;
	cor.j = 0;
	double result(0.00);
	while (cor.i < carte.size())
	{
		cor.j = 0;
		if (carte.size() == 1)
		{
			while (cor.j < carte[cor.i].size()) {
				if (carte[cor.i][cor.j] == 1) {
					++result;	
				}
				++cor.j;
			}
			return (echelle * ((result * 2) + 2));
		}
		if (cor.i == 0)
			result += count_first_line(carte, cor);
		else if (cor.i != carte.size()-1)
			result += count_mid_map(carte, cor);
		if (cor.i == carte.size()-1)
			result += count_last_line(carte, cor);
		++(cor.i);
	}
	return (echelle * result);
}

bool binaire(Carte const& carte)
{
	Position cor;

	cor.i = 0;
	while (cor.i < carte.size())
	{
		cor.j = 0;
		while (cor.j < carte[cor.i].size())
		{
			if (carte[cor.i][cor.j] != 0 && carte[cor.i][cor.j] != 1)
				return false;
			else
				++(cor.j);
		}
		++(cor.i);
	}
	return true;
}

bool is_a_pond(Carte const& carte, Position cor)
{
	while (cor.j < carte[cor.i].size()) {
		if (carte[cor.i][cor.j] == 1) {
			return true;
		}
		else {
			++(cor.j);
		}
	}
	return false;
}

void affiche(Carte const& carte)
{
	for (auto linia : carte) {
		for (auto element : linia) {
			cout << element;
		}
		cout << endl;
	}
	cout << "----" << endl;
}

bool verifie_et_modifie(Carte& carte)
{
	Position cor;
	cor.i = 0;
	cor.j = 0;
	if (not binaire(carte)) {
		cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
		return false;
	}
	else {
		while (cor.i < carte.size()) {
			cor.j = 0;
			while (cor.j < carte[cor.i].size())
			{
				if (carte[cor.i][cor.j] == 0 && carte[cor.i][cor.j-1] == 1)
				{
					int col = cor.j;
					if (is_a_pond(carte, cor))
					{
						while (carte[cor.i][col] == 0) {
							carte[cor.i][col] = 1;
							++col;
						}
					}
					++(cor.j);
				}
				else {
					++(cor.j);
				}
			}
			++(cor.i);
		}
	}
	return true;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
	Carte carte = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0},
		{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	cout << "Carte au départ :" << endl;
	affiche(carte);
	if (verifie_et_modifie(carte)) {
		cout << "Carte après modification :" << endl;
		affiche(carte);
		cout << "Il vous faut " << longueur_cloture(carte)
			<< " mètres de clôture pour votre terrain."
			<< endl;
	}

	return 0;
}
