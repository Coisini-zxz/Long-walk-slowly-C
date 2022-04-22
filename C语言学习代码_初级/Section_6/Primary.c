#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
#include <assert.h>

int main()
{
	// func1();
	// func3();
	// func4();
	// func5();
	// func7();
	// func8();
	// func9();
	// func11();
	func12();
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

//  指针和数组

// 数组名是什么呢？
int func7()
{
	int arr[10] = { 0 };
	printf("%p\n", arr); //数组名是数组首元素的地址
	printf("%p\n", &arr[0]);  // 打印会发现 二者相同
	return 0;
}

int func8()
{
	int arr[10] = { 0 };
	int* p = &arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		// printf("%p  <==> %p\n", &arr[i], p + i);
		*(p + i) = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%p  <==> %p\n", &arr[i], p + i);
		printf("%d \n", arr[i]);
		printf("%d \n", *(p+i));
	}
	// 推导 --->
	//  arr[2] <==> *(arr+2) <==> *(p+2) <==> *(2+p) <==> *(2+arr) <==> 2[arr] ????妙啊！
	//  2[arr] <==> *(2+arr) 
	int arr_[5] = { 1,2,3,4,5 };
	printf("2[arr_]=%d <==> arr_[2]=%d\n", 2[arr_], arr_[2]);
	 
	// why? --->  :  []是一个操作符 2/arr 是他的两个操作数 交换位置一样
	// eg: a+b <==> b+a  +号也是操作符！

	// arr[2] 编译器最终会转换成 *(arr+2) p[2] 也最终会转换成 *(p+2)
	int* p_ = &arr_;
	printf("arr_[2] = %d\n", arr_[2]);
	printf("p_[2] = %d\n", p_[2]);

	return 0;
}

// 二级指针
int func9()
{
	int a = 10;
	int *pa = &a;  // pa 是一个指针  一级指针
	int **ppa = &pa; // pa 也是一个变量 . &pa 取出pa 在内存中的起始地址
	// 此时ppa 就是一个二级指针变量
	// int*** pppa = &ppa;  三级指针  ！ 在这套娃呢？？
	printf("%d\n" ,**ppa); // 10
	return 0;
}

// 指针数组
int func10()
{
	int arr[10];  // 整型数组  --- 存放整型的数组
	char ch[5];  // 字符数组  --- 存放的是字符
	// 指针数组 --- 存放指针的数组
	int *parr[10]; // 整型指针的数组
	char *pch[5]; // 字符指针的数组
	return 0;
}

struct SS
{
	char c;
	short b;
	double d;
};

// 结构体初阶
struct Stu
{
	// 类型
	int age;
	char name[20];
	char id[20];
	// 结构体的成员也可以是另一个结构体
	struct SS sb; 
}; // 分号不能丢！！！
// } s1,s2;  这样也是创建了两个结构体变量  
// 区别 ： s1, s2是全局变量 而下面的是局部变量

int func11()
{
	// 对象
	// 结构体变量初始化
	struct Stu s =
	{
		21,
		"Wxylkxy",
		"201940440003",
		{'w', 1,0}
	};
	// 注意 char类型需要 "" 
	// 访问结构体变量
	printf("%c\n", s.sb.c);
	printf("%s\n", s.name);
	struct Stu *ps = &s;
	printf("%c\n", (*ps).sb.c);
	printf("%c\n", ps->sb.c);
	return 0;
}

// 模拟实现strlen()
int func12()
{
	char arr[] = "Wxylkxyzz";
	// int len = strlen(arr);
	int len = MyStrlen(arr);
	printf("len = %d\n", len);
	return 0;
}

int MyStrlen(const char* str)
{
	assert(str != NULL);
	// assert(str);
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}










