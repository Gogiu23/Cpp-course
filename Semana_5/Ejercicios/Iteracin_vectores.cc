#include <vector>
#include <iostream>
using namespace std;

int main(){
	vector<double> v(3, 1);

	for (auto& x : v) {
		x += 1.1;
	}
	for (auto x : v) {
		cout << x << ", ";
	}
}
