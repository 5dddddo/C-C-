#pragma once
class MyArray
{
public:
	MyArray(){ ary = 0; size = 0; }
	MyArray(int s){ ary = new int[s]; }
	MyArray(const MyArray& br);
	~MyArray(){ delete[] ary; }
	MyArray & operator=(const MyArray & br);
	virtual bool put(int index, int val);
	bool get(int index, int & getdata);
	int getSize(){return size;}
	int * getAry(){ return ary; }
private:
	int size;
	int *ary;
};

