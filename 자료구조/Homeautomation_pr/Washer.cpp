#include "Washer.h"
enum { NO_OPERATION = 1, GENERAL, BOIL, DRY }; // 세탁기의 상태를 나타내는 열거형 상수

Washer::Washer() :Appliance()
{
	machineState = NO_OPERATION;
}

Washer::Washer(string machineName, int powerConsumption)
	: Appliance(machineName, powerConsumption)
{
	machineState = NO_OPERATION;
}

int Washer::getMachineState() const
{
	return machineState;
}

void Washer::setMachineState(int machineState)
{
	this->machineState = machineState;
}

void Washer::stateView()
{
	cout << "제품명 : " << this->getMachineName() << " (";
	if (this->getPowerFlag() == true)
	{
		cout << "ON) 설정상태 : ";
		switch (this->getMachineState())
		{
		case NO_OPERATION: cout << "무동작"; break;
		case GENERAL: cout << "일반빨래"; break;
		case BOIL: cout << "삶은빨래"; break;
		case DRY: cout << "건조"; break;
		default:; break;
		}
	}
	else
		cout << "OFF)";
	cout << endl;
}