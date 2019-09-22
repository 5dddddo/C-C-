#include "SingleTone.h"

SingleTone *SingleTone::instance = NULL;
SingleTone::SingleTone()
{
}
SingleTone::~SingleTone()
{
}
SingleTone * SingleTone::getInstance()
{
	if (instance == NULL)
	{
		instance = new SingleTone(); //������ SingleTone ��ü 1���� �����ϱ�
		
		atexit(destroy); //void (*atexit)(void (*)(void));
						 //���α׷��� ����� �� ������ �Լ��� �ڵ� ȣ��, ���� �� ȣ���� �� ����(Stack���� : FILO)
	}
	return instance;
}

void SingleTone::destroy()
{
	if (instance != NULL)
	{
		delete instance;
		instance = NULL; //dangling pointer ����
	}
}