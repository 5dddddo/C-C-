#pragma once
#include "Beverage.h"
class Coffee :
	public Beverage
{
public:
	Coffee();
	~Coffee();
	void brew();
	void addCondiment();
};

