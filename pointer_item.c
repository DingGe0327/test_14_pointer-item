#define  _CRT_SECURE_NO_WARNINGS 1
指针的大小在32位机器上是4个字节，在64位机器上是8个字节
#include <stdio.h>
int main()
{	
	char* pa;
	int* pb;
	double* pc;
	printf("%d\n", sizeof(*pa));  //1
	printf("%d\n", sizeof(*pb));  //4
	printf("%d\n", sizeof(*pc));  //8

	printf("%d\n", sizeof(pa));  //8
	printf("%d\n", sizeof(pb));  //8
	printf("%d\n", sizeof(pc));  //8
	
	//指针类型的意义：指针类型决定了，1.指针解引用的权限有多大   2.指针走一步能走多远（指针+1：  char:地址+1    shor:2   double:8）
	int a = 0x11223344;//十六进制
	char* pa = &a;
	*pa = 0;
	printf("%d\n", a);  //0x11223300
	return 0;
}

野指针
#include <stdio.h>
int main()
{
	int* p;   //p没有初始化，意味着没有明确的指向。一个局部变量不初始化，存放的是随机值0xcccccccc
	*p = 10;
	printf("%d\n", *p);  //p：野指针，非法访问内存
	return;
}

int main()
{
	int arr[10] = { 0 };
	int* p = arr;
	int i = 0;
	for (i = 0; i <= 10; i++)
	{
		*p = i;   //当指针指向的范围超出数组arr的范围时，p就是野指针
		p++;
	}
	return 0;
}

int* test()
{
	int a = 10;
	return &a;  //返回的是地址，局部变量被销毁
}
int main()
{
	int* p = test();  //野指针
	printf("hh\n");
	printf("%d\n", *p);  //这个值是变化的
	return 0;
}

#include <stdio.h>
int main()
{
	int* p1 = NULL;
	if (p1 != NULL)
	{
		*p1 = 10;
	}
	return 0;
}

指针的运算
#include <stdio.h>
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
		int* p = arr;
	for (i = 0; i < sz; i++)
	{

		*p = 1;
		p++;
		//*(p + i) = 1;
	}
	return 0;
}

#include <stdio.h>
int main()
{
	int arr[10] = { 0 };
	printf("%d\n", &arr[9] - &arr[0]);  //9   指针相减得到的是两个指针之间元素的个数(指向同一块空间的两个指针才能相减)
	////int a = 2;
	////int b = 9;
	////printf("%d\n", &a - &b);
	return 0;
}

int my_strlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;

	}
	return count;
}
int main()
{
	int len = my_strlen("abcdef");
	printf("%d\n", len);   //6
	return 0;
}

指针-指针
int my_strlen(char* str)
{
	char* start = str;
	while (*str != '\0')
	{
		str++;
	}
	return str - start;
}
int main()
{
	int len = my_strlen("abcdef");
	printf("%d\n", len);  //6
	return 0;
}
