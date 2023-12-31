#include <iostream>
#include <vector>
using namespace std;

int f(int n)
{
	vector<int> v;
	int j(0);

	while (n != 0) {
		v.push_back(n % 1000);
		n = n / 1000;
	}

	if (not v.empty()) {
		for (size_t i(v.size()-1); i > 0; --i) {
			for (++j; v[i] >= j; j = j + 2) {
				v[i] = v[i] - j;
			}

			j = 10 * (j-1);
			v[i-1] = v[i-1] + 10 * v[i];
		}

		for (++j; v[0] >= j; j = j + 2) {
			v[0] = v[0] - j;
		}
		return 2*j; //respuesta correcta
	}
	return 0;
}

int main()
{
	cout << f(40000) << endl;
	return 0;
}
