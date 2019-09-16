#include <stdio.h>
#include "person.h"
int main()
{
	Person x[10] = { { "가나다", 21, "010-1234-5678" }, { "나다라", 22, "010-1111-2222" }, { "다라마", 23, "010-4345-5565" },
	{ "라마바", 24, "010-7657-1785" }, { "마바사", 25, "010-9898-2846" }, { "바사아", 26, "010-3454-6745" },
	{ "사아자", 27, "010-1454-9568" }, { "아자차", 28, "010-5965-2913" }, { "자차카", 29, "010-7877-1216" }, { "차카타", 30, "010-9432-7654" } };

	char userName1[20] = { "사아자" };
	char userName2[20] = { "오은애" };
	int userAge1 = 24;
	int userAge2 = 5;
	Person *ip;

	// 검색 결과 O
	ip = (Person *)find(x, x + 10, &userAge1, sizeof(Person), compareAge);
	if (ip == x + 10) { printf("not find\n"); }
	else
	{ 
		printf("# Search Age = %d\nData name = %s Data Age = %d Data Phonenumber = %s\n\n",
			userAge1, ip->name, ip->age, ip->phoneNumber);
	}

	ip = (Person *)find(x, x + 10, &userName1, sizeof(Person), compareName);
	if (ip == x + 10) { printf("not find\n"); }
	else {
		printf("# Search Name = %s\nData name = %s Data Age = %d Data Phonenumber = %s\n\n",
			userName1, ip->name, ip->age, ip->phoneNumber);
	}
	// 검색 결과 X
	ip = (Person *)find(x, x + 10, &userAge2, sizeof(Person), compareAge);
	if (ip == x + 10) {
		printf("# Search Age = %d\nNot find\n\n",userAge2); }
	else
	{
		printf("# Search Age = %d\nData name = %s Data Age = %d Data Phonenumber = %s\n\n",
			userAge2, ip->name, ip->age, ip->phoneNumber);
	}

	ip = (Person *)find(x, x + 10, &userName2, sizeof(Person), compareName);
	if (ip == x + 10) { printf("# Search Name = %s\nNot find\n\n",userName2); }
	else {
		printf("# Search Name = %s\nData name = %s Data Age = %d Data Phonenumber = %s\n\n",
			userName2, ip->name, ip->age, ip->phoneNumber);
	}
	return 0;
}