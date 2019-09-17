﻿#include<stdio.h>
#include "graph.h"
#include "datatype.h"
void displayTitle(char *message);

int main()
{
	GraphMatrix gm;
	int compCount; /* 그래프 내의 연결 요소의 개수 저장 변수 */
	GraphList gl;
	initGraph(&gm, "c:\\data\\graphData1.txt");/* 그래프 초기화 */
	outputGraph(&gm);   /* 그래프 상태 출력*/        
	
	displayTitle("DFS 방문(비재귀판)");
	nrDFS_Matrix(&gm);
	
	displayTitle("DFS 방문(재귀판)");
	DFS_Matrix(&gm);

	displayTitle("BFS 방문");
	BFS_Matrix(&gm);

	displayTitle("그래프 내의 연결 요소 보기");
	compCount = countGraphComponents(&gm);
	printf("\n그래프 내의 총 연결 요소의 개수 : %d개\n\n", compCount);
	
	
	initGraph_List(&gl, "c:\\data\\graphData1.txt");
	outputGraph_List(&gl);  
	destroyGraph_List(&gl);
	return 0;
}

void displayTitle(char *message)
{
	printf("\n----------------------------------------\n");
	printf("\t %s\n", message);
	printf("----------------------------------------\n");
}
//-------------------------------------
//   int type 보조 함수
//-------------------------------------
/*--------------------------------------------------------------------------------------
  함수명 및 기능: printInt() – 전달인자로 넘겨진 int값을 정해진 format으로 출력 함
  전달인자: p - 출력할 정수의 주소
  리턴값: 없음
--------------------------------------------------------------------------------------*/
void printInt(DataType *p)
{
	printf("%4d", *p);
}

/*=========================================================================================
[ 실행결과 ]
     A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q
  A  0  1  1  1  0  0  0  0  0  0  0  0  0  0  0  0  0
  B  1  0  0  0  1  0  0  0  0  0  0  0  0  0  0  0  0
  C  1  0  0  0  0  1  0  0  0  0  0  0  0  0  0  0  0
  D  1  0  0  0  0  0  0  1  0  0  0  0  0  0  0  0  0
  E  0  1  0  0  0  1  1  0  0  0  0  0  0  0  0  0  0
  F  0  0  1  0  1  0  0  1  0  0  0  0  0  0  0  0  0
  G  0  0  0  0  1  0  0  0  1  0  0  0  0  0  0  0  0
  H  0  0  0  1  0  1  0  0  1  0  0  0  0  0  0  0  0
  I  0  0  0  0  0  0  1  1  0  0  0  0  0  0  0  0  0
  J  0  0  0  0  0  0  0  0  0  0  1  1  0  0  0  0  0
  K  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0
  L  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0
  M  0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  0  0
  N  0  0  0  0  0  0  0  0  0  0  0  0  1  0  0  1  1
  O  0  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  1
  P  0  0  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0
  Q  0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  0  0

----------------------------------------
         DFS 방문(비재귀판)
----------------------------------------
  A  D  H  I  G  E  F  C  B  J  L  K  M  O  Q  N  P
----------------------------------------
         DFS 방문(재귀판)
----------------------------------------
  A  B  E  F  C  H  D  I  G  J  K  L  M  N  P  Q  O
----------------------------------------
         BFS 방문
----------------------------------------
  A  B  C  D  E  F  H  G  I  J  K  L  M  N  O  P  Q
----------------------------------------
         그래프 내의 연결 요소 보기
----------------------------------------

연결 요소 1 :   A  D  H  I  G  E  F  C  B
연결 요소 2 :   J  L  K
연결 요소 3 :   M  O  Q  N  P
그래프 내의 총 연결 요소의 개수 : 3개

  A :   D ->   C ->   B
  B :   E ->   A
  C :   F ->   A
  D :   H ->   A
  E :   G ->   F ->   B
  F :   H ->   E ->   C
  G :   I ->   E
  H :   I ->   F ->   D
  I :   H ->   G
  J :   L ->   K
  K :   J
  L :   J
  M :   O ->   N
  N :   Q ->   P ->   M
  O :   Q ->   M
  P :   N
  Q :   O ->   N
=========================================================================================*/