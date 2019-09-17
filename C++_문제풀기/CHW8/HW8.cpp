#include<iostream>
#pragma warning (disable : 4996)
using namespace std;
void swap_ptr(char *(&a), char *(&b));
int main()
{
	char *ap = "apple";
	char *bp = "banana";
	cout << "바꾸기 전의 문자열 : " << ap << " " << bp << endl;
	swap_ptr(ap, bp);
	cout << "바꾼 후의 문자열 : " << ap << " " << bp << endl;
	return 0;
}

void swap_ptr(char *(&a), char *(&b))
{
	char *temp;
	temp = a;
	a = b;
	b = temp;
}