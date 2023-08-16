#include <iostream>
using namespace std;

int main() {
	int i(3);
	int& j(i);
	int * k(&i);
	int * l(new int(10));

	i = 5;
	k = l;
	j = 15;

	cout << i << " " << j << " " << *k << endl;
}
