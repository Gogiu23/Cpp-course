#include <iostream>
using namespace std;

int main()
{
	const int base(4);
	double fromage(800.0);
	double eau(2.0);
	double ail(2.0);
	double pain(400.0);

	cout << "Para cuantas personas quieres preparar la fondue? ";
	int nb_convives(0);
	cin >> nb_convives;
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "Para " << nb_convives << " personas necesitamos:" << endl;
	cout << "--------------------------------------------------" <<  endl;
	cout << "- " << fromage * nb_convives / base << " gr de queso;" << endl;
	cout << "- " << eau * nb_convives / base << " dl de agua;" << endl;
	cout << "- " << ail * nb_convives / base << " piezas de ajo;" << endl;
	cout << "- " << pain * nb_convives / base << " gr de pan;" << endl;
	cout << "- Pimiento al gusto." << endl;
	cout << "--------------------------------------------------" <<  endl;
	return 0;
}
