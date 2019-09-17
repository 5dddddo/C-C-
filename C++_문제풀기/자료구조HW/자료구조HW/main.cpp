#include "func.h"
int sortCnt = 0;
int main()
{
	int i, j, tmp, searchRes;
	string searchWord[3] = { "���Ǵ�", "����", "������8" };
	string searchDate[3] = { "2016", "2014-06", "2016" }, searchInfo[3] = { "�̼�", "����", "���ѵ���" };
	searchHistory *firstHistory[10], *secondHistory[10], *res;

	//searchHistory�� 10�� �߰�
	initHistoryList(firstHistory, secondHistory);
	cout << "\n	< Search History first List >\n" << endl;
	display(firstHistory);
	cout << "\n	< Search History second List >\n" << endl;
	display(secondHistory);

	//��Ȯ���� ���� �Ϻ� �������� ã�� (1 field : SearchWord)
	cout << "\n	< ��Ȯ���� ���� �Ϻ� �������� ã�� (1 field : SearchWord) >\n" << endl;
	for (i = 0; i < 3; i++)
	{
		cout << "# ã�� ���� �˻��� �Է� : " << searchWord[i] << endl;
		searchRes = searchOneField(firstHistory, searchWord[i]); //��Ȯ���� ���� �������� ã�� �Լ�
		if (searchRes == -1)
		{
			cout << "# �˻� ����" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
		}
		else
		{
			tmp = firstHistory[searchRes]->getFrequency() + 1;
			firstHistory[searchRes]->setFrequency(tmp);
			display(firstHistory[searchRes]);
		}
	}

	//��Ȯ���� ���� �Ϻ� �������� ã�� (2 field : SearchWord)
	cout << "\n	< ��Ȯ���� ���� �Ϻ� �������� ã�� (2 field : Information & Date) >\n" << endl;
	for (i = 0; i < 3; i++)
	{
		cout << "# ã�� ���� ��¥ : " << searchDate[i] << " ���� : " << searchInfo[i] << endl;
		res = searchTwoField(firstHistory, searchDate[i], searchInfo[i]); //��Ȯ���� ���� �������� ã�� �Լ�
		if (res == NULL)
		{
			cout << "# �˻� ����" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
		}
		else
			display(res);
	}

	//�˻��� ����
	tmp = 0;
	cout << "\n	< �˻��� ���� >\n" << endl;
	for (i = 0; i < 3; i++)
	{
		cout << "# �����ϰ� ���� �˻��� �Է� : " << searchWord[i] << endl;
		searchRes = searchOneField(firstHistory, searchWord[i]);
		if (searchRes == -1)
			cout << "# ���� ����" << endl;
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
			cout << "# ���� �Ϸ�" << endl;
		}
	}
	cout << "\n	< ���� �� Search History firstList >\n" << endl;
	display(firstHistory);

	//�˻� �����丮 �ʱ�ȭ
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
	
	//�˻� �����丮 �ʱ�ȭ
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

	cout << " 5. �������� �������� ����ü search history ũ�Ⱑ �󸶰� �Ǿ�� quick sort�� �� ���� �ϰ� �ǳ�? " << endl;
	cout << " => A(n) ��� ���, �뷫������ 28~29������ Quick sort�� ����" << endl;

	deleteHistoryList(firstHistory, secondHistory);
	return 0;
}
