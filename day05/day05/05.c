#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//1.��ɲ�������Ϸ�� 
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
		printf("���������µ�ֵ->:");
		scanf("%d", &b);
		if (b > ret)
		{
			printf("�´���\n");
		}
		else if (b < ret)
		{
			printf("��С��\n");
		}
		else if (b == ret)
		{
			printf("�¶���\n");
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
		printf("������->:");
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
			printf("�����������������\n");
		}
	} while (a);
	return 0;
}
//������
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
			printf("��ȷ\n");
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
			printf("��������\n");
		}
	}
	return 0;
}


//2.д����������������������в�����Ҫ�����֣�
//�ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�
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
			printf("�ҵ��ˣ��±���:%d\n", mid);
			break;
		}
	}
	if (left>right)
	{
		printf("�Ҳ���\n");
	}
	system("pause");
	return 0;
}
//�Ż���
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


//3.��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���, �������
//�����������룬����������Ρ����ξ�������ʾ�˳�����
#include <string.h>

int main()
{
	char psw[10] = "";
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("�����룺");
		scanf("%s", psw);
		if (strcmp(psw, "123456")==0)
		{
			printf("��½�ɹ���\n");
			break;
		}
		else
		{
			printf("�������");
		}
	}
	if (i == 3)
	{
		printf("�˳�����\n");
	}
	system("pause");
	return 0;
}


//4.��дһ�����򣬿���һֱ���ռ����ַ���
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
//��������ֲ������
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
//������
void transformChar()
{
	while (1)
	{
		char ch;
		scanf("%c", &ch);
		//�ж��ַ�����
		if ('A' <= ch && ch <= 'Z')
		{
			//��дתСд
			printf("%c\n", ch + 32);
		}
		if ('a' <= ch && ch <= 'z')
		{
			//Сдת��д
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
		//�ж��ַ�����
		if ('A' <= ch && ch <= 'Z')
		{
			//��дתСд
			putchar(ch + 32);
			printf("\n");
		}
		if ('a' <= ch && ch <= 'z')
		{
			//Сдת��д
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
