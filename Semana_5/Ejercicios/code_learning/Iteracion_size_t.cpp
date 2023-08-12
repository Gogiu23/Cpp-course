#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> ages(5);

	for (size_t i(0); i < ages.size(); ++i) {
		cout << "entrada edad trabajador nr " << i + 1 << ": ";
		cin >> ages[i];
	}

	int n(1);
	for (auto i : ages) {
		cout << "trabajador n. " << n << ": " << i << endl;
		++n;
	}
}
