#include <stdio.h>

int main()
{
	func1(); // Release版本会对代码优化以及越界访问造成的问题
	return 0;
}


// Release版本是如何优化的呢？
int func1()
{
	//int i = 0;
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//for (i = 0; i <= 12; i++)
	//{
	//	arr[i] = 0;
	//	printf("Az\n");

	//}
	// 以上 会报错(或者产生死循环(不同ide不同)) 因为什么呢？
	/*
	i, arr 是局部变量 ---> 局部变量是放在栈区上的
	---> 而栈区的使用习惯是先用高地址再用低地址
	---> 数组随之下标的增长 地址是由低到高变化的
	看ppt的图 理解
	*/
	// 如果使用 Release 不会报错或者死循环
	int i = 0;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	// 查看 debug跟release版本 下的区别
	printf("%p\n", &i);
	printf("%p\n", &arr[2]);
	return 0;
}

