#include <iostream>
using namespace std;

char code(char c, int n);
char decale(char c, char debut, int decalage);

int main(){
	char c('a'); 
	c = code(c, 1);
	cout << c << endl;
	return 0;
}

char decale(char c, char debut, int decalage)
{
	if (decalage < 0)
		decalage += 26;
	return (debut + (((c - debut) + decalage) % 26));
}

char code(char c, int n)
{
	if (c >= 'a' && c <= 'z')
		return decale(c, 'a', n);
	else if (c >= 'A' && c <= 'Z')
		return decale(c, 'A', n);
	else
		return c;
}
