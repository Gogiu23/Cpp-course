#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
													* all compilers seems to support it :-( */

char tirer_couleur()
{
	static const char* const couleurs = ".RGBCYM";
	static const int nb = strlen(couleurs) - 1;

	return couleurs[distribution(generateur,
			std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
	char lu(' ');
	cout << "Entrez une couleur : ";
	cin >> lu;
	return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
	char lu(poser_question());
	while (not couleur_valide(lu)) {
		cout << "'" << lu << "' n'est pas une couleur valide." << endl;
		cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
		lu = poser_question();
	}
	return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
	cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
	while (nb-- > 0) {
		cout << c;
	}
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
		char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
		char r1, char r2, char r3, char r4)
{
	afficher_couleurs(c1, c2, c3, c4);
	cout << " : ";
	afficher_reponses(c1, c2, c3, c4,
			r1, r2, r3, r4);
	cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
	cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
	cout << "Perdu :-(" << endl;
	cout << "La bonne combinaison était : ";
	afficher_couleurs(c1, c2, c3, c4);
	cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

// ======================================================================
bool couleur_valide(char c)
{
	if (c != '.' and c != 'Y' and c != 'R' and c != 'M' and c != 'B' \
			and c != 'G' and c != 'C')
		return false;
	return true;
}

// ======================================================================
bool verifier(char& c1, char& r1, int& score)
{
	if (c1 == r1)
	{
		++score;
		c1 = 'X';
		r1 = 'x';
		return true;
	}
	return false;
}

// ======================================================================
void apparier(char col_test, char& col_1, char& col_2, char& col_3, int& score)
{
	if (col_test == col_1){
		col_1 = 'x';
		++score;
	}
	else if (col_test == col_2){
		col_2 = 'x';
		++score;
	}
	else if (col_test == col_3){
		col_3 = 'x';
		++score;
	}
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
		char r1, char r2, char r3, char r4)
{
	int score(0);
	int sum(0);
	verifier(c1, r1, score); 
	verifier(c2, r2, score);
	verifier(c3, r3, score);
	verifier(c4, r4, score);
	afficher(score, '#');
//	cout << endl << c1 << c2 << c3  << c4 << endl;
//	cout << endl << r1 << r2 << r3  << r4 << endl;
	sum += score;
	score = 0;
	apparier(c1, r2, r3, r4, score);
	apparier(c2, r1, r3, r4, score);
	apparier(c3, r2, r1, r4, score);
	apparier(c4, r2, r3, r1, score);
	afficher(score, '+');
	sum += score;
	afficher(4-sum, '-');
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
		char r1, char r2, char r3, char r4)
{
	if (c1 == r1 and c2 == r2 and c3 == r3 and c4 == r4)
		return true;
	return false;
}

// ======================================================================
void jouer(int intentos = 8)
{
	char r1 = tirer_couleur();
	char r2 = tirer_couleur();
	char r3 = tirer_couleur();
	char r4 = tirer_couleur();
//	cout << "Entra los colores test R: ";
//	char r1(0); 
//	char r2(0);	
//	char r3(0);	
//	char r4(0);		
//	cin >> r1 >> r2 >> r3 >> r4;
	for (int ask_col(1); ask_col <= intentos; ++ask_col) {
		char c1 = lire_couleur();
		char c2 = lire_couleur();
		char c3 = lire_couleur();
		char c4 = lire_couleur();
		afficher_coup(c1, c2, c3, c4, r1, r2, r3, r4);
		if (gagne(c1, c2, c3, c4, r1, r2, r3, r4)){
			message_gagne(ask_col);
			return ;
		}
	}
	message_perdu(r1, r2, r3, r4);
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
	jouer();
	return 0;
}
