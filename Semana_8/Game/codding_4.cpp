#include <array>
#include <cstddef>
#include <iostream>
using namespace std;

enum Color { vacio, red, yellow };



typedef array<array<Color, 7>, 6> Tab;

void init(Tab& tab);
void affiche(const Tab& tab);

//imprime 0 por rojo y X por amarillo
void affiche(const Tab& tab) {
	cout << endl;
	for (auto line : tab) {
		cout << "|";
		for (auto kase : line) {
			if (kase == vacio) {
				cout << " ⬛️ ";
			} else if (kase == red) {
				cout << " 🟥 ";
			}
			else {
				cout << " 🟨 ";
			}
			cout << "|";
		}
		cout << endl;
	}
	cout << endl;
	cout << "=  ";
	for (size_t i(1); i <= tab[0].size(); ++i) {
		cout << i << " =  ";
	}
	cout << endl << endl;
}

void init(Tab& tab)
{
	for (auto& line : tab) {
		for (auto& kase : line) {
			kase = vacio;
		}	
	}
}

int main() {
	Tab tab;
	init(tab);
	tab[2][3] = yellow;
	tab[2][4] = red;
	affiche(tab);
	return 0;
}
