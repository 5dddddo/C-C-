#include <iostream>
using namespace std;
#include "MyArray.h"
#include "SmartArray.h"
int main()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	SmartArray cScore(3),mScore(5);
	int i;
	bool res;
	int num;
	int tot = 0;
	int temp[5];

	cout << "ö���� �� ������ ���� �Է�:";
	cin >> temp[0] >> temp[1] >> temp[2];
	for (i = 0; i < 3; i++)
	{
		if (cScore.put(i, temp[i]) == false)
			cout << "�迭 ���� ����" << endl;
		res = cScore.get(i, num);
		if (res) tot += num;
		else cout << "�迭 �б� ����" << endl;
	}
	cout << "ö���� ���� : "<< tot <<"\nö���� ��� : " << tot / 3.0 << endl;
	
	tot = 0;
	cout << "������ �ټ� ������ ���� �Է�:";
	cin >> temp[0] >> temp[1] >> temp[2] >> temp[3] >> temp[4];
	for (i = 0; i < 5; i++)
	{
		if (mScore.put(i, temp[i]) == false)
			cout << "�迭 ���� ����" << endl;
		res = mScore.get(i, num);
		if (res) tot += num;
		else cout << "�迭 �б� ����" << endl;
	}
	cout << "������ ���� : " << tot << "\n������ ��� : " << tot / 5.0 << endl;
	if (mScore > cScore)
		cout << "ö���� �ְ����� ���ں��� ũ�� �ʴ�..." << endl;
	else
		cout << "������ �ְ����� ö�̺��� ũ�� �ʴ�..." << endl;


	return 0;
}