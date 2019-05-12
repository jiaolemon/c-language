#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//1.完成猜数字游戏。 
void menu()
{
	printf("***********************************\n");
	printf("************  1. play  ************\n");
	printf("************  0. exit  ************\n");
	printf("***********************************\n");
}

void game()
{
	int ret = rand()%100+1;
	int b=0;
	while (1)
	{
		printf("请输入所猜的值->:");
		scanf("%d", &b);
		if (b > ret)
		{
			printf("猜大了\n");
		}
		else if (b < ret)
		{
			printf("猜小了\n");
		}
		else if (b == ret)
		{
			printf("猜对了\n");
			break;
		}
	}
}

int main()
{
	int a=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入->:");
		scanf("%d", &a);
		if (a == 1)
		{
			game();
		}
		else if (a == 0)
		{
			break;
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	} while (a);
	return 0;
}
//其他：
void Guess()
{
	srand((unsigned int)time(NULL));
	int a = rand() % 100;
	int input;
	while (1)
	{
		scanf("%d", &input);
		if (input == a)
		{
			printf("正确\n");
			break;
		}
		else if (input > a)
		{
			printf("big!\n");
		}
		else
		{
			printf("less!\n");
		}
	}
}
int main()
{
	int input = 0;
	while (1)
	{
		printf("**********1. play*************\n");
		printf("**********0. exit*************\n");
		scanf("%d", &input);
		if (input == 1)
			Guess();
		else if (input == 0)
			break;
		else
		{
			printf("重新输入\n");
		}
	}
	return 0;
}


//2.写代码可以在整型有序数组中查找想要的数字，
//找到了返回下标，找不到返回 - 1.（折半查找）
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a=0;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0])-1;	
	scanf("%d", &a);
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] > a)
		{
			right = mid - 1;
		}
		else if (arr[mid] < a)
		{
			left = mid + 1;
		}
		else
		{
			printf("找到了，下标是:%d\n", mid);
			break;
		}
	}
	if (left>right)
	{
		printf("找不到\n");
	}
	system("pause");
	return 0;
}
//优化：
int find(int arr[], int sz, int key)
{
	int start = 0;
	int end = sz - 1;
	int mid = 0;
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] > key)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return -1;
}
int main()
{
	int key;
	scanf("%d", &key);
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int pos = find(arr, 10, key);
	if (pos != -1)
	{
		printf("%d\n", pos);
	}
	else
	{
		printf("not find!\n");
	}
	return 0;
}


//3.编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，
//可以重新输入，最多输入三次。三次均错，则提示退出程序。
#include <string.h>

int main()
{
	char psw[10] = "";
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("请输入：");
		scanf("%s", psw);
		if (strcmp(psw, "123456")==0)
		{
			printf("登陆成功！\n");
			break;
		}
		else
		{
			printf("输入错误");
		}
	}
	if (i == 3)
	{
		printf("退出程序\n");
	}
	system("pause");
	return 0;
}


//4.编写一个程序，可以一直接收键盘字符，
//如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，
//如果是数字不输出。
int main()
{
	char a;
	while (1)
	{
		scanf("%c", &a);
		if (a >=65 && a <= 90)
		{
			printf("%c", a + 32);
		}
		else if (a >= 97 && a <= 122)
		{
			printf("%c", a - 32);
		}
	}
	system("pause");
	return 0;
}
//其他：
void transformChar()
{
	while (1)
	{
		char ch;
		scanf("%c", &ch);
		//判断字符区间
		if ('A' <= ch && ch <= 'Z')
		{
			//大写转小写
			printf("%c\n", ch + 32);
		}
		if ('a' <= ch && ch <= 'z')
		{
			//小写转大写
			printf("%c\n", ch - 32);
		}
	}
}
void transformChar2()
{
	while (1)
	{
		int ch;
		ch = getchar();
		//判断字符区间
		if ('A' <= ch && ch <= 'Z')
		{
			//大写转小写
			putchar(ch + 32);
			printf("\n");
		}
		if ('a' <= ch && ch <= 'z')
		{
			//小写转大写
			putchar(ch - 32);
			printf("\n");
		}
	}
}
int main()
{
	transformChar2();
	return 0;
}
