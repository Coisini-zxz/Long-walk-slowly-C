// C语言是从主函数的第一行开始执行的
// 1. 一个工程可以有多个.c文件 但是只能有一个main函数
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
	return 0;
}
