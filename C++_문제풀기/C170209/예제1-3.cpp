#include<iostream>
using namespace std;
int main()
{
	int ary[5] = { 1, 3, 5, 7, 9 };
	char charary[10] = "apple";
	cout << ary << endl;
	cout << charary << endl;
	cout << (void *)charary << endl;
	for (int i = 0; i < sizeof(ary) / sizeof(int); i++)
		cout << " ary "<< i << ": " << ary[i] << endl;

}