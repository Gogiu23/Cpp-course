#include <iostream>
using namespace std;

int demander_anne()
{
	int annee(0);
	do{
		cout << "Entrez une annee (1583-4000) : ";
		cin >> annee;
	} while (annee < 1583 or annee > 4000);
	return annee;
}

int date_Paques(int year)
{
	int century = year / 100;
	int p = (13 + (8 * century))/25;
	int q = century/4;
	int M = (15 - p + century - q) % 30;
	int N = (4 + century - q) % 7;
	int d = (M + (19 * (year % 19))) % 30;
	int e = (2 * (year % 4) + (4 * (year % 7)) + (6 * d) + N) % 7;
	int day = e + d + 22;
	if (e == 6 and (d == 29 or (d == 28 and (11 * (M + 1) % 30) < 19)))
		day -= 7;
	return day;
}

void	affiche_date(int year, int number)
{
		cout << "Date de Paques en " << year << " : ";
		if (number <= 31)
			cout << number << " mars" << endl;
		else if (number >= 32)
		{
			number -= 31;
			cout << number << " avril" << endl;
		}
}

int main()
{
	int annee = demander_anne();
	int number = date_Paques(annee);
	affiche_date(annee, number);
	return 0;
}
