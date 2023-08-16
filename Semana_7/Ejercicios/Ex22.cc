#include <iostream>
using namespace std;

struct Casa {
	string direccion;
};

struct Persona {
	string name;
	Casa* home;
};

void affiche(struct Persona p)
{
	cout << p.name << " vive en " << (p.home)->direccion << endl;
}

int main() {
	Casa m1 = { "Barcelona" };
	Persona p1 = {"Giuliano", &m1};
	Persona p2 = {"Alessia", &m1};

	Casa m2 = {"Italia"};
	Persona p3 = {"Loredana", &m2};
	Persona p4 = {"Ginebra", &m2};
	affiche(p1); affiche(p2); affiche(p3); affiche(p4);

	p1.home = &m2;
	cout << "Mientras tanto: ";
	affiche(p1); affiche(p2); affiche(p3); affiche(p4);
	return 0;
}
