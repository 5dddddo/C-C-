#include <iostream>
#pragma warning (disable:4996)
using namespace std;
class Robot{
public:
	Robot(){
		cout << "Robot constructor" << endl;
	}
	~Robot(){
		cout << "Robot destructor" << endl;
	}
};
int main()
{
	Robot *rp;
	rp = new Robot[3];
	delete [] rp;
	return 0;
}