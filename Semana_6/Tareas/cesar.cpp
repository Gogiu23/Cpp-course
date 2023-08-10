#include <iostream>
#include <stdlib.h>
using namespace std;

char code(char c, int n);
string code(string str, int nm);
char decale(char c, char debut, int decalage);
string decode(string str, int num);

int main(){
//	char c('g');
//	c = code(c, -133);
//	cout << c << endl;
//	string str("Avez-vous vu mes 3 chats et mes 2 chiens ?");
//	str = code(str, 4);
//	cout << str << endl;
//	str = decode(str, 4);
//	cout << str << endl;
	return 0;
}

char decale(char c, char debut, int decalage)
{
	while (decalage < 0)
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

string code(string str, int nm)
{
	int i(0);
	while (str[i])
	{
		str[i] = code(str[i], nm);
		i++;
	}
	return str;
}

string decode(string str, int num) 
{
	return (code(str, -num));
}
