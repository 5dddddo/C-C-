#pragma warning (disable : 4996)
#include <stdio.h>
int main()
{
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	char str[100];
	while (getchar() != EOF)
	{
		printf("������ �Է��ϼ��� : ");
		scanf("%s", str);
		if (getchar() >= 'A' && getchar() <= 'Z')
		{
			c1++;
		}
		else if (getchar() >= 'a' && getchar() <= 'z')
		{
			c2++;
		}
		else if (getchar() == ' ' || getchar() == '\n' || getchar() == '\t')
		{
			c3++;
		}
		else
		{
			c4++;
		}
	}
	printf("* �����ڴ�ҹ��� : %d��\n", c1);
	printf("* ���ڹ��� : %d��\n", c2);
	printf("* ���鹮��(space,tab,enter) : %d��\n", c3);
	printf("* �׿� ��Ÿ���� : %d��\n", c4);

}