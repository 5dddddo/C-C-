#include<iostream>
#pragma warning (disable : 4996)
using namespace std;
void swap_ptr(char *(&a), char *(&b));
int main()
{
	char *ap = "apple";
	char *bp = "banana";
	cout << "�ٲٱ� ���� ���ڿ� : " << ap << " " << bp << endl;
	swap_ptr(ap, bp);
	cout << "�ٲ� ���� ���ڿ� : " << ap << " " << bp << endl;
	return 0;
}

void swap_ptr(char *(&a), char *(&b))
{
	char *temp;
	temp = a;
	a = b;
	b = temp;
}