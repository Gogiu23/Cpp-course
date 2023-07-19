#include <iostream>
using namespace std;

int main()
{
	int m;
	int p(4);
	int n(10);
	bool test1(true);
	bool test2(test1 and (p < n));

	for (m = n/2; m < n; ++m) {
		if (test1 and test2){
			cout << p + m << " ";
			test2 = not test2;
		}else {
			cout << n + m << " ";
			test1 = not test1;
		}
	}
	if (test1 and test2){
		cout << "1 ";
	}else {
		cout << "2 ";
	}
	return 0;
}
