#pragma once
class Beverage
{
public:
	Beverage();
	~Beverage();
	void make();
	void boilWater();
	virtual void brew() = 0;
	void pourInCup();
	virtual void addCondiment() = 0;

};

