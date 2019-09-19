#pragma once
#include "MyArray.h"
class SmartArray :
	public MyArray
{
public:
	SmartArray(){};
	SmartArray(int s) :MyArray(s), max(0){}
	bool put(int index, int val);
	int getMax();
	bool operator>(const SmartArray &br);
private:
	int max;
};

