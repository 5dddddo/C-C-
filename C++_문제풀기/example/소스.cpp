#include <iostream>
using namespace std;
void prn(char *);
void prn(char *, int = 10);
int main()
{
	char str[10] = "star";
	prn(str);
	prn("Monn");
}
void prn(char *p)
{
	cout << p << endl;
}
void prn(char *p, int rc)
{
	for (int i = 0; i < rc; i++)
	{
		cout << p << endl;
	}
}