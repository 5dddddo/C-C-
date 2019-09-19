#include "AirConditioner.h"

int AirConditioner::getMachineState() const // machineState ����� ��ȯ �Լ�
{
	return machineState;
}
int AirConditioner::getSetTemperature() const  // setTemperature ����� ��ȯ �Լ�
{
	return setTemperature;
}
void AirConditioner::setMachineState(int machineState) // machineState ��� �ʱ�ȭ �Լ�
{
	this->machineState = machineState;
}
void AirConditioner::setSetTemperature(int setTemperature) // setTemperature ��� �ʱ�ȭ �Լ�
{
	this->setTemperature = setTemperature;
}
AirConditioner & AirConditioner::operator++() // ���� �µ��� 1���� �ø���(prefix increment)
{
	setTemperature++;
	return *this;
}
AirConditioner & AirConditioner::operator--() // ���� �µ��� 1���� ������(prefix decrement)
{
	setTemperature--;
	return *this;
}
void AirConditioner::stateView()  // ��ü�� ���� ���
{
	cout << "��ǰ�� : " << this->getMachineName() << " (";
	if (this->getPowerFlag() == true)
	{
		cout << "ON) �������� : ";
		switch (this->getMachineState())
		{
		case SENDAIR: cout << "��ǳ"; break;
		case COOLER: cout << "�ù�"; break;
		case HEATER: cout << "����"; break;
		default:; break;
		}
		cout << "(�����µ� : " << setTemperature << ")";
	}
	else
		cout << "OFF)";
	cout << endl;
}