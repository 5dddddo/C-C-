#pragma once
#include <iostream>
using namespace std;

class Profile
{
private:
	string name;
	string addr;
	int age;
	double height;
public:
	Profile();
	Profile(string np, string ap, int a, double h);
	bool operator>(const Profile &br);
	string getName();
	string getAddr();
	int getAge();
	double getHeight();
	void setName(string br);
	void setAddr(string br);
	void setAge(int a);
	void setHeight(double h);
};