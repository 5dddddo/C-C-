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
	cout << "두 실수 입력 : ";
	cin >> num1 >> num2;
	maxNum = max(num1, num2);
	cout << "큰 값 : " << maxNum << endl;

	cout << "두 문자열 입력 : ";
	cin >> str1 >> str2;
	maxStr = max(str1, str2);
	cout << "긴 문자열 : " << maxStr << endl;
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