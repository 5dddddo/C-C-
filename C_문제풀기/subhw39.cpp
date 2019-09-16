#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>
#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH 13 /* 주민등록번호 길이*/
int availability_check(char *resident_number);
int length_character_check(char *resident_number);
int date_check(char *resident_number);
int identification_check(char *resident_number);
int gender_check(char *resident_number);
int year_check(int year);
int checkData(int, int, int);
int main()
{
	/* 테스트할 주민등록번호 저장 배열*/
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
		"0003154194917", "801203#201122", "7804155328845", "7804150328840",
		"9612241068382", "9902292194322", "0230174326176", "8811391042219",
		"8100122042213", "8112002042213", "9210101069415", "0802294012345",
		"8806311069417", "8807311069418"
	};
	int i, count;
	/* 검사할 주민등록번호의 개수 계산*/
	count = sizeof(resident_number) / sizeof(resident_number[0]);
	for (i = 0; i<count; i++) /* 주민등록번호 유효성 검사를 반복적으로 수행 함*/
	{
		if (availability_check(resident_number[i]) == TRUE)
		{
			printf("(+) 주민번호%s는(은) 유효한 번호입니다.\n", resident_number[i]);
		}
		else
		{
			printf("(-) 주민번호%s는(은) 유효하지 않은 번호입니다.\n", resident_number[i]);
		}
	}
	return 0;
}
int availability_check(char *resident_number)
{
	if (length_character_check(resident_number)) /* 길이 및 숫자문자 유효성검사*/
	{
		if (date_check(resident_number)) /* 날짜검사*/
		{
			if (identification_check(resident_number)) /* 인식자 오류체크*/
			{
				return TRUE;
			}
		}
	}
	return FALSE;
}
int length_character_check(char *resident_number)
{
	int i, len;
	len = strlen(resident_number);
	if (len == 13)
	{
		for (i = 0; i < len; i++)
		{
			if (resident_number[i] < '0' || resident_number[i]  > '9')
			{
				return FALSE;
			}
		}
	}
	else
	{
		return FALSE;
	}
	return TRUE;
}

int date_check(char *resident_number)
{
	int year, month, day;
	if (gender_check(resident_number))
	{
		switch (resident_number[6])
		{
		case '1':
		case '2':year = 1900 + (resident_number[0] - '0') * 10 + (resident_number[1] - '0');
			break;
		case '3':
		case '4':year = 2000 + (resident_number[0] - '0') * 10 + (resident_number[1] - '0');
			break;
		default:
			break;
		}
	}
	else
	{
		return FALSE;
	}
	month = (resident_number[2] - '0') * 10 + (resident_number[3] - '0');
	day = (resident_number[4] - '0') * 10 + (resident_number[5] - '0');
	return checkData(year, month, day);
}
int identification_check(char *resident_number)
{
	int sum = 0, i;
	for (i = 0; i < 12; i++)
	{
		sum += resident_number[i] - '0';
	}
	if (resident_number[12] - '0' == sum % 10)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
int gender_check(char *resident_number)
{
	switch (resident_number[6])
	{
	case '1':
	case '2':
	case '3':
	case '4':return TRUE;
		break;
	default:return FALSE;
		break;
	}
}
int year_check(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int checkData(int year, int month, int day)
{
	int res = 1;
	if (year <= 0 || month <= 0 || day <= 0)
	{
		res = 0;
	}
	else
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day > 31)
			{
				res = 0;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30)
			{
				res = 0;
			}
			break;
		case 2:
			if (year_check(year))
			{
				if (day > 29)
				{
					res = 0;
				}
			}
			else
			{
				if (day > 28)
				{
					res = 0;
				}
			}
			break;
		default:
			res = 0;
		}
	}
	return res;
}