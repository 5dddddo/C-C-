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
	printf("# ���� �Է� : ");
	gets(cp);
	printf("# Ű �Է�(cm����) : ");
	scanf("%lf", dp);
	fflush(stdin);
	printf("# ���� �Է�(M/F) :");
	scanf("%c", gp);
}

void output(char *cp, double h, char g)
{
	char gender[10];
	if (g == 'F' || g == 'f')
	{
		strcpy(gender, "����");
	}
	else if (g == 'M' || g == 'm')
	{
		strcpy(gender, "����");
	}
	printf("%s�� Ű�� %.2lfcm�̰� %s�Դϴ�.\n", cp, h, gender);
}