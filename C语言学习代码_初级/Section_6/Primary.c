#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>


int main()
{
	// func1();
	// func3();
	// func4();
	func5();
	return 0;
}


//  指针类型的意义
int func1()
{
	// 1.
	int a = 0X11223344;
	// 16进制 - 0 1 2 3 4 5 6 7 8 9 a b c d e f
	// 11111111 - 后四位就已经 8+4+2+1 = 15 了 也就是f  ---> 一个十六进制位 就是四个 二进制位
	
	// 调试 - 内存 - 查看a的变化！
	
	// int* pa = &a;
	// *pa = 0;

	// char* pc = &a;
	// *pc = 0;
	// 忽略报错的话 调试中从内存看出 只有  11 变成了 00 

	// 2.
	int arr[10] = { 0 };
	int* p = &arr;
	char* pc = &arr;
	printf("%d\n", p);       // 925890088   
	printf("%d\n", p+1);   // 925890092    --- 差4 差出了一个整型 也就是四个字节
	printf("%d\n", pc);     // 925890088
	printf("%d\n", pc+1); // 925890089    --- 差1 差出了一个字符 也就是一个字节

	// 1.  指针类型决定了 :  指针解引用访问的权限有多大
	// 2.  指针类型决定了 :  指针走一步 能走多远 (步长)
	// eg:
	func2();
	return 0;
}

int func2()
{
	int arr[10] = { 0 };
	int* p = &arr;
	// char* p = &arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = 1;
	}
	return 0;
}

// 野指针 : 就是指针指向的位置是不可知的 

int func3()
{
	// 1. 非法访问内存
	// 这里的p 就是野指针
	// int* p;  // p是一个局部的指针变量 , 局部变量不初始化的话 默认是随机值！
	// *p = 20;

	// 2. 指针越界访问
	//int arr[10] = { 0 };
	//int* p = &arr;
	//int i = 0;
	//for (i = 0; i <= 10; i++)
	//{
	//	*p = i;
	//	p++;
	//}

	// 3. 指针指向的空间释放
	//int* p = test();
	//*p = 20;
	//return 0;
}

int* test()
{
	int a = 10;
	return &a;
}

/*
如何避免野指针？
1.  指针初始化  --- 不知道初始化为什么地址的时候 直接初始化为 NULL（不建议）
2. 小心指针越界 --- C语言本身是不会检查数组的越界行为的！ 
3. 指针指向空间释放即时置NULL --- 
4. 指针使用之前检查有效性
*/


// 指针运算
// 1.  指针 +- 整数   2. 指针-指针 3. 指针的关系运算

int func4() 
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d\n", &arr[9] - &arr[0]);
	// 指针-指针 得到的是 两个指针之前的元素个数

	char c[5];
	printf("%d\n", &arr[9] - &c[0]);
	// 看似得到了一个数 但是其实是不正确的
	// 指针相减的前提是： 两个指针指向同一块空间！ 
	return 0;
}


int func5()
{
	// int len = strlen("abc");
	int len = my_strlen("abc");  // 模拟实现strlen的功能
	printf("%d\n", len);
	return 0;
}

// 计数器方法
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


// 递归方法

//	指针相减方法
int my_strlen(char* str)
{
	char* start = str;
	while (*str != '\0')
	{
		str++;
	}
	return str - start;
}

// 指针的关系运算

int func6()
{
	float values[5];
	float* vp;
	for (vp = &values[5]; vp > &values[0];)
	{
		*--vp;
	}
	// 以下代码 与上面一样 但是不建议 这样做！！！！！虽然编译器可行 但是标准并不保证这样可行 ！
	
	//for (vp = &values[5-1]; vp >= &values[0];vp--)
	//{
	//	*vp;
	//}

	// C语言标准规定
	// 允许指向数组元素的指针与指向数组最后一个元素后面的内存位置的指针进行比较 但是不允许与指向第一个元素之前的那个内存位置的指针进行比较
	return 0;
}