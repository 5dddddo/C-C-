#include "List.h"
#include <iostream>
using namespace std;

int main()
{
	int i;
	string searchWord[3] = { "���Ǵ�", "����", "������8" };
	List l, addL;
	ListElementType elem,
		addWord[2] = { { "������s8", "2016-01-23", "http://mutantcell.blog.me/220962579255", "�÷�", 19 },
		{"�Ϻ� ����ī ����" , "2017-05-04","http://m.post.naver.com/viewer/postView.nhn?volumeNo=5065503&memberNo=938657&vType=VERTICAL","����ī �����н� 2�ϱ�", 23}};
	ListElementType firstHistory[10] = { { "�޼��������� �Խ�", "2017-03-24", "http://blog.naver.com/guil_riahn?Redirect=Log&logNo=220879988821", "����", 14 },
	{ "������8", "2017-08-05", "http://wixtm.blog.me/220957731811", "���� ����", 8 },
	{ "����ȣ", "2014-04-16", "http://news.sbs.co.kr/news/endPage.do?news_id=N1004110461&plink=ORI&cooper=NAVER", "�ξ�", 3 },
	{ "����", "2016-11-23", "http://www.kukinews.com/news/article.html?no=441897", "�̼�����", 21 },
	{ "�ѱ� �౸", "2015-06-30", "http://www.sedaily.com/NewsView/1ODHUL1M3X", "�⼺��", 1 },
	{ "�Ｚ ��Ʈ��", "2013-08-05", "http://www.samsung.com/sec/notebook9_always/", "�����", 5 },
	{ "īī��������", "2015-02-16", "http://m.post.naver.com/viewer/postView.nhn?volumeNo=6101696&memberNo=15460571&vType=VERTICAL", "���̾�", 26 },
	{ "����", "2014-06-17", "http://comic.naver.com/webtoon/weekday.nhn", "�����ϱ�", 11 },
	{ "���Ǵ��б�", "2011-01-21", "http://oasis.ssu.ac.kr/index.ax", "�߾ӵ�����", 19 },
	{ "������s8", "2016-01-23", "http://mutantcell.blog.me/220962579255", "�÷�", 19 } },
		secondHistory[10] =
	{ { "5�� ��ü������", "2017-05-03", "http://news.chosun.com/site/data/html_dir/2017/01/10/2017011002336.html", "Ȳ�ݿ���", 27 },
	{ "��ī�� ȿ��", "2012 - 01 - 29", "http://blog.naver.com/husneaaqlsd/220949277191", "Ÿ�츰 �Է�", 6 },
	{ "�����-forever", "2018-06-19", "http://music.naver.com/lyric/index.nhn?trackId=6190924", "������ ���", 33 },
	{ "3.1��", "2013-03-01", "http://navercast.naver.com/list.nhn?cid=129&category_id=129", "�������", 15 },
	{ "2017�� ���� ��ȭ�ñ�", "2017-04-06", "http://blog.naver.com/2000happy_/220965461404", "��������", 2 },
	{ "ũ�������� ��ȭ", "2016-12-25", "http://blog.skylife.co.kr/220892616731", "Home Alone", 24 },
	{ "2002�� ���� ������ 4�� ����", "2002-08-12", "http://blog.naver.com/chiwoorin/220310831150", "������ ����", 18 },
	{ "insertion sort", "2011-07-13", "http://cafe.naver.com/bcbmaster/928", "�����ϴ� ���", 10 },
	{ "���鰡�� �뷡�Ұ��", "2017-03-26", "http://www.focus.kr/view.php?key=2017032600144150605", "�ٺ�ġ ���ظ�", 36 },
	{ "���ѵ��� 7�� ���", "2015-03-28", "http://osen.mt.co.kr/article/G1110605063", "������ Ư�� 4����", 7 } };

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

	////��Ȯ���� ���� �Ϻ� �������� ã�� (1 field : SearchWord)
	//for (i = 0; i < 3; i++)
	//{
	//	cout << "# ã�� ���� �˻��� �Է� : " << searchWord[i] << endl;
	//	if (l.find(elem, searchWord[i]))
	//		cout << elem;
	//	else
	//	{
	//		cout << "# �˻� ����" << endl;
	//		cout << "--------------------------------------------------------------------------------" << endl;
	//	}
	//}

	////�˻��� ����
	//cout << "\n	< �˻��� ���� >\n" << endl;
	//for (i = 0; i < 3; i++)
	//{
	//	cout << "# �����ϰ� ���� �˻��� �Է� : " << searchWord[i] << endl;
	//	if (l.deleteNode(searchWord[i]))
	//		cout << "# ���� �Ϸ�" << endl;
	//	else
	//		cout << "# ���� ����" << endl;
	//}

	//cout << "\n	< ���� �� list >\n" << endl;
	//while (notEmpty) {
	//	cout << elem << endl;
	//	notEmpty = l.next(elem);
	//}

	//// ���� �˻��� �˻�
	//l.AddSearch(addWord[0]);
	//// ���ο� �˻��� �˻�
	//l.AddSearch(addWord[1]);

	////�� list ����
	//l.AddAll(addL);
	//notEmpty = l.first(elem);
	//cout << "\n	< �� list�� ������ �� list >\n" << endl;
	//while (notEmpty) {
	//	cout << elem<< endl;
	//	notEmpty = l.next(elem);
	//}


	return 0;
}
