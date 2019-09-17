#pragma once
typedef struct _line{
	char str[81];
	int lineNum;
}Line;

typedef Line DataType;
int compareLineNumber(DataType *p1, DataType *p2);
void printPerson(DataType *lp);
