#include <iostream>
using namespace std;
int ** myAlloc(int, int);
void input(int **, int, int);
void output(int **,int,int);
void myDelete(int **, int stdNum, int sbjNum);
int main()
{
	int studentNum, subjectNum;
	int **p;
	cout << "�л� �� :";
	cin >> studentNum;
	cout << "���� �� :";
	cin >> subjectNum;

	p = myAlloc(studentNum, subjectNum);
	input(p, studentNum, subjectNum);
	output(p, studentNum, subjectNum);
	myDelete(p, studentNum, subjectNum);
}

int** myAlloc(int stdNum, int sbjNum)
{
	int **p;
	p = new int *[stdNum]; // p = new (int *)[stdNum];
	for (int i = 0; i < stdNum; i++)
		p[i] = new int[sbjNum];
	return p;
}
void input(int **p, int stdNum, int sbjNum)
{
	for (int i = 0; i < stdNum; i++)
	{
		cout << i+1 << "�� �л� ���� �Է� :" << endl;
		for (int j = 0; j < sbjNum; j++)
			cin >> p[i][j];
	}
}
void output(int **p,int stdNum,int sbjNum)
{
	int sum = 0;
	for (int i = 0; i < stdNum; i++)
	{
		cout << i << " �� : ";
		for (int j = 0; j < sbjNum; j++)
		{
			cout << p[i][j] << " ";
			sum += p[i][j];
		}
		cout << "���� : " << sum;
		cout << endl;
	}
}
void myDelete(int **p,int stdNum,int sbjNum)
{
	for (int i = 0; i < stdNum; i++)
		delete p[i];
	delete[]p;

}