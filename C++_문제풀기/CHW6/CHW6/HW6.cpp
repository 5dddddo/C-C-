#include <iostream>
using namespace std;
int my_strlen(char *sp, char c = '\0');
int main()
{
	char str[30], ch;
	int length;
	cout << "문자열 입력 : ";
	cin >> str;
	length = my_strlen(str);
	cout << "문자열의 길이 : " << length << endl;
	cout << "문자 입력 : ";
	cin >> ch;
	length = my_strlen(str, ch);
	cout << ch << " 이전 까지의 길이 : " << length << endl;
	cout << "문자 입력 : ";
	cin >> ch;
	length = my_strlen(str, ch);
	cout << ch << " 이전 까지의 길이 : " << length << endl;
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