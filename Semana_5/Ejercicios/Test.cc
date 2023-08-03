#include <vector>
#include <iostream>
using namespace std;

int main(){
	vector<double> v(3, 3.14);

	for (double valeur(v[0]); valeur < v.size(); ++valeur) {
		cout << valeur << ", ";
	}
	cout << endl;
}
