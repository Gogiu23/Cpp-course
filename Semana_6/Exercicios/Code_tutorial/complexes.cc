#include <iostream>
#include <vector>
using namespace std;

struct Complexe {
	vector<double> nom_com;
};

void affiche(vector<double> nom);
vector<double> addition(vector<double> N1, vector<double> N2);

int main() {

	vector<double> num_1({1, 0});
	vector<double> num_2({0, 1});
	addition(num_1, num_2);
	//	affiche(num_1);
	return 0;
}

void affiche(vector<double> nom) {
	cout << "(" << nom[0] << "," << nom[1] << ")" << endl;
}

vector<double> addition(vector<double> N1, vector<double> N2) {

	vector<double> result({N1[0] + N2[0], N1[1] + N2[1]});  
	affiche(result);
	return result;
}
