#include <iostream>
#include <vector>
using namespace std;

struct Complexe {
	vector<double> nom_com;
};

void affiche(vector<double> nom);
vector<double> addition(vector<double> N1, vector<double> N2);
vector<double> soustraction(vector<double> N1, vector<double> N2);
vector<double> multiplication(vector<double> N1, vector<double> N2);
vector<double> division(vector<double> N1, vector<double> N2);

int main() {

	Complexe N1;
	Complexe N2;
	N1.nom_com = {2, -3};
	N2.nom_com = {1, 1};
	affiche(addition(N1.nom_com, N2.nom_com));
	affiche(soustraction(N1.nom_com, N2.nom_com));
	affiche(multiplication(N1.nom_com, N2.nom_com));
	affiche(division(N1.nom_com, N2.nom_com));
	return 0;
}

void affiche(vector<double> nom) {
	cout << "(" << nom[0] << "," << nom[1] << ")" << endl;
}

vector<double> addition(vector<double> N1, vector<double> N2) {

	vector<double> result({N1[0] + N2[0], N1[1] + N2[1]});
	cout << "Addition" << endl;
	return result;
}

vector<double> soustraction(vector<double> N1, vector<double> N2)
{
	vector<double> result({N1[0] - N2[0], N1[1] - N2[1]});
	cout << "Sottrazzione" << endl;
	return result;
}

vector<double> multiplication(vector<double> N1, vector<double> N2)
{
	cout << "Multiplication: " << endl;;
	double first(0.00);
	double second(0.00);
	first = (N1[0] * N2[0])-(N1[1] * N2[1]);
	second = (N1[0] * N2[1]) + (N2[0] * N1[1]);
	vector<double> result({first, second});
	return result;
}

vector<double> division(vector<double> N1, vector<double> N2)
{
	cout << "Division: " << endl;
	double first(0.00);
	double second(0.00);
	first = ((N1[0] * N2[0]) + (N1[1] * N2[1]))/((N2[0] * N2[0])+(N2[1]*N2[1]));
	second = ((N1[1] * N2[0]) - (N1[0] * N2[1]))/((N2[0] * N2[0])+(N2[1]*N2[1]));
	vector<double> result({first, second});
	return result;
}

