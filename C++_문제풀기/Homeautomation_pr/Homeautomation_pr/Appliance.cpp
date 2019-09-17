#include "Appliance.h"
#include <time.h>

/* Constructor, Destructor Func */
Appliance::Appliance()
{
	machineName = "";		// default : NULL String
	powerConsumption = 0;	// default : 0(��뷮)
	powerFlag = false;		// default : false
	startHour = 0;			// default : 0(���۽ð�)
	useHour = 0;			// default : 0(���ð�)
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
	if (powerFlag == true)	// ��ǰ�� ������ �̹� �����ִ� ���¶��
		return false;		// ���� ���� �� false ����

	// ��ǰ�� ������ �����ִ� �����϶��� ó��
	powerFlag = true;
	time(&startHour);		// startHour�� runtime�� ���۽ð����� ����
	return true;			// ���� ���� �� true ��ȯ
}

bool Appliance::turnOff()
{
	if (powerFlag == false)	// ��ǰ�� ������ �̹� �����ִ� ���¶��
		return false;		// ���� ���� �� false ��ȯ

	// ��ǰ�� ������ �����ִ� �����϶��� ó��
	powerFlag = false;
	time(&useHour);		
	useHour -= startHour;	// ��� �ð� : ���� �ð� - ���۽ð�
	return true;			// ���� ���� �� true ��ȯ
}
