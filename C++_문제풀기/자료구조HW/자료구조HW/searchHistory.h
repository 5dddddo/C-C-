//searchHistory class ����
#include <iostream>
using namespace std;
#pragma once
class searchHistory
{
	// Characteristics:
	//
	// �˻� �����丮 class�� ��� �����δ� �˻���,��¥,������Ʈ,������ �ְ�
	// sort�� ���� ��� ����, �󵵼��� �����Ѵ�. 

public:
	searchHistory();
	searchHistory(searchHistory &s);
	searchHistory(string s, string d, string w, string i, int f);
	~searchHistory();
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
	int getFrequency();
	void setFrequency(int f);
	void addHistory(string s, string d, string w, string i, int f);
private:
	string website;
	string date;
	string information;
	string searchWord;
	int frequency;

};
