#include "Beverage.h"
#include <iostream>
using namespace std;

Beverage::Beverage()
{
}


Beverage::~Beverage()
{
}

void Beverage::make()
{
	boilWater();
	brew();
	pourInCup();
	addCondiment();
}

void Beverage::boilWater()
{
	cout << "¹°À» ²úÀÔ´Ï´Ù." << endl;
}

void Beverage::pourInCup()
{
	cout << "ÄÅ¿¡ µû¸¨´Ï´Ù." << endl;
}