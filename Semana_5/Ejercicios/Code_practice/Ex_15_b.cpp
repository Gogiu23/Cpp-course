#include <vector>
#include <iostream>
using namespace std;

void f(vector<int>& tab, vector<int>& tab2);

int main() {
	vector<int> tab = {3, 2, 1, 3};
	vector<int> tab2;
	f(tab, tab2);
	for (auto tabs : tab2) {
		cout << tabs << endl;
	}
}


void f(vector<int>& tab, vector<int>& tab2) {

	for (size_t i(0); i < tab.size(); ++i) {
		tab2.push_back(tab[0]);
	}
}
