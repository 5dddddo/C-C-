#pragma once
typedef struct _pattern
{
	char pattern[8];
	int cnt;
}Pattern;

typedef Pattern DataType;
void printPattern(DataType *p);
int comparePatternPattern(DataType *p1, DataType *p2);
int comparePatternCnt(DataType *p1, DataType *p2);
