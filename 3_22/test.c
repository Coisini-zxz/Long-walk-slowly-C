#define _CRT_SECURE_NO_WARNINGS	1	// 放在开头 防止scanf报错
#include <stdio.h> 	

int main()
{
	printf("打印测试\n");
	printf("%d\n", 100); //打印一个整数 - %d
	// sizeof - 关键字 - 操作符 - 计算类型或者变量所占空间的大小 单位为byte
	// C语言标准 : sizeof(long) >= sizeof(int)
	printf("%d\n", sizeof(char));		//字符数据类型
	printf("%d\n", sizeof(short));		//短整型
	printf("%d\n", sizeof(int));		//整型
	printf("%d\n", sizeof(long));		//长整型
	printf("%d\n", sizeof(long long));	//更长整型
	printf("%d\n", sizeof(float));		//单精度浮点型
	printf("%d\n", sizeof(double));		//双精度浮点型
	variable();
	sum_ab();
	return 0;
}
int variable()
{
	int age = 21;
	double weight = 67.8;
	age = age + 1;
	weight = weight - 10;
	printf("年龄 : %d\n", age);
	printf("体重 : %lf\n", weight);
	return 0;
}
// %d int
// %f float
// %lf double

// scanf()输入函数 printf()输出函数
int sum_ab() 
{
	int a = 0;
	int b = 0;
	int sum;
	scanf("%d %d", &a, &b);
	sum = a + b;
	printf("sum = %d\n", sum);
	return 0;
}