#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define ESC 27
#pragma warning (disable : 4996)
int main()
{
	char ch;
	while(1){
		if(kbhit()){ //����ڰ� Ű����� �Է��ϸ� 1, �Է� ���ϸ� 0
			ch=getch(); //�ϵ���� �Է�buffer���� 1���� ������ ( stdin buffer�� ������� ���� )
			if(ch=='b'){
				printf("����������!!\n");
				Sleep(100);
			}
			else if(ch==ESC){
				break;
			}
		}
		printf("��������~\n");
		Sleep(100);
	}
	return 0;
}
