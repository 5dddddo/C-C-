#include "HomeAutomation.h"
HomeAutomation::HomeAutomation() // appliaceArray의 메모리 영역을 모두 0으로 초기화 하고, applianceCnt를 0으로 초기화
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
HomeAutomation::~HomeAutomation() // applianceArray에 동적 할당된 객체를 모두 해제함
{
	for (int i = 0; i < applianceCnt; i++)
		delete applianceArray[i];
}
Appliance ** HomeAutomation::getApplianceArray() // applianceArray 멤버 값 반환 함수
{
	return applianceArray;
}
int HomeAutomation::getApplianceCnt() const // applianceCnt 멤버 값 반환 함수
{
	return applianceCnt;
}

HomeAutomation & HomeAutomation::operator=(const HomeAutomation &r) // 대입(할당)연산자 오버로딩 함수
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
bool HomeAutomation::addAppliance(Appliance *ap)	// 가전제품을 목록에 추가.  동일한 제품명 추가 불가능. 
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
int HomeAutomation::searchMachine(string machineName) // 가전제품명에 해당하는 가전제품을 찾아서 배열의 index리턴/없을 시 -1 리턴
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
bool HomeAutomation::deleteAppliance(string machineName) // 가전제품명에 해당하는 가전제품을 목록에서 삭제하다
{
	/*char control;
	if (applianceCnt == 0)
	return false;
	for (int i = 0; i < applianceCnt; i++)
	{
	if (machineName == applianceArray[i]->getMachineName())
	{
	cout << "** 정말로 삭제하겠습니까?(y/n) : ";
	cin >> control;
	while (cin.fail() || (control != 'Y' && control != 'y' && control != 'N' &&control != 'n'))
	{
	cin.clear();
	while (cin.get() == '\n');
	cout << "** 정말로 삭제하겠습니까?(y/n) : ";
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
			cout << "** 정말로 삭제하겠습니까?(y/n) : ";
			cin >> control;
			while (cin.fail() || (control != 'Y' && control != 'y' && control != 'N' &&control != 'n'))
			{
				cin.clear();
				while (cin.get() == '\n');
				cout << "** 정말로 삭제하겠습니까?(y/n) : ";
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
void HomeAutomation::listDisplayAppliance() // 등록된 가전제품 전체 목록 및 상태를  확인하다
{
	for (int i = 0; i < applianceCnt; i++)
		applianceArray[i]->stateView();
}
bool HomeAutomation::controlAppliance(string machineName)   // 해당 가전제품을 제어하다
{
	char control;
	for (int i = 0; i < applianceCnt; i++)
	{
		if (machineName == applianceArray[i]->getMachineName())
		{
			if (applianceArray[i]->getPowerFlag() == false)
			{
				cout << "전원을 켜시겠습니까?(Y/N) : ";
				cin >> control;
				while (cin.fail() || (control != 'Y' && control != 'y' && control != 'N' &&control != 'n'))
				{
					cin.clear();
					while (cin.get() == '\n');
					cout << "전원을 켜시겠습니까?(Y/N) : ";
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

void HomeAutomation::setStateAppliance(Appliance * ap) // 켜져있는 가전제품의 상태를 변경하다
{
	int num, temp = 0;
	if (dynamic_cast<RiceCooker *>(ap))
	{
		cout << "1.무동작 / 2.보온 / 3.밥짓기 / 4.데우기 / 5.끄기 : ";
		cin >> num;
		while (cin.fail() || (num <1 || num >5))
		{
			cin.clear();
			while (cin.get() == '\n');
			cout << "1.무동작 / 2.보온 / 3.밥짓기 / 4.데우기 / 5.끄기 : ";
			cin >> num;
		}
		if (num == 5) ap->turnOff();
		else dynamic_cast<RiceCooker *>(ap)->setMachineState(num);
		dynamic_cast<RiceCooker *>(ap)->stateView();
	}
	else if (dynamic_cast<Washer *>(ap))
	{
		cout << "1.무동작 / 2.일반빨래 / 3.삶은빨래 / 4.건조 / 5.끄기 : ";
		cin >> num;
		while (cin.fail() || (num <1 || num >5))
		{
			cin.clear();
			while (cin.get() == '\n');
			cout << "1.무동작 / 2.일반빨래 / 3.삶은빨래 / 4.건조 / 5.끄기 : ";
			cin >> num;
		}
		if (num == 5) ap->turnOff();
		else dynamic_cast<Washer *>(ap)->setMachineState(num);
		dynamic_cast<Washer *>(ap)->stateView();
	}
	else if (dynamic_cast <AirConditioner *>(ap))
	{
		cout << "1.송풍 / 2.냉방 / 3.난방 / 4.끄기 : ";
		cin >> num;
		while (cin.fail() || (num <1 || num >4))
		{
			cin.clear();
			while (cin.get() == '\n');
			cout << "1.송풍 / 2.냉방 / 3.난방 / 4.끄기 : ";
			cin >> num;
		}
		if (num == 4) ap->turnOff();
		else
		{
			dynamic_cast<AirConditioner *>(ap)->setMachineState(num);
			while (temp != 3)
			{
				cout << "1.온도 올리기 / 2.온도 내리기 / 3.온도조절 종료 : ";
				cin >> temp;
				while (cin.fail() || (temp < 1 || temp > 3))
				{
					cin.clear();
					while (cin.get() == '\n');
					cout << "1.온도 올리기 / 2.온도 내리기 / 3.온도조절 종료 : ";
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
