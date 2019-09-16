#include <stdio.h>
#include "person.h"
int main()
{
	Person x[10] = { { "������", 21, "010-1234-5678" }, { "���ٶ�", 22, "010-1111-2222" }, { "�ٶ�", 23, "010-4345-5565" },
	{ "�󸶹�", 24, "010-7657-1785" }, { "���ٻ�", 25, "010-9898-2846" }, { "�ٻ��", 26, "010-3454-6745" },
	{ "�����", 27, "010-1454-9568" }, { "������", 28, "010-5965-2913" }, { "����ī", 29, "010-7877-1216" }, { "��īŸ", 30, "010-9432-7654" } };

	char userName1[20] = { "�����" };
	char userName2[20] = { "������" };
	int userAge1 = 24;
	int userAge2 = 5;
	Person *ip;

	// �˻� ��� O
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
	// �˻� ��� X
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