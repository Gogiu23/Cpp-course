#include <iostream>
using namespace std;

enum direction {N = 2, NE, E, SE, S, SO, O, NO };

int main() {
	for (int i(E); i < O; ++i)
	{
		cout << i << " ";
	}
}
