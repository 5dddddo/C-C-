#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	fstream rwFileStream;
	int nNum;
	rwFileStream.open("randomFileEx",ios::out | ios:: binary); //2진수로 output만 가능하게 파일 open
	for (int i = 0; i < 1000; i++) //1~1000까지 파일에 쓰기
	{
		nNum = i;
		rwFileStream.write((char*)&nNum, sizeof(int));
	}
	rwFileStream.close();

	rwFileStream.open("randomFileEx", ios::in | ios::out| ios::binary); //2진수로 input,output 가능하게 파일 open
	for (int i = 1; i != 20; i++) //10번째까지 읽기
	{
		//rwFileStream.seekg((i - 1) *sizeof(int));
		rwFileStream.read((char *)&nNum, sizeof(int));
		cout << nNum << endl;
	}
	rwFileStream.seekp(13 * sizeof(int)); //13번째 값을 15로 바꾸기
	int nTemp = 15;
	rwFileStream.write((char*)&nTemp, sizeof(int));
	rwFileStream.seekg(13 *sizeof(int));
	rwFileStream.read((char *)&nNum, sizeof(int));
	cout << nNum << endl;
	rwFileStream.close();
	return 0;
}