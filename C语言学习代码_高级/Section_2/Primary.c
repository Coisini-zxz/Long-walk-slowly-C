#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
#include <math.h>
#include <assert.h>

int main()
{
	// func0(); //字符指针
    // practice0(); //题
	// func1(); //指针数组
	// func2(); //数组指针
	// func3();
	// func4(); // eg
	// func5(); // 一维数组传参
	// func6(); // 二维数组传参
    // practice0();   // 常量字符串
    // practice1();
    // practice2();   // 求Sn = a + aa + aaa +aaaa +aaaaa 前五项之和
    // practice3();  // 打印arr数组的内容(用指针)
    // practice4();  // 列出 某范围内的水仙花数
    // practice5();  // 逆序字符串内容 
    // func5();  // 一级指针传参
    // func6();  // 二级指针传参
    // func7(); // 函数指针
    // func8(); // 函数指针数组
    func9();

	return 0;
}

int func0()
{
    //char ch = 'w';
    //char* pc = &ch;
    //*pc = 'w';

    const char* pstr = "hello bit.";//这里是把一个字符串放到pstr指针变量里了吗？
    printf("%c\n", *pstr);
    printf("%s\n", pstr);
    // 本质是把字符串 hello bit.首字符的地址放到了pstr中

    return 0;
}


int practice0()
{
    char str1[] = "hello bit.";
    char str2[] = "hello bit.";
    const char* str3 = "hello bit.";
    const char* str4 = "hello bit.";
    if (str1 == str2)
        printf("str1 and str2 are same\n");
    else
        printf("str1 and str2 are not same\n");

    if (str3 == str4)
        printf("str3 and str4 are same\n");
    else
        printf("str3 and str4 are not same\n");

    return 0;
    //  12相同 34不同 
     /* 
     这里str3和str4指向的是一个同一个常量字符串。C / C++会把常量字符串存储到单独的一个内存区域，当
     几个指针。指向同一个字符串的时候，他们实际会指向同一块内存。但是用相同的常量字符串去初始化
     不同的数组的时候就会开辟出不同的内存块。所以str1和str2不同，str3和str4不同。
     */
}


int func1()
{
    // 指针数组 --- 数组中存放的是指针 (地址)
    // int* arr[3];  // 存放整形指针的数组
    //int a = 1;
    //int b = 2;
    //int c = 3;
    //int* arr[3] = { &a,&b,&c };
    //int i = 0;
    //for (i = 0; i < 3; i++)
    //{
    //    printf("%d\n", *(arr[i]));
    //}

    int a[5] = { 1,2,3,4,5 };
    int b[] = { 2, 3, 4, 5, 6 };
    int c[] = {3, 4, 5, 6, 7};
    int* arr[3] = { a, b,c };
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        int j = 0;
        for (j = 0; j < 5; j++)
        {
            // printf("%d ", *(arr[i] + j));
            printf("%d ", arr[i][j]);
        }
    }
    return 0;
}

// 数组指针
// 是一种指针 ---> 是指向数组的指针

int func2()
{
    int a = 10;
    int* pa = &a;
    char ch = 'w';
    char* pc = &ch;
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    // arr; // 数组名 是首元素的地址  - arr[0]的地址
    // &arr; // 取出数组的地址
    int (*parr)[10] = &arr; // 此时 parr就是一个数组指针 其中存放的数组的地址

    // eg:
    double* d[5];
    double* (*pd)[5];
    return 0;
}

int func3()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    //printf("%p\n", arr);
    //printf("%p\n", &arr);
    // 上面 虽然输出一样 但是意义不一样

    // 这里也是 虽然输出一样 但是意义不一样
    int* p1 = arr;
    int (*p2)[10] = &arr;
    printf("%p\n", p1);      // 000000E7ACBAF968   差了 4 即 一个整形
    printf("%p\n", p1+1);  // 000000E7ACBAF96C  
    printf("%p\n", p2);      // 000000E7ACBAF968
    printf("%p\n", p2+1);  // 000000E7ACBAF990    差了 16进制的28 即 10进制 的40 即一个数组的长度 

    // 其实(*p2) 此时就是数组名
    // 不建议以下写法
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", (*p2)[i]);
        // printf("%d\n", *((*p2)+i));
    }
    return 0;
}

/*
数组名是数组首元素的地址
但是有两个例外
1. sizeof(数组名)   -  数组名表示整个数组， 计算的是整个数组的大小 单位是字节
2. &数组名  -  数组名表示整个数组， 取出的是整个数组的地址
*/

int func4()
{
    int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6}, {3,4,5,6,7} };
    // 原来的方式
    //void print1(int arr[3][5], int r, int c);
    //print1(arr, 3, 5);

    // 利用数组指针
    void print2(int(*p)[5], int r, int c);
    print2(arr, 3, 5);
    return 0;
}

void print1(int arr[3][5], int r, int c)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// p 是一个数组指针
// 二维数组的数组名表示 首元素的地址；
// 二维数组的首元素是谁呢？ ---> 是第一行
void print2(int (*p)[5], int r, int c)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
}


/*
* 
int (*parr2)[10];  -  数组指针  指向一个数组 数组十个元素 每个元素的类型是int
int (*parr3[10])[5];  -  是一个 存储数组指针的数组 该数组能够存放10个数组指针 每个数组指针 能够指向一个数组 数组五个元素 每个元素是int类型
parr3[10] 首先是一个数组  假设先拿掉 , int (*   )[5] 是一个数组指针 指向了一个数组 数组内每个元素类型都是int
再把 这个数组指针存入 parr3[10] 这个数组 
parr3[10] 十个元素 每个元素就是一个数组指针
*/


// 一维数组传参 
//
//void test(int arr[])            //ok?  ✔
//{}
//void test(int arr[10])        //ok? ✔
//{}
//void test(int* arr)             //ok? ✔
//{}
//void test2(int* arr[20])     //ok? ✔
//{}
//void test2(int** arr)          //ok? ✔
//{}
//
//int func5()
//{
//    int arr[10] = { 0 };       // 整形数组 - 存放十个整形元素
//    int* arr2[20] = { 0 };    // 整形指针数组 - 存放二十个整形指针(int*)元素
//    test(arr);
//    test2(arr2);
//
//    // p204
//    /*
//    arr2 数组名表示首元素的地址  也就是 *int 的地址 而 &(*int) 就是 **int 啊！
//    [*int, *int, *int, *int, ~~~~ ]
//    */
//}
//
//// 二维数组传参
//void test(int arr[3][5])    //ok？ ✔
//{}
////void test(int arr[][])        //ok？❌
////{}
//void test(int arr[][5])      //ok？✔
//{}
////总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
////因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。
////这样才方便运算。
//void test(int* arr)         //ok？❌
//{}
//void test(int* arr[5])     //ok？❌
//{}
//void test(int(*arr)[5])   //ok？✔  指针 - 指向 含有五个整形元素的数组
//{}
//void test(int** arr)       //ok？❌
//{}
//int func6()
//{
//    int arr[3][5] = { 0 };
//    test(arr);
//}

// practice

int practice1()
{
    int i=0;   // 不初始化变量 默认是0
    i--;
    if(i > sizeof(i))   // sizeof操作符 结果类型是 unsigned int 类型 
    {
        printf(">\n");
    }
    else
    {
        printf("<\n");
    }
    return 0;
    /*
    有符号整型跟无符号整型比较时  会把无符号整型 解读成有符号整型再比较
    -1 : 10000000000000000000000000000001 ---> 11111111111111111111111111111110 ---> 11111111111111111111111111111111
    所以必然大于4
    */
}


// 求Sn = a + aa + aaa +aaaa +aaaaa 前五项之和
// eg 2 + 22 + 222 + 2222 + 22222
int practice2()
{
    int a = 0;
    int n = 0;
    scanf("%d %d", &a, &n);
    int i = 0;
    int sum = 0;
    int ret = 0;
    for (i = 0; i < n; i++)
    {
        ret = ret * 10 + a;
        sum = sum+ret;
    }
    printf("sum = %d\n", sum);
    return 0;
}

// 写一个函数 打印arr数组的内容  不使用数组下标  使用指针
// arr 是一个整型一维数组
int practice3()
{
    int arr[] = { 1,5,7,3,4 };
    int* pa = &arr;
    int sz = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    // (1)
    //for (i = 0; i < sz; i++)
    //{
    //    printf("%d ", *(pa+i));
    //}
    // (2)
    int* pd = arr + sz - 1;
    while (pa <= pd)
    {
        printf("%d ", *pa);
        pa++;
    }
    return 0;
}

// 求出 0~100000之间的所有 "水仙花数" 并输出
// "水仙花数" 是指一个n位数， 其各位数字的n次方之和 确好等于该数本身
// eg:  153 = 1^3 + 5^3 + 3^3 则153是一个 "水仙花数"
int practice4()
{
    int  i = 0;
    for (i = 0; i < 100000; i++)
    {
        // 判断i是否为自幂数
        // 1. 计算i的位数
        // 2. 计算i的每一位的n次方之和
        // 3.  判断
        int n = 1;
        int tmp = i;
        while (tmp / 10)
        {
            n++;
            tmp = tmp / 10;
        }

        tmp = i;
        int sum = 0;
        while (tmp)
        {
            sum += pow(tmp % 10, n);
            tmp = tmp / 10;
        }
        if (sum == i)
        {
            printf("%d ", i);
        }
    }
    return 0;
}

// 写一个函数 可以逆序一个字符串的内容
int practice5()
{
    char arr[] = "abcdefg"; // gfedcba
    // char* arr = "abcdef";  这种写法是错误的！ 常量字符串不能更改
    void reverse(char* str);
    reverse(arr);
    printf("%s\n", arr);
    return 0;
}

void reverse(char*  str)
{
    assert(str != NULL);
    int len = strlen(str) - 1;
    char* left = str;
    char* right = str+len-1;
    while (left<right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}


 // 一级指针传参
int func5()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    int* p = arr;
    int sz = sizeof(arr) / sizeof(arr[0]);
    // p 此时是一级指针
    void print3(int* , int);
    print3(p, sz);
    return 0;
}

void print3(int* p, int sz)
{
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", *(p + i));
    }
    return 0;
}

/*
思考：
当一个函数的参数部分为一级指针的时候，函数能接收什么参数？

void test1(int* p)
{
}
int egg()
{
    int i = 0;
    test1(&i);
    return 0;
}
*/


// 二级指针传参
int func6()
{
    int a = 10;
    int* pa = &a;  // pa 一级指针
    int** ppa = &pa; // ppa 二级指针
    // 二级指针传参
    void func6_test(int**);
    func6_test(ppa);
    printf("%d\n", a); // 20


    //// 对应思考
    //// 1.
    //func6_test(&pa); // 传一级指针变量的地址
    //// 2.
    //int* arr[10] = { 0 };  // 传存放一级指针的数组
    //func6_test(arr); 
    // //arr是指针数组 arr名又是首元素地址 不就是int**吗


    return 0;
}
void  func6_test(int** p2)
{
    **p2 = 20;
}

/*
思考：
当函数的参数为二级指针的时候，可以接收什么参数？
p437
*/

// 函数指针 - 存放函数地址的指针

int func7()
{
    int a = 10;
    int* pa = &a;

    char ch = 'W';
    char pch = &ch;

    int arr[10] = { 0 };
    int (* parr)[10] = &arr;

    // 函数指针 --- &函数名  ---  取到的就是函数的地址
    int Add(int, int);
    printf("%p\n", &Add);
    printf("%p\n", Add);
    // 此时 &Add跟Add 不仅值一样  且 意义也一样  跟数组那里不一样了！
     int (* pf)(int, int ) = &Add;
     // int (* pf)(int, int ) = Add;
     // pf 就是函数指针变量

     // eg 练习书写
     void func7_test(char*);
     void (* pf7)(char *) = &func7_test;

     // 如何使用呢？
     int ret1 = (*pf)(3, 5);
     int (*pf1)(int, int) = Add;  // 分析 如果能把Add的地址放到pf里 是不是说明 pf跟Add 等价?
     int ret2 = Add(3, 5);
     int ret3 = pf1(3, 5);
     printf("%d\n", ret1);  // 8 
     printf("%d\n", ret2);  // 8 
     printf("%d\n", ret3);  // 8 
     // 你会发现 ？ 离谱
     // 其实 p487的* 是个摆设 只是帮助我们理解 你写什么都行
     int ret4 = (****pf1)(3, 5);
     printf("%d\n", ret4);  // 8 
     
     // 但是 这样不行
     // int ret5 = *pf(3, 5);  这样=*8
     // 必须加括号
    return 0;
}
int Add(int x, int y)
{
    return x + y;
}

void func7_test(char* str)
{
}

/*
 阅读两段有趣的代码：
 
代码1
 (*(void (*)())0)();
 答案:  调用0地址处的函数 该函数无参, 返回类型是void
 解读：
 1. void (*)() - 函数指针类型 
 2. (void (*)()) 0 - 强制类型转换 {跟(char*) 0 是的} ， 被解释为一个函数地址
 3. *(void (*)()) 0 - 对0地址进行了解引用操作
 4. (*(void (*)())0)(); - 调用 0 地址出的函数

代码2
void (*signal(int, void(*)(int)))(int); 
 自己做的时候 思路
 x = int, void(*)(int)
 void(*y) (int) --- 函数指针
 y = signal(int, 一个函数指针)
 答案:  signal是一个函数的声明
 解读
 1. signal先和()结合  说明signal是个函数名
 2. signal函数的参数 第一个参数类型是int  第二个函数类型是函数指针 --- 而函数指针 指向一个参数为int 返回类型为void的函数
 3. signal函数的返回类型 也是一个函数指针 --- 该指针类型 指向了一个参数为int 返回类型为void的函数
  signal是一个函数的声明
 
 简化
 1. 法一
 这样写更容易理解
 void (*)int signal(int, void(*)(int)) 
void (*)int // 返回类型  = x
 int, void(*)(int) 参数类型  = z c
 x signal(z, c) 函数声明
 但是 规定不允许这样写
 必须写成下面这样
void (*signal(int, void(*)(int)))(int);

 2. 法二
 typedef - 对类型进行重定义
 eg: typedef unsigned int uint;
typedef void(*pfun_t)(int); // 对void(*)(int) 的函数指针类型 重命名为 pfun_t
pfun_t signal(int, pfun_t);

*/

// 函数指针数组
/*
整型指针 : int* 
整型指针数组 : int* arr[5]

函数指针数组 : 存放函数指针的数组（同类型）
*/
int Sub(int x, int y)
{
    return x - y;
}
int func8()
{
    int (*pf1)(int, int) = Add;
    int (*pf2)(int, int) = Sub;
    int (*pfArr[2])(int, int) = { Add, Sub }; //pfArr 就是一个函数指针数组
}

int Mul(int x, int y)
{
    return x * y;
}
int Div(int x, int y)
{
    return x / y;
}
// 用处呢 到底有啥用这样
int func9()
{
    void meau();
    int input = 0;
    // 计算器 - 计算整型变量的加减乘除
    do {
        meau();
        int x = 0;
        int y = 0;
        int ret = 0;
        printf("请选择>: ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("请输入两个操作数>:");
            scanf("%d %d", &x, &y);
            ret = Add(x, y);
            printf("ret= %d\n", ret);
            break;
        case 2:
            printf("请输入两个操作数>:");
            scanf("%d %d", &x, &y);
            ret = Sub(x, y);
            printf("ret= %d\n", ret);
            break;
        case 3:
            printf("请输入两个操作数>:");
            scanf("%d %d", &x, &y);
            ret = Mul(x, y);
            printf("ret= %d\n", ret);
            break;
        case 4:
            printf("请输入两个操作数>:");
            scanf("%d %d", &x, &y);
            ret = Div(x, y);
            printf("ret= %d\n", ret);
            break;
        case 0:
            printf("退出程序\n");
            break;
        default:
            printf("选择错误 请重新选择");
            break;
        }
    } while (input);

    return 0;
}

void meau()
{
    printf("--------------------------------------\n");
    printf("--------------------------------------\n");
    printf("------1. Add    2. Sub ---------------\n");
    printf("------3. Mul    4. Div  ---------------\n");
    printf("-----------0. Exit---------------------\n");
    printf("--------------------------------------\n");
}
// 当你不只需要加减乘除时 需要的更多时 总不能一直写case吧？
// 这时候就用到的 函数指针数组