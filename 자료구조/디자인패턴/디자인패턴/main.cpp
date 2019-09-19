#include "SingleTone.h"
using std::cout;
using std::endl;
int main()
{
	SingleTone *s1 = SingleTone::getInstance();
	SingleTone *s2 = SingleTone::getInstance();

	cout << s1 << endl;
	cout << s2 << endl;

	return 0;
}