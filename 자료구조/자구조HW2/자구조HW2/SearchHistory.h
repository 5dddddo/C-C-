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
	// 멤버 변수의 범위지정자가 private이므로
	// 각 멤버변수 값을 변경하기 위한 set함수 선언,
	// 멤버변수 값을 가져오기 위한 get함수 선언
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
