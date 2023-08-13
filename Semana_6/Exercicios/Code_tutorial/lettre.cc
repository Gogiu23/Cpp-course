#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct personne {
	string sexe;
	string destinatario;
	string asunto;
	int dia;
	int mes;
	string despedida;
	string autor;
};

void genereLettre(personne p);

int main() {
	personne M = {"chére", "Mireille", "votre cours", 18, 12, "Amicalment", "John"};
	genereLettre(M);
	cout << endl;
	personne F = {"cher", "John", "votre demande de rendez vous", 16, 12, "Sincerement", "Mireille"};
	genereLettre(F);
	return 0;
}

void genereLettre(personne p) {
	cout << "Bonjour " << p.sexe << " " << p.destinatario << "," << endl;
	cout << "Je vous écris à propos " << p.asunto << endl;
	cout << "Il faudrait que nous nous voyons le "  << p.dia << "/" << p.mes\
		<< " pour en discuter." << endl;
	cout << "Donnez-moi vite de vos nouvelles !" << endl;
	cout << p.despedida << ", " << p.autor << endl;
}
