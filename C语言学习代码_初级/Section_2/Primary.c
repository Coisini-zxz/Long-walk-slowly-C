#define _CRT_SECURE_NO_WARNINGS	1	// ���ڿ�ͷ ��ֹscanf����
#include <stdio.h>
#include <string.h>


int main() 
{
    // cycle();
    // switch_learn_0();
    // switch_learn_1();
    switch_learn_2();
    return 0;
}

// forѭ�� 
// ע��else��ƥ�䣺else�Ǻ�����������ifƥ���  ��python��һ������(python����������)
int cycle()
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