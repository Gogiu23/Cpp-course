#include <iostream>
using namespace std;

int main()
{
	int age(0);

	cout << "Indique su edad: ";
	cin >> age;

	int year = 2023 - age;

	cout << "El año de nacimiento vuestro es:" << year << endl;
	return 0;
}
