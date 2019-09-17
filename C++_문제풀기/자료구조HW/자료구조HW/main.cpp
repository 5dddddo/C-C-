#include "func.h"
int sortCnt = 0;
int main()
{
	int i, j, tmp, searchRes;
	string searchWord[3] = { "숭실대", "벚꽃", "아이폰8" };
	string searchDate[3] = { "2016", "2014-06", "2016" }, searchInfo[3] = { "미세", "대학", "무한도전" };
	searchHistory *firstHistory[10], *secondHistory[10], *res;

	//searchHistory에 10개 추가
	initHistoryList(firstHistory, secondHistory);
	cout << "\n	< Search History first List >\n" << endl;
	display(firstHistory);
	cout << "\n	< Search History second List >\n" << endl;
	display(secondHistory);

	//정확하지 않은 일부 내용으로 찾기 (1 field : SearchWord)
	cout << "\n	< 정확하지 않은 일부 내용으로 찾기 (1 field : SearchWord) >\n" << endl;
	for (i = 0; i < 3; i++)
	{
		cout << "# 찾고 싶은 검색어 입력 : " << searchWord[i] << endl;
		searchRes = searchOneField(firstHistory, searchWord[i]); //정확하지 않은 내용으로 찾는 함수
		if (searchRes == -1)
		{
			cout << "# 검색 실패" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
		}
		else
		{
			tmp = firstHistory[searchRes]->getFrequency() + 1;
			firstHistory[searchRes]->setFrequency(tmp);
			display(firstHistory[searchRes]);
		}
	}

	//정확하지 않은 일부 내용으로 찾기 (2 field : SearchWord)
	cout << "\n	< 정확하지 않은 일부 내용으로 찾기 (2 field : Information & Date) >\n" << endl;
	for (i = 0; i < 3; i++)
	{
		cout << "# 찾고 싶은 날짜 : " << searchDate[i] << " 정보 : " << searchInfo[i] << endl;
		res = searchTwoField(firstHistory, searchDate[i], searchInfo[i]); //정확하지 않은 내용으로 찾는 함수
		if (res == NULL)
		{
			cout << "# 검색 실패" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
		}
		else
			display(res);
	}

	//검색어 삭제
	tmp = 0;
	cout << "\n	< 검색어 삭제 >\n" << endl;
	for (i = 0; i < 3; i++)
	{
		cout << "# 삭제하고 싶은 검색어 입력 : " << searchWord[i] << endl;
		searchRes = searchOneField(firstHistory, searchWord[i]);
		if (searchRes == -1)
			cout << "# 삭제 실패" << endl;
		else
		{
			tmp++;
			delete firstHistory[searchRes];
			for (j = searchRes; j < 10 - tmp; j++)
			{
				if (j != 9 - tmp)
					firstHistory[j] = firstHistory[j + 1];
				else firstHistory[j] = NULL;
			}
			cout << "# 삭제 완료" << endl;
		}
	}
	cout << "\n	< 삭제 후 Search History firstList >\n" << endl;
	display(firstHistory);

	//검색 히스토리 초기화
	deleteHistoryList(firstHistory, secondHistory);
	initHistoryList(firstHistory, secondHistory);

	//Insertion Sort
	cout << "\n	< Insertion Sort - FirstHistory >\n" << endl;
	insertionSort(firstHistory);
	display(firstHistory);
	cout << "\n	< Insertion Sort - FirstHistory result = " << sortCnt << " >\n" << endl;

	cout << "\n	< Insertion Sort - SecondHistory >\n" << endl;
	sortCnt = 0;
	insertionSort(secondHistory);
	display(secondHistory);
	cout << "\n	< Insertion Sort - SecondHistory result = " << sortCnt << " >\n" << endl;
	
	//검색 히스토리 초기화
	deleteHistoryList(firstHistory, secondHistory);
	initHistoryList(firstHistory, secondHistory);

	//Quick Sort
	cout << "\n	< Quick Sort - FirstHistory >\n" << endl;
	sortCnt = 0;
	quicksort(firstHistory, 0, 9);
	display(firstHistory);
	cout << "\n	< Quick Sort - FirstHistory result = " << sortCnt << " >\n" << endl;

	cout << "\n	< Quick Sort - SecondHistory >\n" << endl;
	sortCnt = 0;
	quicksort(secondHistory, 0, 9);
	display(secondHistory);
	cout << "\n	< Quick Sort - SecondHistory result = " << sortCnt << " >\n" << endl;

	cout << " 5. 여러분의 구현에서 도대체 search history 크기가 얼마가 되어야 quick sort가 더 유리 하게 되나? " << endl;
	cout << " => A(n) 계산 결과, 대략적으로 28~29개부터 Quick sort가 유리" << endl;

	deleteHistoryList(firstHistory, secondHistory);
	return 0;
}
