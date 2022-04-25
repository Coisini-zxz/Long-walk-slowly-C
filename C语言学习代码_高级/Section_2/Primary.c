#include <stdio.h>

int main()
{
	// func0(); //字符指针
    // practice0(); //题
	func1(); //指针数组
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