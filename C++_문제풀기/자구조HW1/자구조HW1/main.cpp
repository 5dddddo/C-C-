//#include <stdio.h>
//#include <string.h>
//int bad_int_size_32();
//int main()
//{
//	int a;
//
//	a = bad_int_size_32();
//	printf("a = %d\n", a);
//}
//int bad_int_size_32(){
//	int set_msb = 1 << 31;
//	int beyond_msb = 1 << 32;
//	return set_msb && !beyond_msb;
//}
//
////3¹ø
//void copy_int(int val, void *buf, int maxbytes)
//{
//	if (maxbytes - sizeof(val) >= 0)
//		memcpy(buf, (void *)&val, sizeof(val));
//
//}

#include <stdio.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, int len);
void show_int(int x);
void show_float(float x);
void show_pointer(void *x);
void test_show_bytes(int val);
int main()
{
	test_show_bytes(12345);
	return 0;
}
void show_bytes(byte_pointer start, int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf("%.2x", start[i]);
	printf("\n");
}
void show_int(int x)
{
	show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
	show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
	show_bytes((byte_pointer)&x, sizeof(void *));
}

void test_show_bytes(int val)
{
	int ival = val;
	float fval = (float)ival;
	int *pval = &ival;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}
