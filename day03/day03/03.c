#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//1. 将数组A中的内容和数组B中的内容进行交换。（数组一样大）
int main()
{
	int arr1[5] = { 1, 2, 3, 4, 5 };
	int arr2[5] = { 5, 4, 3, 2, 1 };
	int tmp = 0, i = 0;
	int n = sizeof(arr1) / sizeof(arr1[0]);
	for (i = 0; i < n; i++)
	{
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr2[i]);
	}
	system("pause");
	return 0;
}
//优化：
void fun(int a[], int b[], int sz)
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i < sz; i++)
	{
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
}
void fun2(int a[], int b[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		// a = a ^ b
		a[i] = a[i] ^ b[i];
		// b = a ^ b
		b[i] = a[i] ^ b[i];
		// a = a ^ b
		a[i] = a[i] ^ b[i];
	}
}
void fun3(int a[], int b[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		// a = a + b   a = 10    b = 5   --> a = 15
		a[i] = a[i] + b[i];
		// b = a - b    b = 15 - 5 = 10    -->  a = 15
		b[i] = a[i] - b[i];
		// a = a - b   b = 10   -->  a = 5 
		a[i] = a[i] - b[i];
	}
}
void printArray(int a[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	int a[] = {1, 2, 3, 4, 5};
	int b[] = { 11, 12, 13, 14, 15 };
	printArray(a, 5);
	printArray(b, 5);
	fun(a, b, 5);
	printArray(a, 5);
	printArray(b, 5);
	fun2(a, b, 5);
	printArray(a, 5);
	printArray(b, 5);
	fun3(a, b, 5);
	printArray(a, 5);
	printArray(b, 5);
	return 0;
}


//2. 计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值。
int main()
{
	double i = 1,sum = 0;
	int b = 1;
	for (i = 1; i <= 100; i++)
	{
		sum += ( 1 / i ) * b;
		b *= ( -1 );
	}
	printf("%lf\n", sum);
	system("pause");
	return 0;
}
//优化版：
double Sum()
{
	double sum1 = 0, sum2 = 0;
	int i;
	for (i = 1; i < 100; i += 2)
	{
		sum1 += 1.0 / i;
	}
	for (i = 2; i <= 100; i += 2)
	{
		sum2 += 1.0 / i;
	}
	//奇数项的和 - 偶数项的和
	return sum1 - sum2;
}
double Sum2()
{
	double sum1 = 0;
	int i;
	int flag = 1;
	for (i = 1; i <= 100; i++)
	{
		sum1 += 1.0 / i * flag;
		flag = -flag;
	}
	return sum1;
}
int main()
{
	printf("%lf\n", Sum());
	printf("%lf\n", Sum2());
	return 0;
}


//3. 编写程序数一下 1到 100 的所有整数中出现多少次数字9
int main()
{
	int i = 0;
	int k = 0;
	for (i = 1; i < 100; i++)
	{
		if (i % 10 == 9)
		{
			k++;
		}
		if (i / 10 == 9)
		{
			k++;
		}
	}
	printf("%d\n", k);
	system("pause");
	return 0;
}
//优化版：
int main()
{
	int n, m;
	int i = 0;
	int sum = 0;
	for (i = 1; i < 100; i++)
	{
		//分别查看个位和十位上的数字
		// / 10 : 获取十位上的数字
		if (i / 10 == 9)
		{
			sum++;
		}
		// % 10： 获取个位上的数字
		if (i % 10 == 9)
			sum++;
	}
	printf("%d\n", sum);
	return 0;
}
//或：
int main()
{
	int n, m;
	int i = 0;
	int sum = 0;
	scanf("%d %d", &n, &m);
	for (i = n; i <= m; i++)
	{
		int tmp = i;
		//通过连续%10, /10获取i的每一位的数字
		// %10： 获取个位的数字
		// /10： 把其它位的数字移到个位
		while (tmp)
		{
			if (tmp % 10 == 9)
				sum++;
			tmp /= 10;
		}
	}
	printf("%d\n", sum);
	return 0;
}