#define  _CRT_SECURE_NO_WARNINGS 1
//二级指针   二级指针变量是用来存放一级指针变量的地址
#include <stdio.h>
int main()
{
	int a = 10;
	int* pa = &a;     //pa是一个指针变量，一级指针变量
	int** ppa = &pa;  //ppa是一个二级指针变量		int*说明ppa指向的对象是int*型  （右）*说明ppa是指针
	** ppa = 20;
	printf("%d\n", a);
	return 0;
}

指针数组
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
			printf("%d ", *(arr4[i] + j));  //解引用

		}
		printf("\n");
	}
	return 0;
}





