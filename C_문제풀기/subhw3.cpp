/* 세 과목의 점수의 총점과 평균을 구해주는 프로그램 */
#pragma warning(disable : 4996)
#include <stdio.h>
void output(int,double);
int main()
{	
	double mean = 0.0;
	int sub1, sub2, sub3, sum = 0;
	
	printf("역사, 문학, 예능 점수를 입력하세요 :");
	scanf("%d", &sub1);
	scanf("%d", &sub2);
	scanf("%d", &sub3);
	sum = sub1 + sub2 + sub3;
	mean = (sub1 + sub2 + sub3) / 3.0;
	output(sum,mean);
	return 0;
}

void output(int s, double m)
{
	printf("총점은 %d이고 평균은 %lf입니다.\n", s, m);
}