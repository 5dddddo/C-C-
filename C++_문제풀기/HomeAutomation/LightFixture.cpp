#include "LightFixture.h"
void LightFixture::initLightFixture(string machineName, bool powerFlag) // 전등객체 초기화 함수 
{
	this->machineName = machineName;
	this->powerFlag = powerFlag;
}
string LightFixture::getMachineName() const  // machineName 멤버 값 반환 함수
{
	return machineName;
}
bool LightFixture::getPowerFlag() const // powerFlag 멤버 값 반환 함수
{
	return powerFlag;
}
void LightFixture::setMachineName(string machineName)  // machineName 멤버 초기화 함수
{
	this->machineName = machineName;
}
void LightFixture::setPowerFlag(bool powerFlag) // powerFlag 멤버 접근 함수 
{
	this->powerFlag = powerFlag;
}
// member fucntion
bool LightFixture::turnOn()         // 제품(전원)을 켜다
{
	if(this->powerFlag = true ) return true;
	else false;
}
bool LightFixture::turnOff()        // 제품(전원)을 끄다
{
	if (this->powerFlag = false) return true;
	else false;
}
void LightFixture::stateView()// 객체의 상태 출력
{
	if (this->powerFlag == true)
		cout << " (ON)" << endl;
	else cout << " (OFF)" << endl;
}