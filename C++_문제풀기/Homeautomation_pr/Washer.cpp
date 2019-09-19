#include "Washer.h"
enum { NO_OPERATION = 1, GENERAL, BOIL, DRY }; // ��Ź���� ���¸� ��Ÿ���� ������ ���

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
	cout << "��ǰ�� : " << this->getMachineName() << " (";
	if (this->getPowerFlag() == true)
	{
		cout << "ON) �������� : ";
		switch (this->getMachineState())
		{
		case NO_OPERATION: cout << "������"; break;
		case GENERAL: cout << "�Ϲݻ���"; break;
		case BOIL: cout << "��������"; break;
		case DRY: cout << "����"; break;
		default:; break;
		}
	}
	else
		cout << "OFF)";
	cout << endl;
}