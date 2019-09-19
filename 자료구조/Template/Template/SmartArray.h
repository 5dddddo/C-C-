#pragma once
#include "MyArray.h"
template <typename T>
class SmartArray :
	public MyArray<T>
{
public:
	SmartArray(){};
	SmartArray(int s) :MyArray<T>(s), max(0){}
	bool put(int index, T val);
	T getMax();
	bool operator>(const SmartArray<T> &br);
private:
	int max;
};
#include "SmartArray.h"

template <typename T>
bool SmartArray<T>::put(int index, T val)
{
	bool res;
	res = MyArray<T>::put(index, val);
	if (val > max)
		max = val;
	return res;
}

template <typename T>
T SmartArray<T>::getMax()
{
	return max;
}


template <typename T>
bool SmartArray<T>::operator>(const SmartArray<T> &br)
{
	if (max > br.max)
		return true;
	else return false;
}

