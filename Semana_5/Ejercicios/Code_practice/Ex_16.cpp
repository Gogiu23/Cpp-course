#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

double scalaire(vector<double> u, vector<double> v);

int main() {
	int n(0);
	int m(0);
	do {
		cout << "Talla del primer vector (m): ";
		cin >> m;
		cout << "Talla del segundo vector (n): ";
		cin >> n;
	} while (m < 0 || n < 0);
	vector<double> a(m);
	vector<double> b(n);

	for (auto& first : a) {
		cout << "Entra los valores de a: ";
		cin >> first;
	}
	for (auto& second : b) {
		cout << "Entra los valores de b: ";
		cin >> second;
	}
	cout << "El producto de dos vectores es: " << scalaire(a, b) << endl;	
}


double scalaire(vector<double> u, vector<double> v)
{
	double resultat(0.00);
	double temp(0.00);
	for (size_t i(0); i < u.size(); ++i) {
		temp = u[i] * v[i];
		resultat += temp;
	}
	return resultat;
}
