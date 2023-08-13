#include <iostream>
#include <ostream>
#include <vector>
using namespace std;


struct personne {
	double talla;
	int age;
	char sexe;
};

void affiche_personne(personne const& p);
void anniversaire(personne & p);
void naissance(personne & p);

int main() {
	personne p;
	naissance(p);
	affiche_personne(p);
	anniversaire(p);
	affiche_personne(p);
}

void anniversaire(personne & p) {
	++(p.age);
}

void naissance(personne& p) {
	cout << "Entra la altura: ";
	cin >> p.talla;
	cout << "Entra la edad: ";
	cin >> p.age;
	cout << "Entra el sexo [M] [F]: ";
	cin >> p.sexe;
}

void affiche_personne(personne const& p) {
	cout << "Talla: " << p.talla << endl;
	cout << "Age: " << p.age << endl;
	cout << "Sexe: " << p.sexe << endl;
}
