#pragma once
#include <iostream>
using namespace std;
class SingleTone
{
private:
	static SingleTone *instance;
	SingleTone();

public:
	virtual ~SingleTone();
	static SingleTone * getInstance();
	static void destroy();
};