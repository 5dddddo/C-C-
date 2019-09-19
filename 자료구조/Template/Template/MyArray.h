#pragma once
#include <iostream>
using namespace std;
template <typename T>
class MyArray
{
public:
	MyArray(){ ary = 0; size = 0; }
	MyArray(int s){ ary = new T[s]; }
	MyArray(const MyArray<T>& br);
	~MyArray(){ delete[] ary; }
	MyArray<T>& operator=(const MyArray<T>& br);
	virtual bool put(int index, T val);
	bool get(int index, T& getdata);
	int getSize(){return size;}
	int * getAry(){ return ary; }
private:
	int size;
	T *ary;
};

template <typename T>
MyArray<T>::MyArray(const MyArray<T>& br)
{
	size = br.size;
	ary = new int[size];
	for (int i = 0; i < size; i++)
		ary[i] = br.ary[i];
};
template <typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& br)
{
	if (this == &br) return *this;
	delete[] ary;
	ary = new int[br.size];
	for (int i = 0; i < br.size; i++)
		ary[i] = br.ary[i];
	size = br.size;
	return *this;
}
template <typename T>
bool MyArray<T>::put(int index, T val)
{
	size++;
	if (size - 1 == index)
	{
		ary[index] = val;
		return true;
	}
	else return false;
}
template <typename T>
bool MyArray<T>::get(int index, T& getdata)
{
	getdata = ary[index];
	if (getdata == ary[index])
		return true;
	else return false;
}
