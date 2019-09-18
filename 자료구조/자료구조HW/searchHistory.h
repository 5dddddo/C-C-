//searchHistory class 정의
#include <iostream>
using namespace std;
#pragma once
class searchHistory
{
	// Characteristics:
	//
	// 검색 히스토리 class의 멤버 변수로는 검색어,날짜,웹사이트,정보가 있고
	// sort를 위한 멤버 변수, 빈도수도 포함한다. 

public:
	searchHistory();
	searchHistory(searchHistory &s);
	searchHistory(string s, string d, string w, string i, int f);
	~searchHistory();
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
