#include "List.h"
#include <iostream>
using namespace std;

int main()
{
	int i;
	string searchWord[3] = { "숭실대", "벚꽃", "아이폰8" };
	List l, addL;
	ListElementType elem,
		addWord[2] = { { "갤럭시s8", "2016-01-23", "http://mutantcell.blog.me/220962579255", "컬러", 19 },
		{"일본 오사카 여행" , "2017-05-04","http://m.post.naver.com/viewer/postView.nhn?volumeNo=5065503&memberNo=938657&vType=VERTICAL","오사카 주유패스 2일권", 23}};
	ListElementType firstHistory[10] = { { "메세나폴리스 롯시", "2017-03-24", "http://blog.naver.com/guil_riahn?Redirect=Log&logNo=220879988821", "팝콘", 14 },
	{ "아이폰8", "2017-08-05", "http://wixtm.blog.me/220957731811", "무선 충전", 8 },
	{ "세월호", "2014-04-16", "http://news.sbs.co.kr/news/endPage.do?news_id=N1004110461&plink=ORI&cooper=NAVER", "인양", 3 },
	{ "날씨", "2016-11-23", "http://www.kukinews.com/news/article.html?no=441897", "미세먼지", 21 },
	{ "한국 축구", "2015-06-30", "http://www.sedaily.com/NewsView/1ODHUL1M3X", "기성용", 1 },
	{ "삼성 노트북", "2013-08-05", "http://www.samsung.com/sec/notebook9_always/", "스토어", 5 },
	{ "카카오프렌즈", "2015-02-16", "http://m.post.naver.com/viewer/postView.nhn?volumeNo=6101696&memberNo=15460571&vType=VERTICAL", "라이언", 26 },
	{ "웹툰", "2014-06-17", "http://comic.naver.com/webtoon/weekday.nhn", "대학일기", 11 },
	{ "숭실대학교", "2011-01-21", "http://oasis.ssu.ac.kr/index.ax", "중앙도서관", 19 },
	{ "갤럭시s8", "2016-01-23", "http://mutantcell.blog.me/220962579255", "컬러", 19 } },
		secondHistory[10] =
	{ { "5월 대체공휴일", "2017-05-03", "http://news.chosun.com/site/data/html_dir/2017/01/10/2017011002336.html", "황금연휴", 27 },
	{ "박카스 효능", "2012 - 01 - 29", "http://blog.naver.com/husneaaqlsd/220949277191", "타우린 함량", 6 },
	{ "비와이-forever", "2018-06-19", "http://music.naver.com/lyric/index.nhn?trackId=6190924", "영원히 비와", 33 },
	{ "3.1절", "2013-03-01", "http://navercast.naver.com/list.nhn?cid=129&category_id=129", "독립운동가", 15 },
	{ "2017년 벚꽃 개화시기", "2017-04-06", "http://blog.naver.com/2000happy_/220965461404", "벚꽃축제", 2 },
	{ "크리스마스 영화", "2016-12-25", "http://blog.skylife.co.kr/220892616731", "Home Alone", 24 },
	{ "2002년 한일 월드컵 4강 진출", "2002-08-12", "http://blog.naver.com/chiwoorin/220310831150", "박지성 선수", 18 },
	{ "insertion sort", "2011-07-13", "http://cafe.naver.com/bcbmaster/928", "삽입하는 방식", 10 },
	{ "복면가왕 노래할고양", "2017-03-26", "http://www.focus.kr/view.php?key=2017032600144150605", "다비치 이해리", 36 },
	{ "무한도전 7주 결방", "2015-03-28", "http://osen.mt.co.kr/article/G1110605063", "레전드 특집 4부작", 7 } };

	for (i = 0; i < 10; i++)
	{
		l.insert(firstHistory[i]);
		addL.insert(secondHistory[i]);
	}
	cout << "Here are the firstHistory in the list.\n";

	bool notEmpty(l.first(elem));

	//while (notEmpty) {
	//	cout << elem << endl;
	//	notEmpty = l.next(elem);
	//}
	//if (l.last(elem))
	//	cout << elem << endl;

	////정확하지 않은 일부 내용으로 찾기 (1 field : SearchWord)
	//for (i = 0; i < 3; i++)
	//{
	//	cout << "# 찾고 싶은 검색어 입력 : " << searchWord[i] << endl;
	//	if (l.find(elem, searchWord[i]))
	//		cout << elem;
	//	else
	//	{
	//		cout << "# 검색 실패" << endl;
	//		cout << "--------------------------------------------------------------------------------" << endl;
	//	}
	//}

	////검색어 삭제
	//cout << "\n	< 검색어 삭제 >\n" << endl;
	//for (i = 0; i < 3; i++)
	//{
	//	cout << "# 삭제하고 싶은 검색어 입력 : " << searchWord[i] << endl;
	//	if (l.deleteNode(searchWord[i]))
	//		cout << "# 삭제 완료" << endl;
	//	else
	//		cout << "# 삭제 실패" << endl;
	//}

	//cout << "\n	< 삭제 후 list >\n" << endl;
	//while (notEmpty) {
	//	cout << elem << endl;
	//	notEmpty = l.next(elem);
	//}

	//// 기존 검색어 검색
	//l.AddSearch(addWord[0]);
	//// 새로운 검색어 검색
	//l.AddSearch(addWord[1]);

	////두 list 연결
	//l.AddAll(addL);
	//notEmpty = l.first(elem);
	//cout << "\n	< 두 list를 연결한 후 list >\n" << endl;
	//while (notEmpty) {
	//	cout << elem<< endl;
	//	notEmpty = l.next(elem);
	//}


	return 0;
}
