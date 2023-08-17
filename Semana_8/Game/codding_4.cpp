#include <array>
#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;

enum Color { vacio, red, yellow };



typedef array<array<Color, 7>, 6> Tab;
// Prototypes
void init(Tab& tab);
void affiche(const Tab& tab);
bool play(Tab& tab, size_t columne, Color color);


bool play(Tab& tab, size_t columne, Color color) {
	if (tab[0][columne-1] != vacio) {
		return false;
	}
	if (columne > tab[0].size())
		return false;
	// cubrimos la columna donde el jugador ha decidido jugador
	size_t line(tab.size()-1);
	while (tab[line][columne-1] != vacio) {
		--line;	
	}
	tab[line][columne-1] = color;
	return true;
}

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

void ask_and_play(Tab& tab, Color color_player)
{
	bool valid;
	//preguntar al jugador por un color
	cout << "Player ";
	if (color_player == yellow) {
		cout << "1";
	} else {
		cout << "2";
	}
	cout << ": elige una columna para jugar" << endl;
	do {
		size_t column;
		cin >> column;
		// testear la validez del color y llenar tabla

		valid = play(tab, column, color_player);
		if (not valid) {
			cout << "Este movimiento no es valido!! " << endl;
		}
	} while (not valid);
}

unsigned int count(const Tab& tab, size_t line_start, size_t column_start, int dir_line, int dir_col) {
	unsigned counter(0);
	size_t line(line_start);
	size_t column(column_start);

	while (line < tab.size() and
			column < tab[line].size() and
			tab[line][column] == tab[line_start][column_start]) {
		++counter;
		line   = line 	+ dir_line;
		column = column + dir_col;
	}
	return counter;
}

bool who_won(Tab& tab, Color color_player) {
	for (size_t line(0); line < tab.size(); ++line) {
		for (size_t column(0); column < tab[line].size(); ++column) {
			Color color_sample(tab[line][column]);	

			const size_t column_max(tab[line].size()-4);
			const size_t line_max(tab.size()-4);
			if (color_sample == color_player) {
				if (//direccion diagonal
					(line >= 3 and column <= column_max and
					count(tab, line, column, -1, +1) >= 4) or 
					// horizontal a derecha
					(column <= column_max and
					count(tab, line, column, 0, +1) >= 4) or\
					//diagonal abajo a la derecha
					(line <= line_max and column <= column_max and
					count(tab, line, column, +1, +1) >= 4) or\
					//vertical abajo
					(line <= line_max and
					count(tab, line, column, +1, 0) >= 4)) {
					return true;
				}
			}
		}
	}
	return false;
}

bool full(const Tab& tab) {
	for (auto kase : tab[0]) {
		if (kase == vacio) {
			return false;
		}
	}
	return true;
}


int main() {
	Tab tab;
	init(tab);
	bool won;
	Color color_player(yellow);
	do {
		ask_and_play(tab, color_player);
		affiche(tab);

		won = who_won(tab, color_player);

		if (color_player == yellow) {
			color_player = red;
		}
		else {
			color_player = yellow;
		}
	} while (not won and not full(tab));

	//ganador es el color opuesto
	if (won)
	{
		if (color_player == yellow) {
			cout << "El ganador es el Player 2!!" << endl;
		} else {
			cout << "El ganador es el Player 1!!" << endl;
		}
	} else {
		cout << "Match acabado en empate!!" << endl;
	}
	return 0;
}
