#define  _CRT_SECURE_NO_WARNINGS 1
ָ��Ĵ�С��32λ��������4���ֽڣ���64λ��������8���ֽ�
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
	
	//ָ�����͵����壺ָ�����;����ˣ�1.ָ������õ�Ȩ���ж��   2.ָ����һ�����߶�Զ��ָ��+1��  char:��ַ+1    shor:2   double:8��
	int a = 0x11223344;//ʮ������
	char* pa = &a;
	*pa = 0;
	printf("%d\n", a);  //0x11223300
	return 0;
}

Ұָ��
#include <stdio.h>
int main()
{
	int* p;   //pû�г�ʼ������ζ��û����ȷ��ָ��һ���ֲ���������ʼ������ŵ������ֵ0xcccccccc
	*p = 10;
	printf("%d\n", *p);  //p��Ұָ�룬�Ƿ������ڴ�
	return;
}

int main()
{
	int arr[10] = { 0 };
	int* p = arr;
	int i = 0;
	for (i = 0; i <= 10; i++)
	{
		*p = i;   //��ָ��ָ��ķ�Χ��������arr�ķ�Χʱ��p����Ұָ��
		p++;
	}
	return 0;
}

int* test()
{
	int a = 10;
	return &a;  //���ص��ǵ�ַ���ֲ�����������
}
int main()
{
	int* p = test();  //Ұָ��
	printf("hh\n");
	printf("%d\n", *p);  //���ֵ�Ǳ仯��
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

ָ�������
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
	printf("%d\n", &arr[9] - &arr[0]);  //9   ָ������õ���������ָ��֮��Ԫ�صĸ���(ָ��ͬһ��ռ������ָ��������)
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

ָ��-ָ��
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
