#include "SearchHistory.h"
searchHistory::searchHistory()
{}

searchHistory::searchHistory(searchHistory &s)
{
	searchWord = s.searchWord;
	date = s.date;
	website = s.website;
	information = s.information;
	frequency = s.frequency;
}
searchHistory::searchHistory(string s, string d, string w, string i, int f)
: searchWord(s), date(d), website(w), information(i), frequency(f)
{}
searchHistory::~searchHistory()
{}
string searchHistory::getWebsite() const
{
	return website;
}
void searchHistory::setWebsite(string w)
{
	website = w;
}
string searchHistory::getDate() const
{
	return date;
}
void searchHistory::setDate(string d)
{
	date = d;
}
string searchHistory::getInformation() const
{
	return information;
}
void searchHistory::setInformation(string i)
{
	information = i;
}
string searchHistory::getSearchword() const
{
	return searchWord;
}
void searchHistory::setSearchword(string s)
{
	searchWord = s;
}
int searchHistory::getFrequency()
{
	return frequency;
}
void searchHistory::setFrequency(int f)
{
	frequency = f;
}

void searchHistory::addHistory(string s, string d, string w, string i, int f)
{
	searchWord = s;
	date = d;
	website = w;
	information = i;
	frequency = f;
}
