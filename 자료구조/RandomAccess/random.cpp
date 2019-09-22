#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	fstream rwFileStream;
	int nNum;
	rwFileStream.open("randomFileEx",ios::out | ios:: binary); //2������ output�� �����ϰ� ���� open
	for (int i = 0; i < 1000; i++) //1~1000���� ���Ͽ� ����
	{
		nNum = i;
		rwFileStream.write((char*)&nNum, sizeof(int));
	}
	rwFileStream.close();

	rwFileStream.open("randomFileEx", ios::in | ios::out| ios::binary); //2������ input,output �����ϰ� ���� open
	for (int i = 1; i != 20; i++) //10��°���� �б�
	{
		//rwFileStream.seekg((i - 1) *sizeof(int));
		rwFileStream.read((char *)&nNum, sizeof(int));
		cout << nNum << endl;
	}
	rwFileStream.seekp(13 * sizeof(int)); //13��° ���� 15�� �ٲٱ�
	int nTemp = 15;
	rwFileStream.write((char*)&nTemp, sizeof(int));
	rwFileStream.seekg(13 *sizeof(int));
	rwFileStream.read((char *)&nNum, sizeof(int));
	cout << nNum << endl;
	rwFileStream.close();
	return 0;
}