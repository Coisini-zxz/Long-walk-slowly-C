#define _CRT_SECURE_NO_WARNINGS	1	// 放在开头 防止scanf报错
#include <stdio.h>
#include <string.h>

extern int pointer_1();
extern int pointer_2();
extern int pointer_3();
int main()
{
	// data_type();
	// Variable_types();
	// Variable_used();
	// g_val_s();
	// constant();
	// string();
	// Escape_character();
	// Select();
	// cycle();
	// Add(123, 456);
	// array();
	// operator();
	// arr_num();
	// Compl();
	// B_A_plusplus();
	// Type_cast();
	// Logical();
	// conditions();
	// Comma();
	// Keywords_typedef();
	// Keywords_static();
	// define_constant();
	// define_macro();
	// pointer_1();
	// pointer_2();
	// pointer_3();
	Structural_body();
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

// 循环语句
int cycle()
{
	printf("快速学习C语言入门\n");
	int line = 0;
	while (line <= 200)
	{
		line++;
		printf("我要继续努力敲代码\n");
	}
	if (line > 200)
		printf("好offer\n");
	return 0;
}

// 函数
int Add(int x, int y)
{
	int z = x + y;
	printf("%d\n", z);
	return z;
}

// 数组
int array()
{
	/*
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	......
	*/
	// 数组 - 一组同样类型的元素的集合
	int arr[4] = { 1,2,3,4 };
	char ch[5] = { 'a', 'b', 'c' }; // 创建 5个,但只给出三个 叫做 “不完全初始化” 剩余的默认为0. (注:单引号！！！跟python不一样)
	int i = 0;
	while (i <= 3)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	return 0;

}


// 初始操作符
int operator()
{
	int a = 9 / 2;
	float b = 9 / 2.0;
	int c = 9 % 2;
	printf("%d\n%f\n%d\n", a, b, c);
	int d = 2;
	int e = d << 1; //左移操作符 -- 移动的是二进制位
	printf("%d\n", e);

	int z = 1;
	printf("%d\n", !z); // 0表示假 非0表示真
	if (z)
	{
		// 如果a为真 执行
	}
	if (!z)
	{
		// 如果a为假 执行
	}

	return 0;
}

// 计算数组元素个数
int arr_num()
{
	// 每个元素占4byte / sizeof是操作符 不是函数
	int arr[10] = { 0 };
	printf("%d\n", sizeof(arr)); //40
	printf("%d\n", sizeof(arr[0])); //4
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", sz); //10
	return 0;
}

// 按位取反
int Compl()
{
	int a = 0;
	printf("%d\n", ~a);
	// 00000000000000000000000000000000 ---> 11111111111111111111111111111111(原码) --->10000000000000000000000000000000(反码)
	// ---> 10000000000000000000000000000001(补码) ---> 得到 -1
	// 二进制位取反：把所有二进制位取反	
	/*
	整数在内存中存储的是补码!!！
	正数的原码反码补码相同
	只针对负数！ 原码取反(符号位不变！)+1 得到补码
	eg：-1 ：原码：10000000000000000000000000000001  (第一位 1 表示符号 1为负号)
			 反码：11111111111111111111111111111110
			 补码：11111111111111111111111111111111

	*/
	return 0;
}

// 前置++/后置++
int B_A_plusplus()
{
	int a = 10;
	int b = ++a; //前置++  :  先++ 后使用
	printf("%d\n", b); // 11
	printf("%d\n", a); // 11

	int q = 10;
	int w = q++; // 后置++ : 先使用 后++
	printf("%d\n", w); // 10
	printf("%d\n", q); // 11


	// 不建议研究以下浪费时间研究的是错误的代码 不同编译器可能不同结果
	//int a = 1;
	//int b = (++a) + (++a) + (++a);
	//printf("%d\n", b);

	return 0;
}

// 强制类型转换 
int Type_cast()
{
	// 加入 (类型) 前缀即可	
	int a = (int)3.14;
	printf("%d\n", a);
	return 0;
}

// 逻辑操作符
int Logical()
{
	int a = 3;
	int b = 5;
	int c = a && b;  // 且
	// int c = a || b;  // 或

	printf("%d\n", c);
	return 0;
}

// 条件操作符(三目操作符)
/*
	exp1 ? exp2 : exp3
	exp1 成立, exp2计算 整个表达式结构是:exp2的结果
	exp1 不成立, exp3计算 整个表达式结构是:exp3的结果
*/
int conditions()
{
	int a = 0;
	int b = 3;
	int max = 0;

	//if (a > b)
	//	max = a;
	//else
	//	max = b;
	max = a > b ? a : b;

	printf("%d\n", max);

	return 0;
}


// 逗号表达式
int Comma()
{
	// 2，4+5，6
	int a = 0;
	int b = 3;
	int c = 5;
	int d = (a = b + 2, c = a - 4, b = c + 2);
	// 逗号表达式 是从左到右依次计算的 且整个表达式的结果是 最后一个表达式的结果
	printf("%d\n", d);
	return 0;
}

// typedef 关键字  - 顾名思义是类型定义，这里应该理解为类型重命名。
typedef unsigned int u_int;
int Keywords_typedef()
{
	unsigned int num = 100;
	u_int num1 = 200;
	printf("%d\n%d\n", num, num1);
	return 0;
}

// static 关键字 
/*
在C语言中：
static是用来修饰变量和函数的
1. 修饰局部变量 - 称为静态局部变量 - 改变了局部变量的生命周期(本质是更改了变量的存储类型)
2. 修饰全局变量 - 称为静态全局变量 - 看add.c
3. 修饰函数 - 称为静态函数         - 看add.c
*/
void test()
{
	// int a = 1;
	static int a = 1;
	a++;
	printf("%d\n", a);
}
int	Keywords_static()
{
	// eg1
	int i = 0;
	while (i < 10)
	{
		test();
		i++;
	}
	// eg2
	// printf("%d\n", g__val) // 即便使用extern声明变量也无法使用 看add.c

	// eg3
	//int a = 1;
	//int b = 3;
	//int c = Add_(a, b);
	//printf("%d\n", c);
	return 0;
}

//  #define 定义常量和宏
// define 是一个预处理指令 
// 1. define 定义符号
#define zzz 100
int define_constant()
{
	printf("%d\n", zzz);
	return 0;
}
// 2.define 定义宏 
// C语言中的“宏”即宏定义，是一种批量处理的称谓。
// 计算机科学里的宏是一种抽象事物，它根据一系列预定义的规则替换一定的文本模式，解释器或编译器在遇到宏时会自动进行这一模式替换。
#define ADD(X,Y) X+Y
// #define ADD(X,Y) ((X)+(Y))
int define_macro()
{
	printf("%d\n", ADD(2, 3)); // 5
	printf("%d\n", 4 * ADD(2, 3));// 11  ---> 4*2+3 替换的！！！ 妙啊！
	// 要想得到 20 要像 注释那样定义！！！
	return 0;
}


// 结构体


struct Stu
{
	char name[20];
	int age;
	double score;
};

int Structural_body()
{
	struct Stu s = { "张三", 20, 85.5 }; // 结构体的创建和初始化
	printf("1: %s %d %lf", s.name, s.age, s.score);

	struct Stu* ps = &s;
	// 解引用操作
	printf("2: %s %d %lf", (*ps).name, (*ps).age, (*ps).score);
	// 结构体指针 -> 成员变量名
	printf("3: %s %d %lf", ps->name, ps->age, ps->score);
	return 0;
}


