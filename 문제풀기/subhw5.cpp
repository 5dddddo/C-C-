/* cm단위를 입력받아 M단위와 cm단위로 환산하는 프로그램 */
#pragma warning(disable : 4996)
#include <stdio.h>
int input(int); 
void output(int);

int main()
{
	int height = 0;
	height = input(height);
	output(height);
	return 0;
}

int input(int h)
{
	printf("cm단위로 입력하세요 :");
	scanf("%d", &h);
	return h;
}

void output(int h)
{
	int m, c = 0;
	m = h / 100;
	c = h - m * 100;
	printf("%dcm => %dM %dcm\n", h, m, c);
}