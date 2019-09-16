#pragma warning (disable : 4996)
#include <stdio.h>
int main()
{
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	char str[100];
	while (getchar() != EOF)
	{
		printf("문장을 입력하세요 : ");
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
	printf("* 영문자대소문자 : %d개\n", c1);
	printf("* 숫자문자 : %d개\n", c2);
	printf("* 여백문자(space,tab,enter) : %d개\n", c3);
	printf("* 그외 기타문자 : %d개\n", c4);

}