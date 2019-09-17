#include "Appliance.h"
#include <time.h>

/* Constructor, Destructor Func */
Appliance::Appliance()
{
	machineName = "";		// default : NULL String
	powerConsumption = 0;	// default : 0(사용량)
	powerFlag = false;		// default : false
	startHour = 0;			// default : 0(시작시간)
	useHour = 0;			// default : 0(사용시간)
}

Appliance::Appliance(string machineName, int powerConsumption, bool powerFlag,
	time_t startHour, time_t useHour)
{
	this->machineName = machineName;
	this->powerConsumption = powerConsumption;
	this->powerFlag = powerFlag;
	this->startHour = startHour;
	this->useHour = useHour;
}


/* getter, setter Member Func */
string Appliance::getMachineName() const
{
	return machineName;
}

bool Appliance::getPowerFlag() const
{
	return powerFlag;
}

int Appliance::getPowerConsumption() const
{
	return powerConsumption;
}

time_t Appliance::getStartHour()
{
	return startHour;
}

time_t Appliance::getUseHour()
{
	return useHour;
}

void Appliance::setMachineName(string machineName)
{
	this->machineName = machineName;
}

void Appliance::setPowerFlag(bool powerFlag)
{
	this->powerFlag = powerFlag;
}

void Appliance::setPowerConsumption(int powerConsumption)
{
	this->powerConsumption = powerConsumption;
}


/* Appliance Class Member Func */
bool Appliance::turnOn()
{
	if (powerFlag == true)	// 제품의 전원이 이미 켜져있는 상태라면
		return false;		// 제어 실패 값 false 리턴

	// 제품의 전원이 꺼져있는 상태일때의 처리
	powerFlag = true;
	time(&startHour);		// startHour를 runtime시 시작시간으로 세팅
	return true;			// 제어 성공 값 true 반환
}

bool Appliance::turnOff()
{
	if (powerFlag == false)	// 제품의 전원이 이미 꺼져있는 상태라면
		return false;		// 제어 실패 값 false 반환

	// 제품의 전원이 켜져있는 상태일때의 처리
	powerFlag = false;
	time(&useHour);		
	useHour -= startHour;	// 사용 시간 : 현재 시간 - 시작시간
	return true;			// 제어 성공 값 true 반환
}
