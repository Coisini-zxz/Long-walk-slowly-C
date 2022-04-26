#include <stdio.h>

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

void test(int arr[])            //ok?  ✔
{}
void test(int arr[10])        //ok? ✔
{}
void test(int* arr)             //ok? ✔
{}
void test2(int* arr[20])     //ok? ✔
{}
void test2(int** arr)          //ok? ✔
{}

int func5()
{
    int arr[10] = { 0 };       // 整形数组 - 存放十个整形元素
    int* arr2[20] = { 0 };    // 整形指针数组 - 存放二十个整形指针(int*)元素
    test(arr);
    test2(arr2);

    // p204
    /*
    arr2 数组名表示首元素的地址  也就是 *int 的地址 而 &(*int) 就是 **int 啊！
    [*int, *int, *int, *int, ~~~~ ]
    */
}

// 二维数组传参
void test(int arr[3][5])    //ok？ ✔
{}
void test(int arr[][])        //ok？❌
{}
void test(int arr[][5])      //ok？✔
{}
//总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
//因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。
//这样才方便运算。
void test(int* arr)         //ok？❌
{}
void test(int* arr[5])     //ok？❌
{}
void test(int(*arr)[5])   //ok？✔  指针 - 指向 含有五个整形元素的数组
{}
void test(int** arr)       //ok？❌
{}
int func6()
{
    int arr[3][5] = { 0 };
    test(arr);
}