#pragma once
#pragma warning(disable : 4996)
#include <string.h>
#include <malloc.h>
#include <stdio.h>
typedef struct _word
{
	char *wp;
	int length;
}Word;

void wordMemCpy(void *p1, void *p2);
void wordClear(void *p);
void wordPrint(int count, int *sum, void *p);
int wordCompare(void *p1, void *p2);
//int wordAgeCompare(void *p1, void *p2);
//int wordCompare(void *p1, void *p2);
