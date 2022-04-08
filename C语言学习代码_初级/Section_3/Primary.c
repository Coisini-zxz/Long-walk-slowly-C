#define _CRT_SECURE_NO_WARNINGS	1	// 放在开头 防止scanf报错
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
	//// 模拟实现strlen()
	//// printf("%d\n", strlen(arr));
	//printf("%d\n", my_strlen(arr));
	
	Fibonacci_number();

	return 0;
}

// 函数返回类型的地方写成 void 表示函数不返回任何值， 也不需要返回值
/*
void Swap(int x, int y)  //传值调用
{
	int z = 0;
	z = x;
	x = y;
	y = z;
}
这个函数无法实现 调试查看原因 - x,y 的确被赋给了a,b的值 但是！ 他们的地址空间不一样！ 传入的参数只是拷贝的一份！
*/


void Swap(int* pa, int* pb)  // 传址调用
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
	printf("Sawp前为-%d,%d\n", a, b);
	Swap(&a, &b);
	printf("Sawp后为-%d,%d\n", a, b);
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


// 写一个函数，实现一个整形有序数组的二分查找
int Binary_eg()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int key = 7;
	// 找到返回下标 找不到返回-1

	int sz = sizeof(arr) / sizeof(arr[0]);
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// 不能把sz在函数里边算！！
	// 数组arr传参 实际传递的不是数组的本身 仅仅传过去了数组首元素的地址
	int ret = binary_search(arr, key, sz);
	if (-1 == ret)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了, 下标为 %d \n", ret);
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

// 函数的嵌套调用和链式访问

int nested_calls()
{
	char arr[20] = "hello";
	int ret = strlen(strcat(arr, "bit"));//这里介绍一下strlen函数
	printf("%d\n", ret);
	return 0;
}

int chain_access()
{
	printf("%d", printf("%d", printf("%d", 43)));
	//结果是啥？
	//注：printf函数的返回值是打印在屏幕上字符的个数
	// 4321
	return 0;
}

// 函数定义和声明

int func_Declaration()
{
	int a = 10;
	int b = 20;
	
	// 函数声明 - 告知有这个函数 (warning C4013: “xxxx”未定义；)
	// 可以先定义在使用 因为程序从上往下扫 如果func在下可以先声明 用来避免warning
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
函数声明：
1. 告诉编译器有一个函数叫什么，参数是什么，返回类型是什么。但是具体是不是存在，函数
声明决定不了。
2. 函数的声明一般出现在函数的使用之前。要满足先声明后使用。
3. 函数的声明一般要放在头文件中的
*/

// 当集成其他人的代码时
#include "sub.h"
int call_sub()
{
	int a = 10;
	int b = 6;
	int c = Sub(a, b);
	printf("%d\n", c);
	return 0;
}

// 递归!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
/*
什么是递归？
------------程序调用自身的编程技巧称为递归（ recursion）。
------------递归做为一种算法在程序设计语言中广泛应用。 一个过程或函数在其定义或说明中有直接或间接
调用自身的一种方法，它通常把一个大型复杂的问题层层转化为一个与原问题相似的规模较小的问题来求解
递归策略 只需少量的程序就可描述出解题过程所需要的多次重复计算，大大地减少了程序的代码量。

递归的主要思考方式在于：
------------把大事化小

递归的两个必要条件
------------存在限制条件，当满足这个限制条件的时候，递归便不再继续。 （跳出条件）
------------每次递归调用之后越来越接近这个限制条件 （逼近跳出条件）
------------同时考虑是否会栈溢出 （递归层次不能太深）
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

// 用递归写
int my_strlen(char* str)
{
	if (*str != '\0')
		return 1 + my_strlen(str + 1);
		// return 1 + my_strlen(++str); //不能这样使用 虽然可以 但是已经改变了str的值
	else
		return 0;
}

// 写阶乘  迭代的方式
int factorial(int x)
{
	if (x == 1)
		return 1;
	else
		return x * factorial(x-1);
}
// 有些功能 可以用迭代实现 也可以用递归实现

// 求第n个斐波那契数。（不考虑溢出) - 一个数列 前两个数之和等于后面数
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
