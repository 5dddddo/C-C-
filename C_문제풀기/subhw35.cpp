#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <conio.h>
#pragma warning(disable: 4996)
int myMenu(char **, int);
void input(int *cnt);
void inputScore(char **sublist, int cnt, int **subcnt, char **name); 
void Modify(char **name, int **subcnt, char **sublist, int cnt);
int* calTotal(int **subcnt, int cnt);
int** makeScore (int cnt);
void output(int *total, int **subcnt, char **name, char **sublist, int cnt);
char **makeName(char **sublist, int cnt);
 int main()
 {	 
	 char *mlist[] = { "1. ���� �Է��ϱ�", "2. ���� �����ϱ�", "3. ���� ����ϱ�", "4. ����" };
	 int num, size = sizeof(mlist) / sizeof(mlist[0]), cnt;
	 int **subcnt = 0;
	 char *sublist[] = { "���� ����", "���� ����", "���� ����" };
	 char **name = { 0 };
	 int *total = 0;
	 input(&cnt);
	 while (1)
	 {
		 num = myMenu(mlist, size);
		 switch (num)
		 {
		 case 1:
			 subcnt = makeScore (cnt);
			 name = makeName(sublist, cnt);
			 inputScore(sublist, cnt, subcnt, name);
			 break;
		 case 2:
			 if (name == NULL)
			 {
				 printf("���� �ڷḦ �Է��ϼ���.\n");
				 getch();
				 system("cls");
				 break;
			 }
			 else
			 {
				 Modify(name, subcnt, sublist, cnt);
				 break;
			 }
			 break;
		 case 3:
			 if (name == NULL)
			 {
				 printf("���� �ڷḦ �Է��ϼ���.\n");
				 getch();
				 system("cls");
				 break;
			 }
			 else
			 {
				 total = calTotal(subcnt, cnt);
				 output(total, subcnt, name, sublist, cnt);
				 break;
			 }
			 break;
		 case 4:
			 exit(0);
			 break;
		 }
	 }
	 return 0;
 }

 int myMenu(char **mlist, int size)
 {
	 int i, num;
	 for (i = 0; i < size; i++)
	 {
		 printf("%s\n", mlist[i]);
	 }
	 printf("\n");
	 while (1)
	 {
		 printf("# �޴����� : ");
		 if (scanf("%d", &num) == 1)
		 {
			 if (getchar() == '\n')
			 {
				 if (num > 0 && num <= 4)
				 {
					 break;
				 }
			 }
			 fflush(stdin);
		 }
	 }
	 return num;
 }
 
 void input(int *cnt)
 {
	 printf("�л� ���� �Է��ϼ��� : ");
	 scanf("%d", cnt);
	 system("cls");
 }
 
 char** makeName(char **sublist, int cnt)
 {
	 int i, len;
	 char **name, temp[1000];
	 system("cls");
	 name = (char **)malloc(sizeof(char *)*cnt);
	 assert(name != NULL);

	 for (i = 0; i < cnt; i++)
	 {
		 printf("%d��° �л��� �̸� : ", i + 1);
		 scanf("%s", temp);
		 len = strlen(temp) + 1;
		 name[i] = (char *)malloc(sizeof(char)*(len + 1));
		 assert(name[i] != NULL);
		 strcpy(name[i], temp);
	 }
	 system("cls");
	 return name;
 }
 
 int** makeScore (int cnt)
 {
	 int i, **score ;

	 score  = (int **)malloc(sizeof(int *)*cnt);
	 assert(score  != NULL);
	 for (i = 0; i < cnt; i++)
	 {
		 score [i] = (int *)malloc(sizeof(int) * 3);
		 assert(score [i] != NULL);
	 }
	 return score ;
 }
 
 void inputScore(char **sublist, int cnt, int **subcnt, char **name)
 {
	 int i, j, score;
	 system("cls");
	 for (i = 0; i < cnt; i++)
	 {
		 printf("%s�л� �����Է�\n", name[i]);
		 for (j = 0; j < 3; j++)
		 {
			 while (1)
			 {
				 printf("%s : ", sublist[j]);
				 scanf("%d", &score);
				 if (getchar() == '\n')
				 {
					 if (score >= 0) 
					 {
						 subcnt[i][j] = score;
						 break;
					 }
				 }
				 fflush(stdin);
			 }
		 }
		 printf("\n");
	 }
	 system("cls");
	 return;
 }
 
 void Modify(char **name, int **subcnt, char **sublist, int cnt)
 {
	 int i, findnum, modnum;
	 char temp[100];

	 system("cls");
	 while (1)
	 {
		 printf("������ �л��� �̸��� �Է� : ");
		 scanf("%s", temp);
		 if (strcmp(temp, "end") == 0)
		 {
			 printf("\n");
			 system("cls");
			 break;
		 }
		 for (i = 0; i < cnt; i++)
		 {
			 if (strcmp(name[i], temp) == 0)
			 {
				 findnum = i;
				 break;
			 }
		 }
		 printf("������ ������ �Է��ϼ���.\n");
		 for (i = 0; i < 3; i++)
		 {
			 printf("%s :", sublist[i]);
			 scanf("%d", &modnum);
			 subcnt[findnum][i] = modnum;
		 }
	 }
	 return;
 }
 
 int* calTotal(int **subcnt, int cnt)
 {
	 int *tot, i, j, sum;
	 tot = (int *)malloc(sizeof(int)*cnt);
	 for (i = 0; i < cnt; i++)
	 {
		 sum = 0;
		 for (j = 0; j < 3; j++)
		 {
			 sum += subcnt[i][j];
		 }
		 tot[i] = sum;
		 printf("%d\n", tot[i]);
	 }
	 return tot;
 }
 
 void output(int *total, int **subcnt, char **name, char **sublist, int cnt)
 {
	 int i, j, temp, *temp1;
	 char *temp2;
	 system("cls");
	 for (i = 0; i < cnt - 1; i++)
	 {
		 for (j = i + 1; j < cnt; j++)
		 {
			 if (total[i] < total[j])
			 {
				 temp = total[i];
				 total[i] = total[j];
				 total[j] = temp;
				 temp1 = subcnt[i];
				 subcnt[i] = subcnt[j];
				 subcnt[j] = temp1; 
				 temp2 = name[i];
				 name[i] = name[j];
				 name[j] = temp2;
			 }
		 }
	 }
	 for (i = 0; i < cnt; i++)
	 {
		 printf("%s\n%s: %d�� %s: %d�� %s: %d�� ���� : %d�� ��� :%.2lf��\n\n", name[i], sublist[0], subcnt[i][0], sublist[1], subcnt[i][1], sublist[2], subcnt[i][2], total[i], total[i] / 3.0);
	 }
	 getch();
	 system("cls");
 }
