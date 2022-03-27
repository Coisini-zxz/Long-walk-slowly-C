#include <stdio.h>

int pointer_1()
{
	int a = 10; // a在内存空间中分的空间 - 4Byte
	printf("%p\n", &a); // %p专门用来打印地址 &取地址 这里a的4个字节 每个字节都有地址 取出的是第一个字节的地址（较小的地址）!!!
	
	// pa 专门用来存放地址的， 在C语言中称为 指针变量!!!
	//  *  : 说明pa是指针变量
	// int : 说明pa执行的对象是int类型的
	int* pa = &a; 

	char ch = 'w';
	char* pc = &ch;

	// 指针变量能不能存储自身的地址呢？？？ 搁这套娃呢？
	// int* pa = &pa;
	return 0;
}

int pointer_2() 
{
	int a = 10;
	int* pa = &a;

	// * 解引用操作 *pa : 通过pa里面的地址找到a
	*pa = 20;
	printf("%d\n", a);
	// 指针变量是用来干嘛的？  是用来存放地址的 
	// 存放谁的地址？          存放其他变量的地址
	// 指针是有类型的！
	// 指针还能用来干嘛？ 首先就是存放地址 其次！ 可以通过解引用操作符 找到地址对应的对象  操作这个对象！
	return 0;
}


//指针变量的大小取决于地址的大小
//32位平台下地址是32个bit位（即4个字节）
//64位平台下地址是64个bit位（即8个字节）
int pointer_3()
{
	printf("%d\n", sizeof(char*));
	printf("%d\n", sizeof(short*));
	printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(double*));
	return 0;
}
