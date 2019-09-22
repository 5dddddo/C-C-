#pragma once
#include "SearchHistory.h"
CSearchHistory::CSearchHistory()
	:frequency(0)
{
}
CSearchHistory::~CSearchHistory()
{
}
CSearchHistory::CSearchHistory(CSearchHistory &s)
{
	searchWord = s.searchWord;
	date = s.date;
	website = s.website;
	information = s.information;
	frequency = s.frequency;
}
CSearchHistory::CSearchHistory(string s, string d, string w, string i, int f)
	: searchWord(s), date(d), website(w), information(i), frequency(f)
{}
string CSearchHistory::getWebsite() const
{
	return website;
}
void CSearchHistory::setWebsite(string w)
{
	website = w;
}
string CSearchHistory::getDate() const
{
	return date;
}
void CSearchHistory::setDate(string d)
{
	date = d;
}
string CSearchHistory::getInformation() const
{
	return information;
}
void CSearchHistory::setInformation(string i)
{
	information = i;
}
string CSearchHistory::getSearchword() const
{
	return searchWord;
}
void CSearchHistory::setSearchword(string s)
{
	searchWord = s;
}
int CSearchHistory::getFrequency() const
{
	return frequency;
}
void CSearchHistory::setFrequency(int f)
{
	frequency = f;
}
ostream& operator<<(ostream &output, CSearchHistory &history)
{
	output << "SearchWord : " << history.getSearchword() << "\nFrequency : " << history.getFrequency()
		<< "\nDate : " << history.getDate() << "\nWebsite : " << history.getWebsite()
		<< "\nInformation : " << history.getInformation() << endl;
	output << "--------------------------------------------------------------------------------" << endl;
	return output;
}