#include "LightFixture.h"
void LightFixture::initLightFixture(string machineName, bool powerFlag) // ���ü �ʱ�ȭ �Լ� 
{
	this->machineName = machineName;
	this->powerFlag = powerFlag;
}
string LightFixture::getMachineName() const  // machineName ��� �� ��ȯ �Լ�
{
	return machineName;
}
bool LightFixture::getPowerFlag() const // powerFlag ��� �� ��ȯ �Լ�
{
	return powerFlag;
}
void LightFixture::setMachineName(string machineName)  // machineName ��� �ʱ�ȭ �Լ�
{
	this->machineName = machineName;
}
void LightFixture::setPowerFlag(bool powerFlag) // powerFlag ��� ���� �Լ� 
{
	this->powerFlag = powerFlag;
}
// member fucntion
bool LightFixture::turnOn()         // ��ǰ(����)�� �Ѵ�
{
	if(this->powerFlag = true ) return true;
	else false;
}
bool LightFixture::turnOff()        // ��ǰ(����)�� ����
{
	if (this->powerFlag = false) return true;
	else false;
}
void LightFixture::stateView()// ��ü�� ���� ���
{
	if (this->powerFlag == true)
		cout << " (ON)" << endl;
	else cout << " (OFF)" << endl;
}