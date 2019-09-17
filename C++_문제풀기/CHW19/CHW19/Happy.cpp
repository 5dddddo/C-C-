#include "Happy.h"
#pragma warning (disable: 4996)
Happy::Happy(char * np, int money)
{
	name = np;
	this->money = money;
	index = 0;
}


Happy::Happy(Happy &r)
{
	for (int i = 0; i < r.index; i++)
	{
		list[i] = new char[strlen(r.list[i]) + 1];
		strcpy(list[i], r.list[i]);
	}
	name = r.name;
	money = r.money;
	index = r.index;
}


Happy::~Happy()
{
	for (int i = 0; i < index; i++)
		delete[] list[i];
}


Happy& Happy::operator=(Happy &r)
{
	if (this == &r) return *this;
	for (int i = 0; i < index; i++)
		delete[] list[i];
	for (int i = 0; i < r.index; i++)
	{
		list[i] = new char[strlen(r.list[i]) + 1];
		strcpy(list[i], r.list[i]);
	}
	name = r.name;
	money = r.money;
	index = r.index;
	return *this;
}


void Happy::use(char *lp, int n)
{
	if (money >= n && index < 99)
	{
		list[index] = new char[strlen(lp) + 1];
		strcpy(list[index], lp);
		money -= n;
		index++;
	}
	else cout << "ÀÜ¾× or  ºÎÁ·" << endl;
}


Happy& Happy::winner(Happy &r)
{
	if (money > r.money)
		return *this;
	else return r;
}


void Happy::setName(string &name)
{
	this->name = name;
}


string& Happy::getName()
{
	return name;
}


void Happy::setMoney(int money)
{
	this->money = money;
}

int Happy::getMoney()
{
	return money;
}


char ** Happy::getList()
{
	return list;
}


int Happy::getIndex()
{
	return index;
}


