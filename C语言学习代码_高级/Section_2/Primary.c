#include <stdio.h>

int main()
{
	// func0(); //�ַ�ָ��
    // practice0(); //��
	func1(); //ָ������
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