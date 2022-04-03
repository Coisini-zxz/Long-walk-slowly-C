#define _CRT_SECURE_NO_WARNINGS	1	// 放在开头 防止scanf报错
#include <stdio.h>
#include <string.h>


int main() 
{
    // for_cycle();
    // switch_learn_0();
    // switch_learn_1();
    // switch_learn_2();
    // while_cycle_0();
    // while_cycle_1();
    // gpchar();
    // for_while();
    // for_error_0();
    // for_error_1();
    int a = bin_search({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 0, 9, 2);
    printf("%d\n", a);
    return 0;
}

// for循环 
// 注：else的匹配：else是和它离的最近的if匹配的  跟python不一样我淦(python有缩进符！)
int for_cycle()
{
    int a = 0;
    int b = 2;
    if (a == 1)
    {
        if (b == 2)
        {
            printf("hehe\n");
        }
    }
    else
    {
        printf("haha\n");
    }
    return 0;
}

int switch_learn_0()
{
    int day = 0;
    scanf("%d", &day);
    switch (day)
    {
    case 1:
        printf("星期1\n");
        break;
    case 2:
        printf("星期2\n");
        break;
    case 3:
        printf("星期3\n");
        break;
    case 4:
        printf("星期4\n");
        break;
    case 5:
        printf("星期5\n");
        break;
    case 6:
        printf("星期6\n");
        break;
    }
    return 0;
}


int switch_learn_1()
{
    int day = 0;
    switch (day)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("weekday\n");
            break;
        case 6:
        case 7:
            printf("weekend\n");
            break;
        default:
            printf("输入有误！ 请重新输入");
            break;
    }
    return 0;
}


int switch_learn_2()
{
    int n = 1;
    int m = 2;
    switch (n)
    {
    case 1:
        m++;  // m=3
    case 2:
        n++;  // n=2
    case 3:
        switch (n) 
        {//switch允许嵌套使用
        case 1:
            n++;
        case 2: 
            m++; // 4
            n++; // 3
            break;
        }
    case 4:
        m++; // m =5
        break;
    default:
        break;
    }
    printf("m = %d, n = %d\n", m, n);
    return 0;
}

int gpchar()
{
    char password[20] = { 0 };
    printf("请输入密码:> ");
    scanf("%s", password);
    printf("请确认密码(Y/n):>");
    // getchar()可以清除缓冲区 scanf()跟getchar()都是从缓冲区拿东西 但是scanf()不会拿换行符 且缓冲区被拿走后数据前顶
    // 清理缓冲区中的多个字符
    int tmp = 0;
    while ((tmp = getchar()) != '\n')
    {
        ; //什么都不做
    }
    // 为什么getchar()用整型 因为字符使用ascll码存储的
    int ch = getchar();
    if (ch == 'Y')
    {
        printf("确认成功\n");
    }
    else
    {
        printf("确认失败\n");
    };
    return 0;
}


//EOF - end of file 文件结束标志
int while_cycle_0()
{
    int ch = 0;
    while ((ch = getchar()) != EOF)
        putchar(ch);
    return 0;
}

int while_cycle_1()
{
    char ch = '0';
    while ((ch = getchar()) != EOF)
    {
        if (ch < '0' || ch > '9')
            continue;
        putchar(ch);
    }
    return 0;
}
/*
这里的循环跟python一样 包括break跟continue的作用 

建议

1. 不可在for 循环体内修改循环变量，防止 for 循环失去控制。
2. 建议for语句的循环控制变量的取值采用“前闭后开区间”写法。
*/

int for_while()
{
    int i = 0;
    // for(i = 1;/*初始化*/ i<=10;/*判断条件*/ i++/*调整部分*/)
    // for(;;) 都可以省略 但是判断条件省略就等于条件恒为真 跟while(1)一样了
    for (i = 1; i <= 10; i++)
    {
        printf("%d\n", i);
    }
    return 0;
}


// 我淦 易错 判断一共打印了几次hehe!!
int for_error_0()
{
    int i = 0;
    int j = 0;
    for (; i < 3; i++)
    {
        for (; j < 3; j++)
        {
            printf("hehe\n");
        }
    }
    return 0;
}
// 我以为九次 其实是三次!!! j没有被初始化！！ 
// 下面这个 循环了几次呢？
int for_error_1()
{
    int i = 0;
    int k = 0;
    for (i = 0, k = 0; k = 0; i++, k++)
        k++;
    return 0;
}

// 没有循环 k=0! 这是假 只有一个=  是赋值！   

// do_while 循环 特点；至少执行一次
int do_while()
{
    int i = 10;

    do
    {
        if (5 == i)
            break;
        printf("%d\n", i);
    } while (i < 10);

    return 0;
}

// 练习题
// 1. 在一个有序数组中查找具体的某个数字n (二分法)
int bin_search(int arr[], int left, int right, int key)
{
    int mid = 0;      // 定义mid
    while (left <= right) // 大循环 直到找到然后return
    {
        mid = (left + right) >> 1;  //
        if (arr[mid] > key)
        {
            right = mid - 1;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
            return mid;//找到了，返回下标
    }
    return -1;//找不到
}














