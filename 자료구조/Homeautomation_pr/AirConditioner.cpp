#include "AirConditioner.h"

int AirConditioner::getMachineState() const // machineState 멤버값 반환 함수
{
	return machineState;
}
int AirConditioner::getSetTemperature() const  // setTemperature 멤버값 반환 함수
{
	return setTemperature;
}
void AirConditioner::setMachineState(int machineState) // machineState 멤버 초기화 함수
{
	this->machineState = machineState;
}
void AirConditioner::setSetTemperature(int setTemperature) // setTemperature 멤버 초기화 함수
{
	this->setTemperature = setTemperature;
}
AirConditioner & AirConditioner::operator++() // 설정 온도를 1도씩 올린다(prefix increment)
{
	setTemperature++;
	return *this;
}
AirConditioner & AirConditioner::operator--() // 설정 온도를 1도씩 내린다(prefix decrement)
{
	setTemperature--;
	return *this;
}
void AirConditioner::stateView()  // 객체의 상태 출력
{
	cout << "제품명 : " << this->getMachineName() << " (";
	if (this->getPowerFlag() == true)
	{
		cout << "ON) 설정상태 : ";
		switch (this->getMachineState())
		{
		case SENDAIR: cout << "송풍"; break;
		case COOLER: cout << "냉방"; break;
		case HEATER: cout << "난방"; break;
		default:; break;
		}
		cout << "(설정온도 : " << setTemperature << ")";
	}
	else
		cout << "OFF)";
	cout << endl;
}