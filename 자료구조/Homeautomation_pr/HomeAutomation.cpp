#include "HomeAutomation.h"
HomeAutomation::HomeAutomation() // appliaceArray�� �޸� ������ ��� 0���� �ʱ�ȭ �ϰ�, applianceCnt�� 0���� �ʱ�ȭ
{
	for (int i = 0; i < APPLIANCE_MAX_CNT; i++)
		applianceArray[i] = NULL;
	applianceCnt = 0;
}
HomeAutomation::HomeAutomation(const HomeAutomation &r) // deep copy constructor
{
	for (int i = 0; i < r.applianceCnt; i++)
	{
		applianceArray[i]->setMachineName(r.applianceArray[i]->getMachineName());
		applianceArray[i]->setPowerFlag(r.applianceArray[i]->getPowerFlag());
		applianceArray[i]->setPowerConsumption(r.applianceArray[i]->getPowerConsumption());
	}
	applianceCnt = r.applianceCnt;
}
HomeAutomation::~HomeAutomation() // applianceArray�� ���� �Ҵ�� ��ü�� ��� ������
{
	for (int i = 0; i < applianceCnt; i++)
		delete applianceArray[i];
}
Appliance ** HomeAutomation::getApplianceArray() // applianceArray ��� �� ��ȯ �Լ�
{
	return applianceArray;
}
int HomeAutomation::getApplianceCnt() const // applianceCnt ��� �� ��ȯ �Լ�
{
	return applianceCnt;
}

HomeAutomation & HomeAutomation::operator=(const HomeAutomation &r) // ����(�Ҵ�)������ �����ε� �Լ�
{
	int i;
	if (this == &r) return *this;
	for (i = 0; i < applianceCnt; i++)
		delete applianceArray[i];
	for (i = 0; i < r.applianceCnt; i++)
	{
		applianceArray[i]->setMachineName(r.applianceArray[i]->getMachineName());
		applianceArray[i]->setPowerFlag(r.applianceArray[i]->getPowerFlag());
		applianceArray[i]->setPowerConsumption(r.applianceArray[i]->getPowerConsumption());
	}
	applianceCnt = r.applianceCnt;
	return *this;
}
bool HomeAutomation::addAppliance(Appliance *ap)	// ������ǰ�� ��Ͽ� �߰�.  ������ ��ǰ�� �߰� �Ұ���. 
{
	if (applianceCnt == 0)
	{
		applianceArray[applianceCnt] = ap;
		applianceCnt++;
		return true;
	}
	if (applianceCnt < APPLIANCE_MAX_CNT)
	{
		for (int i = 0; i < applianceCnt; i++)
		{
			if (ap->getMachineName() != applianceArray[i]->getMachineName() && i == applianceCnt - 1)
			{
				applianceArray[applianceCnt] = ap;
				applianceCnt++;
				return true;
			}
			if (ap->getMachineName() == applianceArray[i]->getMachineName())
				return false;
		}
	}
	else return false;
}
int HomeAutomation::searchMachine(string machineName) // ������ǰ�� �ش��ϴ� ������ǰ�� ã�Ƽ� �迭�� index����/���� �� -1 ����
{
	if (applianceCnt == 0)
		return -1;
	for (int i = 0; i < applianceCnt; i++)
	{
		if (machineName == applianceArray[i]->getMachineName())
			return i;
		if (machineName != applianceArray[i]->getMachineName() && i == applianceCnt - 1)
			return -1;
	}
}
bool HomeAutomation::deleteAppliance(string machineName) // ������ǰ�� �ش��ϴ� ������ǰ�� ��Ͽ��� �����ϴ�
{
	/*char control;
	if (applianceCnt == 0)
	return false;
	for (int i = 0; i < applianceCnt; i++)
	{
	if (machineName == applianceArray[i]->getMachineName())
	{
	cout << "** ������ �����ϰڽ��ϱ�?(y/n) : ";
	cin >> control;
	while (cin.fail() || (control != 'Y' && control != 'y' && control != 'N' &&control != 'n'))
	{
	cin.clear();
	while (cin.get() == '\n');
	cout << "** ������ �����ϰڽ��ϱ�?(y/n) : ";
	cin >> control;
	}
	if (control == 'y' || control == 'Y')
	{
	applianceArray[i]->setMachineName("");
	applianceArray[i]->setPowerFlag(false);
	applianceCnt--;
	return true;
	}
	else return false;
	}
	if (machineName != applianceArray[i]->getMachineName() && i == applianceCnt - 1)
	return false;
	}*/

	char control;
	int i;
	if (applianceCnt == 0)
		throw "";
	for (i = 0; i < applianceCnt; i++)
	{
		if (machineName == applianceArray[i]->getMachineName())
		{
			cout << "** ������ �����ϰڽ��ϱ�?(y/n) : ";
			cin >> control;
			while (cin.fail() || (control != 'Y' && control != 'y' && control != 'N' &&control != 'n'))
			{
				cin.clear();
				while (cin.get() == '\n');
				cout << "** ������ �����ϰڽ��ϱ�?(y/n) : ";
				cin >> control;
			}
			if (control == 'y' || control == 'Y')
			{
				applianceArray[i]->setMachineName("");
				applianceArray[i]->setPowerFlag(false);
				applianceCnt--;
				return true;
			}
			else
				throw "";
		}
	}
	if (i == applianceCnt)
		throw "";
}
void HomeAutomation::listDisplayAppliance() // ��ϵ� ������ǰ ��ü ��� �� ���¸�  Ȯ���ϴ�
{
	for (int i = 0; i < applianceCnt; i++)
		applianceArray[i]->stateView();
}
bool HomeAutomation::controlAppliance(string machineName)   // �ش� ������ǰ�� �����ϴ�
{
	char control;
	for (int i = 0; i < applianceCnt; i++)
	{
		if (machineName == applianceArray[i]->getMachineName())
		{
			if (applianceArray[i]->getPowerFlag() == false)
			{
				cout << "������ �ѽðڽ��ϱ�?(Y/N) : ";
				cin >> control;
				while (cin.fail() || (control != 'Y' && control != 'y' && control != 'N' &&control != 'n'))
				{
					cin.clear();
					while (cin.get() == '\n');
					cout << "������ �ѽðڽ��ϱ�?(Y/N) : ";
					cin >> control;
				}
				if (control == 'Y' || control == 'y')
					applianceArray[i]->turnOn();
				else { applianceArray[i]->turnOff(); return true; }
			}
			setStateAppliance(applianceArray[i]);
			return true;
		}
		if (machineName != applianceArray[i]->getMachineName() && i == applianceCnt - 1)
			return false;
	}
}

void HomeAutomation::setStateAppliance(Appliance * ap) // �����ִ� ������ǰ�� ���¸� �����ϴ�
{
	int num, temp = 0;
	if (dynamic_cast<RiceCooker *>(ap))
	{
		cout << "1.������ / 2.���� / 3.������ / 4.����� / 5.���� : ";
		cin >> num;
		while (cin.fail() || (num <1 || num >5))
		{
			cin.clear();
			while (cin.get() == '\n');
			cout << "1.������ / 2.���� / 3.������ / 4.����� / 5.���� : ";
			cin >> num;
		}
		if (num == 5) ap->turnOff();
		else dynamic_cast<RiceCooker *>(ap)->setMachineState(num);
		dynamic_cast<RiceCooker *>(ap)->stateView();
	}
	else if (dynamic_cast<Washer *>(ap))
	{
		cout << "1.������ / 2.�Ϲݻ��� / 3.�������� / 4.���� / 5.���� : ";
		cin >> num;
		while (cin.fail() || (num <1 || num >5))
		{
			cin.clear();
			while (cin.get() == '\n');
			cout << "1.������ / 2.�Ϲݻ��� / 3.�������� / 4.���� / 5.���� : ";
			cin >> num;
		}
		if (num == 5) ap->turnOff();
		else dynamic_cast<Washer *>(ap)->setMachineState(num);
		dynamic_cast<Washer *>(ap)->stateView();
	}
	else if (dynamic_cast <AirConditioner *>(ap))
	{
		cout << "1.��ǳ / 2.�ù� / 3.���� / 4.���� : ";
		cin >> num;
		while (cin.fail() || (num <1 || num >4))
		{
			cin.clear();
			while (cin.get() == '\n');
			cout << "1.��ǳ / 2.�ù� / 3.���� / 4.���� : ";
			cin >> num;
		}
		if (num == 4) ap->turnOff();
		else
		{
			dynamic_cast<AirConditioner *>(ap)->setMachineState(num);
			while (temp != 3)
			{
				cout << "1.�µ� �ø��� / 2.�µ� ������ / 3.�µ����� ���� : ";
				cin >> temp;
				while (cin.fail() || (temp < 1 || temp > 3))
				{
					cin.clear();
					while (cin.get() == '\n');
					cout << "1.�µ� �ø��� / 2.�µ� ������ / 3.�µ����� ���� : ";
					cin >> temp;
				}
				switch (temp)
				{
				case 1:dynamic_cast<AirConditioner *>(ap)->operator++(); break;
				case 2:dynamic_cast<AirConditioner *>(ap)->operator--(); break;
				case 3:break;
				}
			}
		}
		dynamic_cast<AirConditioner *>(ap)->stateView();
	}
}
