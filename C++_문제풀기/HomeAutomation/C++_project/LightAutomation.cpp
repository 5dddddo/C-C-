#include "LightAutomation.h"
#include <iostream>
using namespace std;
void LightAutomation::initLightAutomation() // lightArray�� �޸� ������ ��� 0���� �ʱ�ȭ �ϰ�, lightCnt�� 0���� �ʱ�ȭ
{
	for (int i = 0; i < LIGHT_MAX_CNT; i++)
	{
		lightArray[i].setMachineName("");
		lightArray[i].setPowerFlag(false);
	}
	lightCnt = 0;
}
// getter, setter member function
LightFixture * LightAutomation::getLightArray() // lightArray ��� �� ��ȯ �Լ�
{
	return lightArray;
}
int LightAutomation::getLightCnt() const       // lightCnt ��� �� ��ȯ �Լ�
{
	return lightCnt;
}
// member function
bool LightAutomation::addAppliance(LightFixture &ap)	      // parameter�� ���ü�� ��Ͽ� �߰�. ������ �̸��� ���ü�� ��ϵ��� �ʵ��� ��
{
	if (lightCnt == 0)
	{
		lightArray[lightCnt] = ap;
		lightCnt++;
		return true;
	}
	if (lightCnt < LIGHT_MAX_CNT)
	{
		for (int i = 0; i < lightCnt; i++)
		{
			if (ap.getMachineName() != lightArray[i].getMachineName() && i == lightCnt - 1)
			{
				lightArray[lightCnt] = ap;
				lightCnt++;
				return true;
			}
		}
	}
	else return false;
}
int LightAutomation::searchMachine(string machineName)    // ����� �ش��ϴ� ������ ã�Ƽ� �迭�� index����/���� �� -1 ����
{
	if (lightCnt == 0)
		return -1;
	for (int i = 0; i < lightCnt; i++)
	{
		if (machineName == lightArray[i].getMachineName())
			return i;
		if (machineName != lightArray[i].getMachineName() && i == lightCnt - 1)
			return -1;
	}
}
bool LightAutomation::deleteAppliance(string machineName)  // ����� �ش��ϴ� ������ ��Ͽ��� �����ϴ�
{
	for (int i = 0; i < lightCnt; i++)
	{
		if (machineName == lightArray[i].getMachineName())
		{
			lightArray[i].setMachineName("");
			lightArray[i].setPowerFlag(false);
			lightCnt--;
			return true;
		}
		if (machineName != lightArray[i].getMachineName() && i == lightCnt - 1)
			return false;
	}
}
void LightAutomation::listDisplayAppliance()               // ��ϵ� ���� ��ü ��� �� On.Off ���¸� Ȯ��(���)�ϴ�
{
	for (int i = 0; i < lightCnt; i++)
	{
		cout << "��ǰ�� : " << lightArray[i].getMachineName();
		lightArray[i].stateView();
	}
}
bool LightAutomation::controlAppliance(string machineName)
{
	for (int i = 0; i < lightCnt; i++)
	{
		if (machineName == lightArray[i].getMachineName())
		{
			if (lightArray[i].getPowerFlag() == true)
				lightArray[i].turnOff();
			else lightArray[i].turnOn();
			return true;
		}
		if (machineName != lightArray[i].getMachineName() && i == lightCnt - 1)
			return false;
	}
}