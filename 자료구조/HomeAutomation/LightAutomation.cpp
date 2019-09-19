#include "LightAutomation.h"
#include <iostream>
using namespace std;
void LightAutomation::initLightAutomation() // lightArray의 메모리 영역을 모두 0으로 초기화 하고, lightCnt를 0으로 초기화
{
	for (int i = 0; i < LIGHT_MAX_CNT; i++)
	{
		lightArray[i].setMachineName("");
		lightArray[i].setPowerFlag(false);
	}
	lightCnt = 0;
}
// getter, setter member function
LightFixture * LightAutomation::getLightArray() // lightArray 멤버 값 반환 함수
{
	return lightArray;
}
int LightAutomation::getLightCnt() const       // lightCnt 멤버 값 반환 함수
{
	return lightCnt;
}
// member function
bool LightAutomation::addAppliance(LightFixture &ap)	      // parameter의 전등객체를 목록에 추가. 동일한 이름의 전등객체는 등록되지 않도록 함
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
int LightAutomation::searchMachine(string machineName)    // 전등명에 해당하는 전등을 찾아서 배열의 index리턴/없을 시 -1 리턴
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
bool LightAutomation::deleteAppliance(string machineName)  // 전등명에 해당하는 전등을 목록에서 삭제하다
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
void LightAutomation::listDisplayAppliance()               // 등록된 전등 전체 목록 및 On.Off 상태를 확인(출력)하다
{
	for (int i = 0; i < lightCnt; i++)
	{
		cout << "제품명 : " << lightArray[i].getMachineName();
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