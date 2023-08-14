#include <cstddef>
#include <iostream>
#include <ratio>
#include <string>
#include <vector>
using namespace std;

struct QCM {
	string question;
	vector<string> response;
	int solution;
	int i;
};

typedef vector<QCM> Examen;

// Prototipos funciones
void affiche(Examen examen, QCM& qcm);
int poser_question(Examen examen, QCM& qcm);
int demander_nombre(int min = 0, int max = 100);
Examen creer_examen();
void final(Examen examen, QCM qcm);

int main() {
	QCM qcm;
	qcm.i = 0;
	qcm.solution = 0;
	Examen examen;
	examen = creer_examen();
	for (size_t i(0); i < examen.size(); ++i) {
		if (poser_question(examen, qcm) == examen[qcm.i].solution)
		{
			++(qcm.solution);
			++(qcm.i);
		}
		else
			++(qcm.i);
	}
	final(examen, qcm);
	return 0;
}

void affiche(Examen examen, QCM& qcm)
{
	int j(0);
	cout << examen[qcm.i].question << endl;
	for (auto element : examen[qcm.i].response) {
		cout << ++j << ") " << element << endl;	
	}
}

int demander_nombre(int min, int max)
{
	int n(0);
	do{
	cout << "Inserte un numero: ";
	cin >> n;
	} while (n < min or n > max);
	return n;
}

int poser_question(Examen examen, QCM & qcm)
{
	affiche(examen, qcm);
	return demander_nombre();
}

Examen creer_examen()
{
	Examen examen;
	QCM qcm1;
	qcm1.question = "Cuantos dientes tiene un elefante Adulto?";
	qcm1.response = {
		"32", 
		"de 6 a 10", 
		"muchas", 
		"24", 
		"2" };
	qcm1.solution = 2;
	examen.push_back(qcm1);

	QCM qcm2;
	qcm2.question = "Cual de las siguientes instrucciones es un prototipo de funcion?";
	qcm2.response = {
		"int f(0);",
		"int f(int 0);",
		"int f(int i);",
		"int f(i)"};
	qcm2.solution = 3;
	examen.push_back(qcm2);
	
	QCM qcm3;
	qcm3.question = "Cual de estos no es considerado como un ser vivo?";
	qcm3.response = { 
		"Virus", 
		"Archeobacteria", 
		"Paramethium", 
		"Acaro", 
		"Islote de Langerhan", 
		"Saccarhomices cerevisae"};
	qcm3.solution = 1;
	examen.push_back(qcm3);

	QCM qcm4;
	qcm4.question = "Harry Potter es un famoso...";
	qcm4.response =	{
		"Libro", 
		"Mago", 
		"Autor", 
		"Escritor", 
		"Actor"};
	qcm4.solution = 1;
	examen.push_back(qcm4);

	// QCM qcm3;
	// qcm3.question = "";
	// qcm3.response =	{""};
	// qcm3.solution = ;
	return examen;
}


void final(Examen examen, QCM qcm)
{
	cout << "Has encontrado " << qcm.solution << " sobre " << examen.size() << endl;
}
