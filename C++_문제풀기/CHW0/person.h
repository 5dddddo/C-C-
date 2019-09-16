#pragma once
typedef struct _person
{
	char name[20];
	int age;
	char phoneNumber[15];
}Person;

void *find(void *begin, void *end, void *value, size_t size, int(*compareData)(void *, void *));
int compareAge(void *vp1, void *vp2);     // vp1이 가리키는 값이 크면 1, 같으면 0, 작으면 -1 리턴
int compareName(void *vp1, void *vp2);  // vp1이 가리키는 값이 크면 1, 같으면 0, 작으면 -1 리턴
