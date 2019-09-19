#include <iostream>
using namespace std;
#include <string>
#include "Profile.h"

Profile::Profile() : name(), addr(), age(0), height(0)
{ }
//-----------------------------------------------------------------------------------
Profile::Profile(string np, string ap, int a, double h)
: name(np), addr(ap), age(a), height(h)
{ }
//-----------------------------------------------------------------------------------
bool Profile::operator>(const Profile &br)
{
	if (height > br.height) return true;
	else return false;
}
//----------------------------------------------------------------------------------
string Profile::getName()
{
	return name;
}
//----------------------------------------------------------------------------------
string Profile::getAddr()
{
	return addr;
}
//----------------------------------------------------------------------------------
int Profile::getAge()
{
	return age;
}
//----------------------------------------------------------------------------------
double Profile::getHeight()
{
	return height;
}
//----------------------------------------------------------------------------------
void Profile::setName(string b)
{
	name = b;
}
//----------------------------------------------------------------------------------
void Profile::setAddr(string b)
{
	addr = b;
}
//----------------------------------------------------------------------------------
void Profile::setAge(int a)
{
	age = a;
}
//----------------------------------------------------------------------------------
void Profile::setHeight(double h)
{
	height = h;
}
