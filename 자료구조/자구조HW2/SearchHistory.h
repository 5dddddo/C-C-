#pragma once
#include <iostream>
using namespace std;
#include <string>
class CSearchHistory
{
public:
	CSearchHistory();
	~CSearchHistory();
	CSearchHistory(CSearchHistory &s);
	CSearchHistory(string s, string d, string w, string i, int f);
	// ��� ������ ���������ڰ� private�̹Ƿ�
	// �� ������� ���� �����ϱ� ���� set�Լ� ����,
	// ������� ���� �������� ���� get�Լ� ����
	string getWebsite() const;
	void setWebsite(string w);
	string getDate() const;
	void setDate(string d);
	string getInformation() const;
	void setInformation(string i);
	string getSearchword() const;
	void setSearchword(string s);
	int getFrequency() const;
	void setFrequency(int f);
	friend ostream& operator<<(ostream &output, CSearchHistory &history);
private:
	string website;
	string date;
	string information;
	string searchWord;
	int frequency;

};
