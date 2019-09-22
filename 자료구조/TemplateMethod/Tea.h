#pragma once
#include "Beverage.h"
class Tea :
	public Beverage
{
public:
	Tea();
	~Tea();
	void brew();
	void addCondiment();
};

