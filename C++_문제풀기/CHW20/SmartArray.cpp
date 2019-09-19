#include "SmartArray.h"

bool SmartArray::put(int index, int val)
{
	bool res;
	res = MyArray::put(index, val);
	if (val > max)
		max = val;
	return res;
}

int SmartArray::getMax()
{
	return max;
}


bool SmartArray::operator>(const SmartArray &br)
{
	if (max > br.max)
		return true;
	else return false;
}
