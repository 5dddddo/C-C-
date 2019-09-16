#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
void input(char *,double *,char *);
void output(char *,double,char);

int main()
{
	char name[20] = "Edf";
	double height = 23.1;
	char gender = 'W';

	input(name, &height, &gender);
	output(name, height, gender);
	return 0;
}

void input(char *cp, double *dp, char *gp)
{
	printf("# 성명 입력 : ");
	gets(cp);
	printf("# 키 입력(cm단위) : ");
	scanf("%lf", dp);
	fflush(stdin);
	printf("# 성별 입력(M/F) :");
	scanf("%c", gp);
}

void output(char *cp, double h, char g)
{
	char gender[10];
	if (g == 'F' || g == 'f')
	{
		strcpy(gender, "여성");
	}
	else if (g == 'M' || g == 'm')
	{
		strcpy(gender, "남성");
	}
	printf("%s의 키는 %.2lfcm이고 %s입니다.\n", cp, h, gender);
}