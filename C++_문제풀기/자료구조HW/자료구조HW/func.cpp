#pragma once
#include "func.h"
extern int sortCnt;
void initHistoryList(searchHistory **firstHistory, searchHistory **secondHistory)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		firstHistory[i] = new searchHistory;
		secondHistory[i] = new searchHistory;
	}
	firstHistory[0]->addHistory("메세나폴리스 롯시", "2017-03-24", "http://blog.naver.com/guil_riahn?Redirect=Log&logNo=220879988821", "팝콘", 14);
	firstHistory[1]->addHistory("아이폰8", "2017-08-05", "http://wixtm.blog.me/220957731811", "무선 충전", 8);
	firstHistory[2]->addHistory("세월호", "2014-04-16", "http://news.sbs.co.kr/news/endPage.do?news_id=N1004110461&plink=ORI&cooper=NAVER", "인양", 3);
	firstHistory[3]->addHistory("날씨", "2016-11-23", "http://www.kukinews.com/news/article.html?no=441897", "미세먼지", 21);
	firstHistory[4]->addHistory("한국 축구", "2015-06-30", "http://www.sedaily.com/NewsView/1ODHUL1M3X", "기성용", 1);
	firstHistory[5]->addHistory("삼성 노트북", "2013-08-05", "http://www.samsung.com/sec/notebook9_always/", "스토어", 5);
	firstHistory[6]->addHistory("카카오프렌즈", "2015-02-16", "http://m.post.naver.com/viewer/postView.nhn?volumeNo=6101696&memberNo=15460571&vType=VERTICAL", "라이언", 26);
	firstHistory[7]->addHistory("웹툰", "2014-06-17", "http://comic.naver.com/webtoon/weekday.nhn", "대학일기", 11);
	firstHistory[8]->addHistory("숭실대학교", "2011-01-21", "http://oasis.ssu.ac.kr/index.ax", "중앙도서관", 19);
	firstHistory[9]->addHistory("갤럭시s8", "2016-01-23", "http://mutantcell.blog.me/220962579255", "컬러", 17);

	secondHistory[0]->addHistory("5월 대체공휴일", "2017-05-03", "http://news.chosun.com/site/data/html_dir/2017/01/10/2017011002336.html", "황금연휴", 27);
	secondHistory[1]->addHistory("박카스 효능", "2012-01-29", "http://blog.naver.com/husneaaqlsd/220949277191", "타우린 함량", 6);
	secondHistory[2]->addHistory("비와이-forever", "2018-06-19", "http://music.naver.com/lyric/index.nhn?trackId=6190924", "영원히 비와", 33);
	secondHistory[3]->addHistory("3.1절", "2013-03-01", "http://navercast.naver.com/list.nhn?cid=129&category_id=129", "독립운동가", 15);
	secondHistory[4]->addHistory("2017년 벚꽃 개화시기", "2017-04-06", "http://blog.naver.com/2000happy_/220965461404", "벚꽃축제", 2);
	secondHistory[5]->addHistory("크리스마스 영화", "2016-12-25", "http://blog.skylife.co.kr/220892616731", "Home Alone", 24);
	secondHistory[6]->addHistory("2002년 한일 월드컵 4강 진출", "2002-08-12", "http://blog.naver.com/chiwoorin/220310831150", "박지성 선수", 18);
	secondHistory[7]->addHistory("insertion sort", "2011-07-13", "http://cafe.naver.com/bcbmaster/928", "삽입하는 방식", 10);
	secondHistory[8]->addHistory("복면가왕 노래할고양", "2017-03-26", "http://www.focus.kr/view.php?key=2017032600144150605", "다비치 이해리", 36);
	secondHistory[9]->addHistory("무한도전 7주 결방", "2015-03-28", "http://osen.mt.co.kr/article/G1110605063", "레전드 특집 4부작", 7);
}

void deleteHistoryList(searchHistory **firstHistory, searchHistory **secondHistory)
{
	for (int i = 0; i < 10; i++)
	{
		if (firstHistory[i] != NULL)
			delete firstHistory[i];
		delete secondHistory[i];
	}
}
void display(searchHistory *sp)
{
	cout << "SearchWord : " << sp->getSearchword() << "\nFrequency : " << sp->getFrequency()
		<< "\nDate : " << sp->getDate() << "\nWebsite : " << sp->getWebsite()
		<< "\nInformation : " << sp->getInformation() << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
}
void display(searchHistory **sp)
{
	for (int i = 0; i < 10; i++)
	{
		if (sp[i] != NULL)
		{
			cout << "SearchWord : " << sp[i]->getSearchword() << "\nFrequency : " << sp[i]->getFrequency()
				<< "\nDate : " << sp[i]->getDate() << "\nWebsite : " << sp[i]->getWebsite()
				<< "\nInformation : " << sp[i]->getInformation() << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
		}
	}
}
int searchOneField(searchHistory **sp, string newData)
{
	for (int i = 0; i < 10; i++)
	{
		if (sp[i] != NULL)
		{
			if (sp[i]->getSearchword().find(newData) != string::npos)
				return i;
		}
	}
	return -1;
}
searchHistory* searchTwoField(searchHistory **sp, string newDate, string newInfo)
{
	searchHistory *tmp[10], res;
	int i, cnt = 0;
	for (i = 0; i < 10; i++)
	{
		if (sp[i]->getDate().find(newDate) != string::npos)
		{
			tmp[cnt] = new searchHistory;
			*tmp[cnt] = *sp[i];
			cnt++;
		}
	}
	for (i = 0; i < cnt; i++)
	{
		if (tmp[i]->getInformation().find(newInfo) != string::npos)
			return tmp[i];
	}
	return NULL;
}
void insertNextItem(searchHistory **sp, int i)
{
	// Precondition: array a is sorted from 0 to i-11	
	searchHistory * newItem(sp[i]);	sortCnt++;
	int insertPos(i); sortCnt++;
	searchHistory *tmp;
	for (; insertPos && newItem->getFrequency() > sp[insertPos - 1]->getFrequency(); insertPos--)
		// Loop Invariant: newItem <= a[insertPos+1] .. a[i] &&
	{	//                  a[insertPos+1] .. a[i] are sorted
		sp[insertPos] = sp[insertPos - 1]; sortCnt++;
	}
	sp[insertPos] = newItem; sortCnt++;
	// Postcondition: array a is sorted from 0 to i
}
void insertionSort(searchHistory **sp, int n)
{
	// Precondition: a is an array with subscripts ranging from 0 to n-1
	int i;
	for (i = 1; i < n; i++)
	{	// Loop invariant: items in range from 0 to i-1 are sorted; 
		//      items from i to n-1 have not yet been examined.
		insertNextItem(sp, i); // see cx3-6.cpp
		// Postcondition: array a is sorted
		sortCnt++;
	}
}
void quicksort(searchHistory **sp, int first, int last)
{
	// precondition: a is an array; 
	//    The portion to be sorted runs from index first to index last inclusive.
	if (first >= last) // Base Case -- nothing to sort, so just return
	{
	//	sortCnt++;
		return;
	}
	// Otherwise, we’re in the recursive case.
	// The partition function uses the item in a[first] as the pivot
	// and returns the position of the pivot -- split -- after the partition.
	int split(partition(sp, first, last));  sortCnt++;

	// Recursively, sort the two partitions.
	quicksort(sp, first, split - 1);
	quicksort(sp, split + 1, last);
	// postcondition: a is sorted in ascending order 
	// between first and last inclusive.
}
void swapElements(searchHistory **sp, int first, int last)
{
	searchHistory *tmp;
	tmp = sp[first];  sortCnt++;
	sp[first] = sp[last]; sortCnt++;
	sp[last] = tmp; sortCnt++;
}
int partition(searchHistory **sp, int first, int last)
{
	int lastSmall(first), i; sortCnt++;

	for (i = first + 1; i <= last; i++)
	{	// loop invariant: a[first+1]...a[lastSmall] <= a[first] &&
		//    a[lastSmall+1]...a[i-1] > a[first]
		sortCnt++;
		if (sp[i]->getFrequency() >= sp[first]->getFrequency())
		{ // key comparison
			++lastSmall; sortCnt++;
			swapElements(sp, lastSmall, i);
		}
	}
	swapElements(sp, first, lastSmall); // put pivot into correct position
	// postcondition: a[first]...a[lastSmall-1] <= a[lastSmall] &&
	//    a[lastSmall+1]...a[last] > a[lastSmall]
	return lastSmall; // this is the final position of the pivot -- the split index
}
