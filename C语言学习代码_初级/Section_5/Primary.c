#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>

int main()
{
	// Arithmetic_operator(); 
	// shift_operator();
	Bitwise_operator();
	return 0;
}

int Arithmetic_operator()
{
	// 算数操作符
	int a1 = 1 / 2; 
	printf("%d\n", a1);		// 0

	int a2 = 7 / 6;
	printf("%d\n", a2);		// 1

	float a3 = 7 / 6;
	printf("%f\n", a3);		// 1.000000

	float a4 = 7.0 / 6;
	printf("%f\n", a4);		// 1.166667

	int a5 = 5 % 2;
	printf("%d\n", a5);		// 1
	return 0;
	/*
	1. 除了 % 操作符之外，其他的几个操作符可以作用于整数和浮点数。
	2. 对于 / 操作符如果两个操作数都为整数，执行整数除法。而只要有浮点数执行的就是浮点数除法。
	3. % 操作符的两个操作数必须为整数。返回的是整除之后的余数。
	*/
}

int shift_operator()
{
	// 注：移位操作符的操作数只能是整数
	// 左移 右移 都不会改变a
	int a = 2;
	int b = a << 1;				// a的二进制向左移动一位 后面补0 
	printf("b = %d\n", b);

	// 右移操作符
	//                  --- 1. 算数右移 -> 右移丢弃 左边补符号位 
	//					 --- 2. 逻辑右移 -> 右移丢弃 左边补0
	int z = -1;
	// 当前右移操作符 使用的是 算数右移
	int c = z >> 1;				// a的二进制向左移动一位 后面补0
	printf("c = %d\n", c);
	return 0;
}

int Bitwise_operator()
{
	// 注：他们的操作数必须是整数 
	int a = 3;			// 00000000000000000000000000000011
	int b = 5;			// 00000000000000000000000000000101

	// 1.  &  -> 按位与 (二进制位)
	int c = a & b;  // 00000000000000000000000000000001 (按位对比 有0就为0 除非都不为0）
	printf("c = %d\n", c); // 1

	// 2.  |  -> 按位或
	int d = a | b;		// 00000000000000000000000000000111
	printf("d = %d\n", d); // 7

	// 3. ^  -> 按位异或 (相同为0 相异为1)
	int e = a ^ b;	// 00000000000000000000000000000110
	printf("e = %d\n", e); // 6

	// eg - 交换两个变量的值 且不能创建第三个变量
	int i = 4;
	int t = 6;
	printf("i = %d,t = %d\n", i, t);
	i = i ^ t;  //   i = i^t
	t = i ^ t;  //  t = i^t^t  = i
	i = i ^ t;  //   i = i^t^i^t^t = t
	//  妙蛙种子吃了妙脆角妙到家了！
	printf("i = %d,t = %d\n", i, t);

	// a ^ a = 0; 
	// 0 ^ a = a;
	return 0;
}