#include <iostream>
using namespace std;
#include<stdlib.h>

#define ARRAY_SIZE(a) (static_cast<unsigned int>(sizeof(a) / sizeof(a)[0]))
#define ARRAY_ITEM_SIZE(a) (static_cast<unsigned int>(sizeof(a[0])))

class Obj
{
public:
	Obj() : pFunc(&Obj::compare) {} //객체가 생성될 때 pFunc을 compare로 초기화

	int compare(const int* one, const int* two) { return (*one<*two) ? -1:1; }

	int (Obj::*pFunc)(const int*, const int*); //compare 타입의 멤버 포인터 변수
};

int wrapper_comp1(const int* one, const int* two)
{
	Obj o;
	int (Obj::*mpFunc)(const int*, const int*) = &Obj::compare;
	return ((o.*mpFunc)(one, two)); //지역 멤버 포인터 변수를 이용한 간접 호출
}

int wrapper_comp2(const int* one, const int* two)
{
	Obj o;
	return ((o.*o.pFunc)(one, two)); //클래스의 멤버포인터 변수를 이용한 간접 호출
}
int main()
{
	int a[] = { 20, 50, 30, 70, 40, 60 };

	qsort(a, ARRAY_SIZE(a), ARRAY_ITEM_SIZE(a),
			reinterpret_cast<int(*)(const void*, const void*)>(wrapper_comp2));

	for (int i=0; i<sizeof(a)/sizeof(a[0]); i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
	cin.get();
	return 0;
}
