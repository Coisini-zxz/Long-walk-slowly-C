#define _CRT_SECURE_NO_WARNINGS	1	// ���ڿ�ͷ ��ֹscanf����
#include <stdio.h>
#include <string.h>

int main()
{
	// use_swap();
	// use_is_prime();
	// Binary_eg();
	// func_Declaration();
	// call_sub();

	// int num = 1234;
	// print(num);

	//char arr[] = "bit";
	//// "b" "i" "t" "\0"
	//// ģ��ʵ��strlen()
	//// printf("%d\n", strlen(arr));
	//printf("%d\n", my_strlen(arr));
	
	Fibonacci_number();

	return 0;
}

// �����������͵ĵط�д�� void ��ʾ�����������κ�ֵ�� Ҳ����Ҫ����ֵ
/*
void Swap(int x, int y)  //��ֵ����
{
	int z = 0;
	z = x;
	x = y;
	y = z;
}
��������޷�ʵ�� ���Բ鿴ԭ�� - x,y ��ȷ��������a,b��ֵ ���ǣ� ���ǵĵ�ַ�ռ䲻һ���� ����Ĳ���ֻ�ǿ�����һ�ݣ�
*/


void Swap(int* pa, int* pb)  // ��ַ����
{
	int z = 0;
	z = *pa;
	*pa = *pb;
	*pb= z;
}


int is_prime(int n)
{
	int j = 0;
	for (j = 2; j < n; j++)
	{
		if (n % j == 0)
			return 0;
	}
	return 1;
}


int use_swap()
{
	int a = 10;
	int b = 20;
	printf("SawpǰΪ-%d,%d\n", a, b);
	Swap(&a, &b);
	printf("Sawp��Ϊ-%d,%d\n", a, b);
	return 0;
}


int use_is_prime() 
{
	int i = 100;
	int count = 0;
	for (i = 100; i <= 200; i++)
	{
		if (is_prime(i) == 1)
		{
			printf("%d\n", i);
			count++;
		}
	}
	printf("count=%d\n", count);
	return 0;
}


// дһ��������ʵ��һ��������������Ķ��ֲ���
int Binary_eg()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int key = 7;
	// �ҵ������±� �Ҳ�������-1

	int sz = sizeof(arr) / sizeof(arr[0]);
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// ���ܰ�sz�ں�������㣡��
	// ����arr���� ʵ�ʴ��ݵĲ�������ı��� ��������ȥ��������Ԫ�صĵ�ַ
	int ret = binary_search(arr, key, sz);
	if (-1 == ret)
	{
		printf("�Ҳ���\n");
	}
	else
	{
		printf("�ҵ���, �±�Ϊ %d \n", ret);
	}
	return 0;
}


// int binary_search(int* a[], int k)
int binary_search(int a[], int k, int s)
{
	int left = 0;
	int right = s - 1;
	while (left<=right) 
	{
		int mid = (left + right) / 2;
		if (a[mid] > k)
		{
			right = mid - 1;
		}
		else if (a[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
}

// ������Ƕ�׵��ú���ʽ����

int nested_calls()
{
	char arr[20] = "hello";
	int ret = strlen(strcat(arr, "bit"));//�������һ��strlen����
	printf("%d\n", ret);
	return 0;
}

int chain_access()
{
	printf("%d", printf("%d", printf("%d", 43)));
	//�����ɶ��
	//ע��printf�����ķ���ֵ�Ǵ�ӡ����Ļ���ַ��ĸ���
	// 4321
	return 0;
}

// �������������

int func_Declaration()
{
	int a = 10;
	int b = 20;
	
	// �������� - ��֪��������� (warning C4013: ��xxxx��δ���壻)
	// �����ȶ�����ʹ�� ��Ϊ�����������ɨ ���func���¿��������� ��������warning
	int Add(int, int);
	int c = Add(a, b);
	printf("%d\n", c);
	return 0;

}


int Add(int x, int y)
{
	return x + y;
}

/*
����������
1. ���߱�������һ��������ʲô��������ʲô������������ʲô�����Ǿ����ǲ��Ǵ��ڣ�����
�����������ˡ�
2. ����������һ������ں�����ʹ��֮ǰ��Ҫ������������ʹ�á�
3. ����������һ��Ҫ����ͷ�ļ��е�
*/

// �����������˵Ĵ���ʱ
#include "sub.h"
int call_sub()
{
	int a = 10;
	int b = 6;
	int c = Sub(a, b);
	printf("%d\n", c);
	return 0;
}

// �ݹ�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
/*
ʲô�ǵݹ飿
------------�����������ı�̼��ɳ�Ϊ�ݹ飨 recursion����
------------�ݹ���Ϊһ���㷨�ڳ�����������й㷺Ӧ�á� һ�����̻������䶨���˵������ֱ�ӻ���
���������һ�ַ�������ͨ����һ�����͸��ӵ�������ת��Ϊһ����ԭ�������ƵĹ�ģ��С�����������
�ݹ���� ֻ�������ĳ���Ϳ������������������Ҫ�Ķ���ظ����㣬���ؼ����˳���Ĵ�������

�ݹ����Ҫ˼����ʽ���ڣ�
------------�Ѵ��»�С

�ݹ��������Ҫ����
------------���������������������������������ʱ�򣬵ݹ�㲻�ټ����� ������������
------------ÿ�εݹ����֮��Խ��Խ�ӽ������������ ���ƽ�����������
------------ͬʱ�����Ƿ��ջ��� ���ݹ��β���̫�
*/
void print(int n)
{
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}

//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}

// �õݹ�д
int my_strlen(char* str)
{
	if (*str != '\0')
		return 1 + my_strlen(str + 1);
		// return 1 + my_strlen(++str); //��������ʹ�� ��Ȼ���� �����Ѿ��ı���str��ֵ
	else
		return 0;
}

// д�׳�  �����ķ�ʽ
int factorial(int x)
{
	if (x == 1)
		return 1;
	else
		return x * factorial(x-1);
}
// ��Щ���� �����õ���ʵ�� Ҳ�����õݹ�ʵ��

// ���n��쳲��������������������) - һ������ ǰ������֮�͵��ں�����
int Fibonacci_number()
{
	int n = 0;
	scanf("%d", &n);
	int ret = fib(n);
	printf("%d\n", ret);

	return 0;
}

int fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
