#include <iostream>
using namespace std;
int my_strlen(char *sp, char c = '\0');
int main()
{
	char str[30], ch;
	int length;
	cout << "���ڿ� �Է� : ";
	cin >> str;
	length = my_strlen(str);
	cout << "���ڿ��� ���� : " << length << endl;
	cout << "���� �Է� : ";
	cin >> ch;
	length = my_strlen(str, ch);
	cout << ch << " ���� ������ ���� : " << length << endl;
	cout << "���� �Է� : ";
	cin >> ch;
	length = my_strlen(str, ch);
	cout << ch << " ���� ������ ���� : " << length << endl;
	return 0;
}

int my_strlen(char *sp, char c)
{
	int count = 0, i = 0;
	while (1)
	{
		if (sp[i] == c || sp[i] == '\0') break;
		else count++;
		i++;
	}
	return count;
}