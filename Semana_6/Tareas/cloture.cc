#include <cstdlib>
#include <iostream>
#include <iterator>
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



double count_mid_map(const Carte& carte)
{
	double result(0.00);
	for (size_t i(1); i < carte.size()-1; ++i) {
		for (size_t j(1); j < carte[0].size()-1; ++j) {
			if (carte[i][j] == 1) {
				if (carte[i-1][j] == 0) {
					++result;
				}
				if (carte[i][j+1] == 0) {
					++result;
				}
				if (carte[i+1][j] == 0) {
					++result;
				}
				if (carte[i][j-1] == 0) {
					++result;
				}
			}	
		}
	
	}
	return result;
}

double count_last_line(const Carte& carte)
{
	double result(0.00);
	double count(0.00);
	size_t line_max(carte.size()-1);
	for (size_t j(0); j < carte[0].size(); ++j) {
		if (carte[line_max][j] == 1) 
		{
			++count;
			if (carte[line_max-1][j] == 0) 
				++result;
		
		}	
	}
	result = result + count + 2;
	return result;
}

double count_first_line(const Carte& carte)
{
	double result(0.00);
	double count(0.00);
	for (size_t j(0); j < carte[0].size(); ++j) {
		if (carte[0][j] == 1) 
		{
			++count;
					if (carte[1][j] == 0) 
				++result;
		}
	}
	result = result + count + 2;
	return result;
}

double count_last_column(const Carte& carte)
{
	double result(0.00);
	double count(0.00);
	size_t col_max(carte[0].size()-1);
	for (size_t i(1); i < carte.size()-1; ++i) {
		if (carte[i][col_max] == 1) {
			++count;
			if (carte[i][col_max-1] == 0) 
				++result;
			if (carte[i-1][col_max] == 0)
				++result;
			if (carte[i+1][col_max] == 0) 
				++result;
		}	
	}
	result = result + count;
	return result;
}

double count_first_column(const Carte& carte)
{
	double result(0.00);
	double count(0.00);
	for (size_t i(1); i < carte.size()-1; ++i) {
		if (carte[i][0] == 1) 
		{
			++count;
			if (carte[i][1] == 0) 
				++result;
			if (carte[i-1][0] == 0)
				++result;	
			if (carte[i+1][0] == 0) 
				++result;
		}
	}
	result = result + count;
	return result;
}

double count_square(const Carte& carte)
{
	double result(0.00);
	result += count_first_line(carte);
	result += count_last_line(carte);
	result += count_first_column(carte);
	result += count_last_column(carte);
	result += count_mid_map(carte);
	return result;
}

double one_line_map(const Carte& carte, Position cor)
{
	double result(0.00);
	while (cor.j < carte[cor.i].size()) {
		if (carte[cor.i][cor.j] == 1) {
			++result;	
		}
		++cor.j;
	}
	return ((result * 2) + 2);
}


double longueur_cloture(Carte const& carte, double echelle)
{
	Position cor;
	cor.i = 0;
	cor.j = 0;
	double result(0.00);
	if (carte.size() == 1)
		result += one_line_map(carte, cor);
	else
		result += count_square(carte);
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
