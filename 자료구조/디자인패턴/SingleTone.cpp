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
		instance = new SingleTone(); //유일한 SingleTone 객체 1개만 생성하기
		
		atexit(destroy); //void (*atexit)(void (*)(void));
						 //프로그램이 종료될 때 전달한 함수를 자동 호출, 여러 번 호출할 수 있음(Stack구조 : FILO)
	}
	return instance;
}

void SingleTone::destroy()
{
	if (instance != NULL)
	{
		delete instance;
		instance = NULL; //dangling pointer 방지
	}
}