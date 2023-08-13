#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<double> > lire_matrice();
vector<vector<double> > multiplication(const vector<vector<double> >& Mat1, \
		const vector<vector<double> >& Mat2);
void affiche_matrice(const vector<vector<double> >& M);

int main() {
	vector<vector<double> > M1(lire_matrice()), M2(lire_matrice());
	vector<vector<double> > tab_res;

	if (M1[0].size() == M2.size()) {
		tab_res = multiplication(M1, M2);
	}
	else
		cout << "Multiplicacion de matrices imposible" << endl;
	affiche_matrice(tab_res);
	return 0;
}

vector<vector<double> > lire_matrice()
{
	int m(0);
	int n(0);

	do {
		cout << "Tamaño de las linias: ";
		cin >> m;
	} while (m < 1);
	do {
		cout << "Tamaño de las columnas: ";
		cin >> n;
	} while (n < 1);

	vector<vector<double> > tab(m, vector<double> (n));

	for (int i(0); i < m; ++i) {
		for (int j(0); j < n; ++j) {
			cout << "Valor en tab[" << i << "][" << j << "] ";
			cin >> tab[i][j];
		}
	}
	return tab;
}

vector<vector<double> > multiplication(const vector<vector<double> >& Mat1, \
		const vector<vector<double> >& Mat2) {
	double resultat_temp(0.00);
	double resultat_fin(0.00);
	vector<vector<double> > M_ret(2, vector<double>(4));

	for (size_t i(0); i < Mat1.size(); ++i) {
		for (size_t j(0); j < Mat2[0].size(); ++j) {
			for (size_t k(0); k <= Mat1.size(); ++k) {
				resultat_temp = Mat1[i][k] * Mat2[k][j];
				resultat_fin += resultat_temp;
			}
			M_ret[i][j] = resultat_fin;
			resultat_fin = 0.00;
		}
	}
	return M_ret;
}

void affiche_matrice(const vector<vector<double> >& M)
{
	cout << "Resultat: " << endl;
	for (auto linia : M) {
		for (auto element : linia) {
			cout << element << " ";
		}		
		cout << endl;
	}
}
