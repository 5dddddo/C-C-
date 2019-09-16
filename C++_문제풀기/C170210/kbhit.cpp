#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define ESC 27
#pragma warning (disable : 4996)
int main()
{
	char ch;
	while(1){
		if(kbhit()){ //사용자가 키보드로 입력하면 1, 입력 안하면 0
			ch=getch(); //하드웨어 입력buffer에서 1글자 가져옴 ( stdin buffer는 사용하지 않음 )
			if(ch=='b'){
				printf("쉬었다하자!!\n");
				Sleep(100);
			}
			else if(ch==ESC){
				break;
			}
		}
		printf("공부하자~\n");
		Sleep(100);
	}
	return 0;
}
