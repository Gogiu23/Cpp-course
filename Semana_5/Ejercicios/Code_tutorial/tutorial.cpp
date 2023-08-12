#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<double> notes;
	cout << "talla del vector notes " << notes.size() << endl;
	cout << "talla del vector notes " << notes.size()+1 << endl;

	double moyenne(0.0);
	double note(0.0);
	do {
		cout << "Entrez le note de l'eleve " << notes.size()+1 <<
			" (<0 pour finir) ";
		cin >> note;
		if (note >= 0.00) 
		{
			notes.push_back(note);
			moyenne += note; 
		}
	} while (note > 0.0);

	cout << "moyenne de la classe : " << moyenne / notes.size() << endl;
	cout << "Detail des notes: " << endl;
	cout << "Eléve : note (ecart á la moyenne)" << endl;
	
	for (size_t i(0); i < notes.size(); ++i) {
		cout << " " << i+1 << " : " << notes[i] << \
			" (" << notes[i] - (moyenne / notes.size()) << ")" <<  endl;	
	}
	return 0;
}
