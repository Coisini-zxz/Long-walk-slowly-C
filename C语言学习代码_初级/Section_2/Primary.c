#define _CRT_SECURE_NO_WARNINGS	1	// ���ڿ�ͷ ��ֹscanf����
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

// forѭ�� 
// ע��else��ƥ�䣺else�Ǻ�����������ifƥ���  ��python��һ������(python����������)
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
        printf("����1\n");
        break;
    case 2:
        printf("����2\n");
        break;
    case 3:
        printf("����3\n");
        break;
    case 4:
        printf("����4\n");
        break;
    case 5:
        printf("����5\n");
        break;
    case 6:
        printf("����6\n");
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
            printf("�������� ����������");
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
        {//switch����Ƕ��ʹ��
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
    printf("����������:> ");
    scanf("%s", password);
    printf("��ȷ������(Y/n):>");
    // getchar()������������� scanf()��getchar()���Ǵӻ������ö��� ����scanf()�����û��з� �һ����������ߺ�����ǰ��
    // ���������еĶ���ַ�
    int tmp = 0;
    while ((tmp = getchar()) != '\n')
    {
        ; //ʲô������
    }
    // Ϊʲôgetchar()������ ��Ϊ�ַ�ʹ��ascll��洢��
    int ch = getchar();
    if (ch == 'Y')
    {
        printf("ȷ�ϳɹ�\n");
    }
    else
    {
        printf("ȷ��ʧ��\n");
    };
    return 0;
}


//EOF - end of file �ļ�������־
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
�����ѭ����pythonһ�� ����break��continue������ 

����

1. ������for ѭ�������޸�ѭ����������ֹ for ѭ��ʧȥ���ơ�
2. ����for����ѭ�����Ʊ�����ȡֵ���á�ǰ�պ����䡱д����
*/

int for_while()
{
    int i = 0;
    // for(i = 1;/*��ʼ��*/ i<=10;/*�ж�����*/ i++/*��������*/)
    // for(;;) ������ʡ�� �����ж�����ʡ�Ծ͵���������Ϊ�� ��while(1)һ����
    for (i = 1; i <= 10; i++)
    {
        printf("%d\n", i);
    }
    return 0;
}


// ���� �״� �ж�һ����ӡ�˼���hehe!!
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
// ����Ϊ�Ŵ� ��ʵ������!!! jû�б���ʼ������ 
// ������� ѭ���˼����أ�
int for_error_1()
{
    int i = 0;
    int k = 0;
    for (i = 0, k = 0; k = 0; i++, k++)
        k++;
    return 0;
}

// û��ѭ�� k=0! ���Ǽ� ֻ��һ��=  �Ǹ�ֵ��   

// do_while ѭ�� �ص㣻����ִ��һ��
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

// ��ϰ��
// 1. ��һ�����������в��Ҿ����ĳ������n (���ַ�)
int bin_search(int arr[], int left, int right, int key)
{
    int mid = 0;      // ����mid
    while (left <= right) // ��ѭ�� ֱ���ҵ�Ȼ��return
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
            return mid;//�ҵ��ˣ������±�
    }
    return -1;//�Ҳ���
}














