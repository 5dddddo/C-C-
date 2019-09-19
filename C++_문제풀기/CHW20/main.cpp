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

	cout << "철이의 세 과목의 점수 입력:";
	cin >> temp[0] >> temp[1] >> temp[2];
	for (i = 0; i < 3; i++)
	{
		if (cScore.put(i, temp[i]) == false)
			cout << "배열 쓰기 실패" << endl;
		res = cScore.get(i, num);
		if (res) tot += num;
		else cout << "배열 읽기 실패" << endl;
	}
	cout << "철이의 총점 : "<< tot <<"\n철이의 평균 : " << tot / 3.0 << endl;
	
	tot = 0;
	cout << "메텔의 다섯 과목의 점수 입력:";
	cin >> temp[0] >> temp[1] >> temp[2] >> temp[3] >> temp[4];
	for (i = 0; i < 5; i++)
	{
		if (mScore.put(i, temp[i]) == false)
			cout << "배열 쓰기 실패" << endl;
		res = mScore.get(i, num);
		if (res) tot += num;
		else cout << "배열 읽기 실패" << endl;
	}
	cout << "메텔의 총점 : " << tot << "\n메텔의 평균 : " << tot / 5.0 << endl;
	if (mScore > cScore)
		cout << "철이의 최고점은 메텔보다 크지 않다..." << endl;
	else
		cout << "메텔의 최고점은 철이보다 크지 않다..." << endl;


	return 0;
}