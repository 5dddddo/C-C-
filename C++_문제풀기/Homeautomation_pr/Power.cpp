#include "Power.h"
#include "HomeAutomation.h"
int Power::calPowerConsumption(HomeAutomation &rHa)
{
	HomeAutomation *hp = &rHa;
	Appliance ** ary = rHa.getApplianceArray();
	time_t useHour;
	int powerConsumption;
	int sum = 0;
	for (int i = 0; i < hp->getApplianceCnt(); i++)
	{
		useHour = ary[i]->getUseHour();
		powerConsumption = ary[i]->getPowerConsumption();
		sum += useHour / 3600 * powerConsumption;
	}
	return sum;
}