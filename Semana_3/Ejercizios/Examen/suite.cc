#include <iostream>
using namespace std;

int main()
{
  int debut(0);
  do {
    cout << "de (>= 1) ? ";
    cin >> debut;
  } while (debut < 1);

  int fin(0);
  do {
    cout << "a (>= " << debut << ") ? ";
    cin >> fin;
  } while (fin < debut);

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/
  while (debut <= fin)
  {
	  int iteration(0);
	  int n(0);
	  n = debut;
	  do {
		  if (n % 3 == 0)
			  n += 4;
		  else if (n % 4 == 0)
			  n /= 2;
		  else
			  --n;
		  ++iteration;
	  } while (n);
	  cout << debut << " -> " << iteration << endl;
	  ++debut;
  }

  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
