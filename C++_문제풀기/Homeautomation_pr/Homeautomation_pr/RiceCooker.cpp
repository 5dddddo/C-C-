#include "RiceCooker.h"
enum { NO_OPERATION = 1, WARM, COOK, HEAT }; // 밥솥의 상태를 나타내는 열거형 상수

RiceCooker::RiceCooker() : Appliance()
{
	machineState = NO_OPERATION;
}

RiceCooker::RiceCooker(string machineName, int powerConsumption)
	:Appliance(machineName, powerConsumption)
{
	machineState = NO_OPERATION;
}

int RiceCooker::getMachineState() const
{
	return machineState;
}

void RiceCooker::setMachineState(int machineState)
{
	this->machineState = machineState;
}

// Overriding Function For Appliance Class's Pure Virtual Function
void RiceCooker::stateView()
{
	cout << "제품명 : " << this->getMachineName() << " (";
	if (this->getPowerFlag() == true)
	{
		cout << "ON) 설정상태 : ";
		switch (this->getMachineState())
		{
		case NO_OPERATION: cout << "무동작"; break;
		case WARM: cout << "보온"; break;
		case COOK: cout << "밥짓기"; break;
		case HEAT: cout << "데우기"; break;
		default:; break;
		}
	}
	else
		cout << "OFF)";
	cout << endl;
}