#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
//1. 打印100~200之间的素数
int main()
{
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		int j = 0;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
				break;
		}
		if (i == j)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
//优化版
int main()
{
	int i = 100;
	while (i <= 200)
	{
		int j = 2;
		while (j < i)//j<=sqrt(i)   j<=(i)/2
		{
			if (i%j == 0)
			{
				break;
			}
			j++;
		}
		if (i == j)//j>sqrt(i)
		{
			printf("%d ", i);
		}
		i++;
	}
	system("pause");
	return 0;
}
//素数求解的N种境界


//2. 输出乘法口诀表
int main()
{
	int i = 0, a = 0;
	for (i = 1; i <= 9; i++)
	{
		int j = 0;
		for (j = 1; j <= i; j++)
		{
			a = i*j;
			printf("%d*%d=%2d ", i, j, a);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}


//3. 判断1000年-- - 2000年之间的闰年
int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			printf("%d ", year);
		}
	}
	system("pause");
	return 0;
}
//优化版
int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (year % 4 == 0)
		{
			if (year % 100 != 0)
			{
				printf("%d ", year);
			}
		}
		if (year % 400 == 0)
		{
			printf("%d ", year);
		}
	}
	system("pause");
	return 0;
}

