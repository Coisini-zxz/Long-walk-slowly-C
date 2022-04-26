#include <stdio.h>

int main()
{
	// func0(); //�ַ�ָ��
    // practice0(); //��
	// func1(); //ָ������
	// func2(); //����ָ��
	// func3();
	func4(); // eg
	return 0;
}

int func0()
{
    //char ch = 'w';
    //char* pc = &ch;
    //*pc = 'w';

    const char* pstr = "hello bit.";//�����ǰ�һ���ַ����ŵ�pstrָ�����������
    printf("%c\n", *pstr);
    printf("%s\n", pstr);
    // �����ǰ��ַ��� hello bit.���ַ��ĵ�ַ�ŵ���pstr��

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
    //  12��ͬ 34��ͬ 
     /* 
     ����str3��str4ָ�����һ��ͬһ�������ַ�����C / C++��ѳ����ַ����洢��������һ���ڴ����򣬵�
     ����ָ�롣ָ��ͬһ���ַ�����ʱ������ʵ�ʻ�ָ��ͬһ���ڴ档��������ͬ�ĳ����ַ���ȥ��ʼ��
     ��ͬ�������ʱ��ͻῪ�ٳ���ͬ���ڴ�顣����str1��str2��ͬ��str3��str4��ͬ��
     */
}


int func1()
{
    // ָ������ --- �����д�ŵ���ָ�� (��ַ)
    // int* arr[3];  // �������ָ�������
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

// ����ָ��
// ��һ��ָ�� ---> ��ָ�������ָ��

int func2()
{
    int a = 10;
    int* pa = &a;
    char ch = 'w';
    char* pc = &ch;
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    // arr; // ������ ����Ԫ�صĵ�ַ  - arr[0]�ĵ�ַ
    // &arr; // ȡ������ĵ�ַ
    int (*parr)[10] = &arr; // ��ʱ parr����һ������ָ�� ���д�ŵ�����ĵ�ַ

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
    // ���� ��Ȼ���һ�� �������岻һ��

    // ����Ҳ�� ��Ȼ���һ�� �������岻һ��
    int* p1 = arr;
    int (*p2)[10] = &arr;
    printf("%p\n", p1);      // 000000E7ACBAF968   ���� 4 �� һ������
    printf("%p\n", p1+1);  // 000000E7ACBAF96C  
    printf("%p\n", p2);      // 000000E7ACBAF968
    printf("%p\n", p2+1);  // 000000E7ACBAF990    ���� 16���Ƶ�28 �� 10���� ��40 ��һ������ĳ��� 

    // ��ʵ(*p2) ��ʱ����������
    // ����������д��
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", (*p2)[i]);
        // printf("%d\n", *((*p2)+i));
    }
    return 0;
}

/*
��������������Ԫ�صĵ�ַ
��������������
1. sizeof(������)   -  ��������ʾ�������飬 ���������������Ĵ�С ��λ���ֽ�
2. &������  -  ��������ʾ�������飬 ȡ��������������ĵ�ַ
*/

int func4()
{
    int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6}, {3,4,5,6,7} };
    // ԭ���ķ�ʽ
    //void print1(int arr[3][5], int r, int c);
    //print1(arr, 3, 5);

    // ��������ָ��
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

// p ��һ������ָ��
// ��ά�������������ʾ ��Ԫ�صĵ�ַ��
// ��ά�������Ԫ����˭�أ� ---> �ǵ�һ��
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
int (*parr2)[10];  -  ����ָ��  ָ��һ������ ����ʮ��Ԫ�� ÿ��Ԫ�ص�������int
int (*parr3[10])[5];  -  ��һ�� �洢����ָ������� �������ܹ����10������ָ�� ÿ������ָ�� �ܹ�ָ��һ������ �������Ԫ�� ÿ��Ԫ����int����
parr3[10] ������һ������  �������õ� , int (*   )[5] ��һ������ָ�� ָ����һ������ ������ÿ��Ԫ�����Ͷ���int
�ٰ� �������ָ����� parr3[10] ������� 
parr3[10] ʮ��Ԫ�� ÿ��Ԫ�ؾ���һ������ָ��
*/