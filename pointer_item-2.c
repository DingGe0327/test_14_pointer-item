#define  _CRT_SECURE_NO_WARNINGS 1
//����ָ��   ����ָ��������������һ��ָ������ĵ�ַ
#include <stdio.h>
int main()
{
	int a = 10;
	int* pa = &a;     //pa��һ��ָ�������һ��ָ�����
	int** ppa = &pa;  //ppa��һ������ָ�����		int*˵��ppaָ��Ķ�����int*��  ���ң�*˵��ppa��ָ��
	** ppa = 20;
	printf("%d\n", a);
	return 0;
}

ָ������
#include <stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;

	int* pa = &a;
	int* pb = &b;
	int* pc = &c;

	//int* parr[] = { &a,&b,&c }; 
	int* parr[] = { pa,pb,pc };   

	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%d\n", *(parr[i]));
	}
	return 0;
}

#include <stdio.h>
int main()
{
	int arr1[] = {1,2,3,4,5};
	int arr2[] = {6,7,8,9,10};
	int arr3[] = { 11,12,13,14,15 };

	int * arr4[] = { arr1,arr2,arr3 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", arr4[i][j]);
			printf("%d ", *(arr4[i] + j));  //������

		}
		printf("\n");
	}
	return 0;
}





