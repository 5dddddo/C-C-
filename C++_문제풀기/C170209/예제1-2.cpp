#include <iostream>
using namespace std;
void myflush();
int main()
{
	int num;
		cin >> num;
		while (cin.fail())
		{
			myflush();
			cin >> num;
		}

		cout << "num : " << num << endl;

}

void myflush()
{
	cin.clear();
	while (cin.get() != '\n');
}