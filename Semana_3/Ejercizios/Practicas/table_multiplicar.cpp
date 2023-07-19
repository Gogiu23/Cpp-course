#include <iostream>
using namespace std;

int main()
{
	cout << "Tabla de multiplicacion: " << endl;
	for(int j(2); j <= 10; ++j){
		cout << "Tabla de " << j <<  ":" << endl;
		for(int i(1); i <= 10; ++i){
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}
		return 0;
	}
