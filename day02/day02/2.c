#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//1. 给定两个整形变量的值，将两个值的内容进行交换。
int main()
{
    int a=10;
    int b=20;
    int *p2=&a;
    int *p1=&b;
    int temp=0;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
    printf("%d %d",a,b);
	system("pause");
	return 0;
}
//优化版
int main()
{
	int a = 10;
	int b = 20;
	int temp = 0;
	printf("%d %d", a, b);
	temp = a;
	a = b;
	b = temp;
	printf("%d %d", a, b);
	system("pause");
	return 0;
}


//2. 不允许创建临时变量，交换两个数的内容（附加题）
int main()
{
    int a=10;
    int b=20;
	a=a+b;//a=a^b;
	b=a-b;//b=a^b;
	a=a-b;//a=a^b;
    printf("%d %d",a,b);
	system("pause");
	return 0;
}
//0^a=a    不能解决浮点型，只能解决整型  可读性差


//3.求10 个整数中最大值。
int main()
{
    int a=0,i=0;
	int b[10]={5,6,7,4,8,3,7,9,2,5};
	a=b[0];
	for(i=0;i<10;i++)
	{
		if(b[i]>a)
		{
			a=b[i];
		}
	}
    printf("%d ",a);
	system("pause");
	return 0;
}
//函数版
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}
int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	if (a < b)
	{
		Swap(&a, &b);
	}
	if (a < c)
	{
		Swap(&a, &c);
	}
	if (b < c)
	{
		Swap(&b, &c);
	}
	printf("%d %d %d\n", a, b, c);
	system("pause");
	return 0;
}


//4.将三个数按从大到小输出。
int main()
{
    int a=0,i=0,j=0;
	int b[3]={4,5,6};
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(b[j]<b[j+1])
			{
				a=b[j+1];
				b[j+1]=b[j];
				b[j]=a;
			}
		}
	}
    for(i=0;i<3;i++)
	{
		printf("%d ",b[i]);
	}
	system("pause");
	return 0;
}

// 5.求两个数的最大公约数。
int main()
{
    int a=0,b=0,i=0,c=0;
	scanf("%d %d",&a,&b);
	c=a;
	if(b<a)
	{
		c=b;
	}
	for(i=c;i>0;i--)
	{
		if(a%i==0&&b%i==0)
		{
			printf("%d\n",i);
			break;
		}
	}
	system("pause");
	return 0;
}
//优化版
int main()
{
	int a = 18;
	int b = 24;
	int c = 0;
	while(c=a%b)
	{
		a = b;
		b = c;
	}
	printf("b = %d\n", b);
	system("pause");
	return 0;
}
//最大公倍数=ab/最大公约数