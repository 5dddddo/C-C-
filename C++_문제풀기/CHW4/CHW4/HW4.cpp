#include <iostream>
#include <string.h>
using namespace std;
double max(double, double);
char* max(char *, char *);
int main()
{
	double num1, num2, maxNum;
	char str1[20], str2[20];
	char *maxStr;
	cout << "�� �Ǽ� �Է� : ";
	cin >> num1 >> num2;
	maxNum = max(num1, num2);
	cout << "ū �� : " << maxNum << endl;

	cout << "�� ���ڿ� �Է� : ";
	cin >> str1 >> str2;
	maxStr = max(str1, str2);
	cout << "�� ���ڿ� : " << maxStr << endl;
	return 0;
}

double max(double n1, double n2)
{
	if (n1 >= n2) return n1;
	else return n2;
}
char* max(char *s1, char *s2)
{
	if (strlen(s1) >= strlen(s2)) return s1;
	else return s2;
}