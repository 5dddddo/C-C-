#include "MyArray.h"
#include <iostream>
using namespace std;
MyArray::MyArray(const MyArray& br)
{
	size = br.size;
	ary = new int[size];
	for (int i = 0; i < size; i++)
		ary[i] = br.ary[i];
};
MyArray & MyArray::operator=(const MyArray & br)
{
	if (this == &br) return *this;
	delete[] ary;
	ary = new int[br.size];
	for (int i = 0; i < br.size; i++)
		ary[i] = br.ary[i];
	size = br.size;
	return *this;
}
bool MyArray::put(int index, int val)
{
	size++;
	if (size - 1 == index)
	{
		ary[index] = val;
		return true;
	}
	else return false;
}
bool MyArray::get(int index, int &getdata)
{
	getdata = ary[index];
	if (getdata == ary[index])
		return true;
	else return false;
}
