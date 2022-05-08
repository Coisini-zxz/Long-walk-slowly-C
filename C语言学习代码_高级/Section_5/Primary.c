#include <stdio.h>
#include <stdio.h>

/*

一.  为什么存在动态内存分配

我们已经掌握的内存开辟方式有：
int val = 20;//在栈空间上开辟四个字节
char arr[10] = {0};//在栈空间上开辟10个字节的连续空间

但是上述的开辟空间的方式有两个特点：
1. 空间开辟大小是固定的。
2. 数组在申明的时候，必须指定数组的长度，它所需要的内存在编译时分配。
但是对于空间的需求，不仅仅是上述的情况。有时候我们需要的空间大小在程序运行的时候才能知道，
那数组的编译时开辟空间的方式就不能满足了。
这时候就只能试试动态存开辟了
*/

/*
二.  动态内存函数的介绍
2.1 malloc和free

C语言提供了一个动态内存开辟的函数：
void* malloc (size_t size);
这个函数向内存申请一块连续可用的空间，并返回指向这块空间的指针。
如果开辟成功，则返回一个指向开辟好空间的指针。
如果开辟失败，则返回一个NULL指针，因此malloc的返回值一定要做检查。
返回值的类型是 void* ，所以malloc函数并不知道开辟空间的类型，具体在使用的时候使用者自己
来决定。
如果参数 size 为0，malloc的行为是标准是未定义的，取决于编译器

C语言提供了另外一个函数free，专门是用来做动态内存的释放和回收的，函数原型如下：
void free (void* ptr);
free函数用来释放动态开辟的内存。
如果参数 ptr 指向的空间不是动态开辟的，那free函数的行为是未定义的。
如果参数 ptr 是NULL指针，则函数什么事都不做。

malloc和free都声明在 stdlib.h 头文件中。
*/

int main()
{
	func0();
	func1();
	func2();
	func3();
	return 0;
}


//
//int func0()
//{
//	//代码1
//	int num = 0;
//	scanf("%d", &num);
//	int arr[num] = { 0 };
//	//代码2
//	int* ptr = NULL;
//	ptr = (int*)malloc(num * sizeof(int));
//	if (NULL != ptr)//判断ptr指针是否为空
//	{
//		int i = 0;
//		for (i = 0; i < num; i++)
//		{
//			*(ptr + i) = 0;
//		}
//	}
//	free(ptr);//释放ptr所指向的动态内存
//	ptr = NULL;//是否有必要？
//	return 0;
//}


/*
2.2 calloc
C语言还提供了一个函数叫 calloc ， calloc 函数也用来动态内存分配。原型如下：
void* calloc (size_t num, size_t size);

函数的功能是为 num 个大小为 size 的元素开辟一块空间，并且把空间的每个字节初始化为0。
与函数 malloc 的区别只在于 calloc 会在返回地址之前把申请的空间的每个字节初始化为全0。

所以如果我们对申请的内存空间的内容要求初始化，那么可以很方便的使用calloc函数来完成任务。
*/

int func1()
{
	int* p = (int*)calloc(10, sizeof(int));
	if (NULL != p)
	{
		//使用空间
	}
	free(p);
	p = NULL;
	return 0;
}


/*
2.3 realloc
realloc函数的出现让动态内存管理更加灵活。
有时会我们发现过去申请的空间太小了，有时候我们又会觉得申请的空间过大了，那为了合理的时
候内存，我们一定会对内存的大小做灵活的调整。那 realloc 函数就可以做到对动态开辟内存大小
的调整。
函数原型如下：
void* realloc (void* ptr, size_t size);

---> ptr 是要调整的内存地址
---> size 调整之后新大小
---> 返回值为调整之后的内存起始位置。
---> 这个函数调整原内存空间大小的基础上，还会将原来内存中的数据移动到 新 的空间。
---> realloc在调整内存空间的是存在两种情况：
														---> 情况1：原有空间之后有足够大的空间  : 要扩展内存就直接原有内存之后直接追加空间，原来空间的数据不发生变化
														---> 情况2：原有空间之后没有足够大的空间 : 原有空间之后没有足够多的空间时，扩展的方法是：在堆空间上另找一个合适大小
																																		的连续空间来使用。这样函数返回的是一个新的内存地址
*/


/*
忘记释放不再使用的动态开辟的空间会造成内存泄漏。
切记：
动态开辟的空间一定要释放，并且正确释放
*/
//
//int func2()
//{
//	int* ptr = (int*)malloc(100);
//	if (ptr != NULL)
//	{
//		//业务处理
//	}
//	else
//	{
//		exit(EXIT_FAILURE);
//	}
//	//扩展容量
//	//代码1
//	ptr = (int*)realloc(ptr, 1000);//这样可以吗？(如果申请失败会如何？)
//
//	//代码2
//	int* p = NULL;
//	p = realloc(ptr, 1000);
//	if (p != NULL)
//	{
//		ptr = p;
//	}
//	//业务处理
//	free(ptr);
//	return 0;
//}


// 常见的动态内存错误


// 3.1 对NULL指针的解引用操作
void test()
{
	int* p = (int*)malloc(1000000000);
	*p = 20;//如果p的值是NULL，就会有问题
	free(p);
	p = NULL;

	//  所以 需要对malloc的返回值 进行判断
}
// 3.2 对动态开辟空间的越界访问
//void test()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;//当i是10的时候越界访问
//	}
//	free(p);
//	p = NULL;
//}


// 3.3 对非动态开辟内存使用free释放
void test()
{
	int a = 10;
	int* p = &a;
	free(p);//ok?
}


// 3.4 使用free释放一块动态开辟内存的一部分
void test()
{
	int* p = (int*)malloc(100);
	p++;
	free(p);//p不再指向动态内存的起始位置
}


// 3.5 对同一块动态内存多次释放
void test()
{
	int* p = (int*)malloc(100);
	free(p);
	free(p);//重复释放
}


// 3.6 动态开辟内存忘记释放（内存泄漏）
void test()
{
	int* p = (int*)malloc(100);
	if (NULL != p)
	{
		*p = 20;
	}
}
int func3()
{
	test();
	while (1);
}
// 忘记释放不再使用的动态开辟的空间会造成内存泄漏。
//切记：
//动态开辟的空间一定要释放，并且正确释放

// 动态开辟的空间 两种回收方式
// 1.  主动释放
// 2.  程序结束

// 几个经典的笔试题

// 1.

//void GetMemory(char *p)
//{
// p = (char *)malloc(100);
//}
//void Test(void)
//{
// char *str = NULL;
// GetMemory(str);
// strcpy(str, "hello world");
// printf(str);
//}

/*
解题
str传给GetMemory函数的时候是值传递，所以GetMemory函数的形参p是str的一份临时拷贝。
在GetMemory函数内部动态申请空间的地址，存放在p中 ，不会影响外边str，所以当GetMemory函数返回之后，str依然是NULL。所以strcpy会失败。
当GetMemory函数返回之后，形参p销毁，使得动态开辟的100个字节存在内存泄漏。无法释放。
*/


// 2.
char* GetMemory(void)
{
	char p[] = "hello world";
	return p;
}
void Test(void)
{
	char* str = NULL;
	str = GetMemory();
	printf(str);
}
/*
解题
局部变量 函数结束已经被销毁
即便访问了这个地址 地址内内容已经被销毁或者覆盖
*/


// 3. 
void GetMemory(char** p, int num)
{
	*p = (char*)malloc(num);
}
void Test(void)
{
	char* str = NULL;
	GetMemory(&str, 100);
	strcpy(str, "hello");
	printf(str);
	//free(str);
	//str = NULL;
}

/*
解题 造成了内存泄露 
加上free注释那两行即可
*/

// 4.
void Test(void)
{
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
}

/*
解题
考点： free之后一定要置空
错解 :  提前free了 应该拿到后面
考点不在这里   free之后并不会将其置空 所以会进入if内 又给str内放字符 此时已经造成了非法访问 因为已经free掉了 
正解 : free 之后 置空
*/


/*
柔性数组
也许你从来没有听说过柔性数组（flexible array）这个概念，但是它确实是存在的。
C99 中，结构中的最后一个元素允许是未知大小的数组，这就叫做『柔性数组』成员。
*/

typedef struct st_type
{
	int i;
	int a[0];//柔性数组成员
}type_a;


/*
柔性数组的特点：
--结构中的柔性数组成员前面必须至少一个其他成员。
--sizeof 返回的这种结构大小不包括柔性数组的内存。
--包含柔性数组成员的结构用malloc ()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小


//code1
typedef struct st_type
{
 int i;
 int a[0];//柔性数组成员
}type_a;
printf("%d\n", sizeof(type_a));//输出的是4


//代码1
int i = 0;
type_a *p = (type_a*)malloc(sizeof(type_a)+100*sizeof(int));
//业务处理
p->i = 100;
for(i=0; i<100; i++)
{
 p->a[i] = i;
}
free(p);
*/


/*
柔性数组的优势
 
//代码2
typedef struct st_type
{
 int i;
 int *p_a;
}type_a;
type_a *p = (type_a *)malloc(sizeof(type_a));
p->i = 100;
p->p_a = (int *)malloc(p->i*sizeof(int));
//业务处理
for(i=0; i<100; i++)
{
 p->p_a[i] = i;
}
//释放空间
free(p->p_a);
p->p_a = NULL;
free(p);
p = NULL;


上述 代码1 和 代码2 可以完成同样的功能，
但是 方法1 的实现有两个好处：

第一个好处是：方便内存释放
如果我们的代码是在一个给别人用的函数中，你在里面做了二次内存分配，并把整个结构体返回给
用户。用户调用free可以释放结构体，但是用户并不知道这个结构体内的成员也需要free，所以你
不能指望用户来发现这个事。所以，如果我们把结构体的内存以及其成员要的内存一次性分配好
了，并返回给用户一个结构体指针，用户做一次free就可以把所有的内存也给释放掉。

第二个好处是：这样有利于访问速度.
连续的内存有益于提高访问速度，也有益于减少内存碎片。（其实，我个人觉得也没多高了，反正
你跑不了要用做偏移量的加法来寻址）
*/