#define _CRT_SECURE_NO_WARNINGS	1	// 放在开头 防止scanf报错
#include <stdio.h> 	
#include <string.h>

int main()
{
	// data_type();
	// Variable_types();
	// Variable_used();
	// g_val_s();
	// constant();
	// string();
	// Escape_character();
	Select();
	return 0;

}


// 数据类型
int data_type()
{
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


// 变量类型  (局部变量优先原则)
int global = 2019;//全局变量
int Variable_types()
{
	int local = 2018;//局部变量
	//下面定义的global会不会有问题？
	int global = 2020;//局部变量
	printf("global = %d\n", global);
	return 0;
}


// 变量使用
int Variable_used()
{
	int a = 0;
	int b = 0;
	int sum;
	scanf("%d %d", &a, &b);
	sum = a + b;
	printf("sum = %d\n", sum);
	// scanf()输入函数 printf()输出函数
	return 0;
}


//声明变量
extern int g_val;
int g_val_s()
{
	printf("%d\n", g_val);
	return 0;
}


// 常量
#define MAX 10000
int constant()
{
	/*
	1.字面常量
	3.14;
	10;
	"abcdfw";
	*/

	/*
   2.const修饰的常变量
   int num = 10; //本身是变量
   num = 20;
   const int num = 10; // 此时num就叫常变量 - 具有常属性(不能被改变) 本质上还是变量只是const修饰后具有常属性
   num = 20;
   printf("num = %d\n", num); //20

   int arr1[10] = { 0 };
   int n = 10;
   int arr2[n] = { 0 }; // 此时 n 为变量 会报错
   const int n_ = 10;
   int arr2[n_] = { 0 }; // 此时 n_ 为常变量 但是n_的本质是变量所以在数组括号中无法进行使用!!!
   */

   /*
   3. #define 定义的标识符常量
   MAX = 222; Error 不能更改！
   int n = MAX;
   printf("n = %d\n", n);
   */

   // 4.枚举常量 (可以一一列举的常量) ：关键词enum
   // eg: 性别
	enum Sex
	{
		// 这种枚举类型变量的未来可能取值
		// MALE = 5 可以赋初值 默认为0！！！ 
		MALE,
		FAMALE,
		SECRET
	};
	// 注: 它们是有值的！
	printf("%d\n", MALE);   //0
	printf("%d\n", FAMALE); //1
	printf("%d\n", SECRET); //2

	enum Sex Zz = MALE; // 此时是枚举常量 只能是上面三个中的一个！

	return 0;
}


// 字符串
// VScode F10 调试 或者 
int string()
{
	// 字符数组 - 数组是一组相同类型的元素
	// char 字符数据类型 创建了一个 arr[]数组 []内不给内容会自动根据后面字符串生成
	char arr1[] = "abcde"; // 数组内有六个元素 因为 字符串结尾自动隐藏了\0 (字符串的结束标志)
	char arr2[] = { 'b', 'i', 't' };  // 这里会出现 其他东西因为没有结束标志
	char arr3[] = { 'b', 'i', 't', '\0' };  // 三者对比感受 \0 结尾作用
	printf("%s\n", arr1);
	printf("%s\n", arr2);
	printf("%s\n", arr3);
	// strlen() 求 字符串长度
	// 出现strlen未定义的警告 说明没有引用头文件
	strlen("abc"); //string length
	int len = strlen("abc");
	printf("%d\n", len);// 长度为3！ \0 只是结束标志 计算字符串长度时不计（但是求字符串数组会算\0）
	printf("%d\n", strlen(arr1)); // 5
	printf("%d\n", strlen(arr2)); // 随机值! 结尾不知道是什么 会一直寻找到 \0 才算结束！所以是随机值
	printf("%d\n", strlen(arr3)); // 3
	return 0;

}


// 转义字符
int Escape_character()
{
	printf("%d\n", strlen("abcdef"));
	// \62被解析成一个转义字符
	printf("%d\n", strlen("c:\test\628\test.c")); //结果为14  制表符算一个字符！ \ddd 而628不是八进制数！
	return 0;
}


// 选择语句
int Select()
{
	int input = 0;
	printf("你喜欢学数学吗！？（选择1 or 0）:>\n");
	scanf("%d", &input);
	if (input == 1)
	{
		printf("那你真棒\n");
	}
	else
	{
		printf("回家卖红薯！\n");
	}
	return 0;
}
