#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//1.����Ļ���������ͼ���� 
//      *
//     ***
//   *****
//   *******
//  *********
// ***********
//*************
// ***********
//  *********
//   *******
//    *****
//     ***
//      *
int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < 7; i++)
	{
		for (j = 6-i; j>0; j--)
		{
			printf(" ");
		}
		printf("*");
		for (k = 0; k < i; k++)
		{
			printf("**");
		}
		printf("\n");
	}
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		printf("*");
		for (k = 5; k>i; k--)
		{
			printf("**");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
//�Ż���
int main()
{
	int maxline;
	scanf("%d", &maxline);
	//�ϰ벿��
	for (int i = 1; i <= maxline; i++)
	{
		//�ո� maxline - i
		for (int j = 1; j <= maxline - i; j++)
		{
			printf(" ");
		}
		//* �� 2*i - 1
		for (int j = 1; j <= 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//�°벿��
	for (int i = 1; i < maxline; i++)
	{
		//�ո� i
		for (int j = 1; j <= i; j++)
		{
			printf(" ");
		}
		//* �� 2*(maxline - i) - 1
		for (int j = 1; j <= 2 *(maxline - i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}


//2.���0��999֮������С�ˮ�ɻ������������ 
//ˮ�ɻ�������ָһ����λ�������λ���ֵ�������ȷ�õ��ڸ��������磻153��1��5��3 ? ����153��һ����ˮ�ɻ�������
/*
�������У�ˮ�ɻ�����Narcissistic number��Ҳ��Ϊ������������������ķ˹׳����ķ˹��������Armstrong number������ָһNλ�����������֮N�η��͵��ڸ�����
����153��370��371��407������λ����ˮ�ɻ������������֮�����͵��ڸ�����
153 = 1^3 + 5^3 + 3^3��
370 = 3^3 + 7^3 + 0^3��
371 = 3^3 + 7^3 + 1^3��
407 = 4^3 + 0^3 + 7^3��
*/
int main()
{
	int a = 0;
	int b = 0;
	int sum = 0;
	int c = 0;
	for (a = 100; a < 1000; a++)
	{
		b = 0;
		sum = 0;
		c = a;
		while (c>0)
		{
			b = c % 10;
			c = c / 10;
			sum = sum + b*b*b;
		}
    	if (sum == a)
    	{
	    	printf("%d ", a);
    	}
	}

	system("pause");
	return 0;
}
//�Ż���
void nPowerNumber()
{
	int i;
	for (i = 100; i < 1000; i++)
	{
		int tmp = i;
		int Sum = 0;
		while (tmp)
		{
			//��ȡÿһλ����
			int num = tmp % 10;
			//�ۼ�ÿһλ���ֵ�����
			Sum += pow(num, 3);
			tmp /= 10;
		}
		if (Sum == i)
		{
			printf("%d\n", i);
		}
	}
}
void nPowerNumber2()
{
	int i;
	int n, m;
	scanf("%d %d", &n, &m);
	for (i = n; i < m; i++)
	{
		//sizeof(i) -->  4
		int tmp = i;
		int Sum = 0;
		int count = 0;
		//��ȡ����
		while (tmp)
		{
			tmp = tmp / 10;
			count++;
		}
		// tmp = 0
		tmp = i;
		while (tmp)
		{
			//��ȡÿһλ����
			int num = tmp % 10;
			//�ۼ�ÿһλ���ֵ�count�η�
			Sum += pow(num, count);
			tmp /= 10;
		}
		if (Sum == i)
		{
			printf("%d\n", i);
		}
	}
}
int main()
{
	nPowerNumber2();
	return 0;
}


//3.��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222
int main()
{
	int a = 0;
	int i = 0;
	int Sn = 0;
	int num = 0;
	scanf("%d", &num);
	for (i = 0; i < 5; i++)
	{
		a = a * 10 + num;
		Sn = Sn + a;
	}
	printf("%d\n", Sn);
	system("pause");
	return 0;
}
//�Ż���
int Sum3(int a, int n)
{
	int sum = 0;
	int tmp = 0;
	while (n > 0)
	{
		// tmp = a  --> a * 10 + a  tmp = aa   -->  aa * 10 + a
		tmp = tmp * 10 + a;
		sum += tmp;
		n--;
	}
	return sum;
}
int main()
{
	int a, n;
	scanf("%d %d", &a, &n);
	printf("%d \n",Sum3(a, n));
	return 0;
}