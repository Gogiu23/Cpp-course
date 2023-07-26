#include <iostream>
using namespace std;

void f(int p, int m, int n, bool b)
{
	for(int i(p); i >= 0; --i) {
		if ((i >= 2) and b) {
			cout << i - 2 << " ";
		} else {
			cout << i + 2 << " ";
		}
	}

	int k(m);

	while (k <= n) {
		cout << k << " ";
		k *= 3;
	}
	cout << endl;
}

int main()
{
	const int N(9);
	f(N, N/2, N*2, false);
	return 0;
}
