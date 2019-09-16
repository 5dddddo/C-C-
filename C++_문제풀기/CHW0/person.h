#pragma once
typedef struct _person
{
	char name[20];
	int age;
	char phoneNumber[15];
}Person;

void *find(void *begin, void *end, void *value, size_t size, int(*compareData)(void *, void *));
int compareAge(void *vp1, void *vp2);     // vp1�� ����Ű�� ���� ũ�� 1, ������ 0, ������ -1 ����
int compareName(void *vp1, void *vp2);  // vp1�� ����Ű�� ���� ũ�� 1, ������ 0, ������ -1 ����
