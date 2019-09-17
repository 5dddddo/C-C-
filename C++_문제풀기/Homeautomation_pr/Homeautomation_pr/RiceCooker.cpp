#include "RiceCooker.h"
enum { NO_OPERATION = 1, WARM, COOK, HEAT }; // ����� ���¸� ��Ÿ���� ������ ���

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
	cout << "��ǰ�� : " << this->getMachineName() << " (";
	if (this->getPowerFlag() == true)
	{
		cout << "ON) �������� : ";
		switch (this->getMachineState())
		{
		case NO_OPERATION: cout << "������"; break;
		case WARM: cout << "����"; break;
		case COOK: cout << "������"; break;
		case HEAT: cout << "�����"; break;
		default:; break;
		}
	}
	else
		cout << "OFF)";
	cout << endl;
}