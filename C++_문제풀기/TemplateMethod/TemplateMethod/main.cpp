#include "Coffee.h"
#include "Tea.h"
int main()
{
	Beverage *coffee = new Coffee();
	Beverage *tea = new Tea();
	tea->make();
	coffee->make();

	delete coffee;
	delete tea;
}