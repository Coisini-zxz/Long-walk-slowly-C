#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
#include <assert.h>

int main()
{
	// func1();
	// func3();
	// func4();
	// func5();
	// func7();
	// func8();
	// func9();
	// func11();
	func12();
	return 0;
}


//  ָ�����͵�����
int func1()
{
	// 1.
	int a = 0X11223344;
	// 16���� - 0 1 2 3 4 5 6 7 8 9 a b c d e f
	// 11111111 - ����λ���Ѿ� 8+4+2+1 = 15 �� Ҳ����f  ---> һ��ʮ������λ �����ĸ� ������λ
	
	// ���� - �ڴ� - �鿴a�ı仯��
	
	// int* pa = &a;
	// *pa = 0;

	// char* pc = &a;
	// *pc = 0;
	// ���Ա���Ļ� �����д��ڴ濴�� ֻ��  11 ����� 00 

	// 2.
	int arr[10] = { 0 };
	int* p = &arr;
	char* pc = &arr;
	printf("%d\n", p);       // 925890088   
	printf("%d\n", p+1);   // 925890092    --- ��4 �����һ������ Ҳ�����ĸ��ֽ�
	printf("%d\n", pc);     // 925890088
	printf("%d\n", pc+1); // 925890089    --- ��1 �����һ���ַ� Ҳ����һ���ֽ�

	// 1.  ָ�����;����� :  ָ������÷��ʵ�Ȩ���ж��
	// 2.  ָ�����;����� :  ָ����һ�� ���߶�Զ (����)
	// eg:
	func2();
	return 0;
}

int func2()
{
	int arr[10] = { 0 };
	int* p = &arr;
	// char* p = &arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = 1;
	}
	return 0;
}

// Ұָ�� : ����ָ��ָ���λ���ǲ���֪�� 

int func3()
{
	// 1. �Ƿ������ڴ�
	// �����p ����Ұָ��
	// int* p;  // p��һ���ֲ���ָ����� , �ֲ���������ʼ���Ļ� Ĭ�������ֵ��
	// *p = 20;

	// 2. ָ��Խ�����
	//int arr[10] = { 0 };
	//int* p = &arr;
	//int i = 0;
	//for (i = 0; i <= 10; i++)
	//{
	//	*p = i;
	//	p++;
	//}

	// 3. ָ��ָ��Ŀռ��ͷ�
	//int* p = test();
	//*p = 20;
	//return 0;
}

int* test()
{
	int a = 10;
	return &a;
}

/*
��α���Ұָ�룿
1.  ָ���ʼ��  --- ��֪����ʼ��Ϊʲô��ַ��ʱ�� ֱ�ӳ�ʼ��Ϊ NULL�������飩
2. С��ָ��Խ�� --- C���Ա����ǲ����������Խ����Ϊ�ģ� 
3. ָ��ָ��ռ��ͷż�ʱ��NULL --- 
4. ָ��ʹ��֮ǰ�����Ч��
*/


// ָ������
// 1.  ָ�� +- ����   2. ָ��-ָ�� 3. ָ��Ĺ�ϵ����

int func4() 
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d\n", &arr[9] - &arr[0]);
	// ָ��-ָ�� �õ����� ����ָ��֮ǰ��Ԫ�ظ���

	char c[5];
	printf("%d\n", &arr[9] - &c[0]);
	// ���Ƶõ���һ���� ������ʵ�ǲ���ȷ��
	// ָ�������ǰ���ǣ� ����ָ��ָ��ͬһ��ռ䣡 
	return 0;
}


int func5()
{
	// int len = strlen("abc");
	int len = my_strlen("abc");  // ģ��ʵ��strlen�Ĺ���
	printf("%d\n", len);
	return 0;
}

// ����������
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}


// �ݹ鷽��

//	ָ���������
int my_strlen(char* str)
{
	char* start = str;
	while (*str != '\0')
	{
		str++;
	}
	return str - start;
}

// ָ��Ĺ�ϵ����

int func6()
{
	float values[5];
	float* vp;
	for (vp = &values[5]; vp > &values[0];)
	{
		*--vp;
	}
	// ���´��� ������һ�� ���ǲ����� ������������������Ȼ���������� ���Ǳ�׼������֤�������� ��
	
	//for (vp = &values[5-1]; vp >= &values[0];vp--)
	//{
	//	*vp;
	//}

	// C���Ա�׼�涨
	// ����ָ������Ԫ�ص�ָ����ָ���������һ��Ԫ�غ�����ڴ�λ�õ�ָ����бȽ� ���ǲ�������ָ���һ��Ԫ��֮ǰ���Ǹ��ڴ�λ�õ�ָ����бȽ�
	return 0;
}

//  ָ�������

// ��������ʲô�أ�
int func7()
{
	int arr[10] = { 0 };
	printf("%p\n", arr); //��������������Ԫ�صĵ�ַ
	printf("%p\n", &arr[0]);  // ��ӡ�ᷢ�� ������ͬ
	return 0;
}

int func8()
{
	int arr[10] = { 0 };
	int* p = &arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		// printf("%p  <==> %p\n", &arr[i], p + i);
		*(p + i) = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%p  <==> %p\n", &arr[i], p + i);
		printf("%d \n", arr[i]);
		printf("%d \n", *(p+i));
	}
	// �Ƶ� --->
	//  arr[2] <==> *(arr+2) <==> *(p+2) <==> *(2+p) <==> *(2+arr) <==> 2[arr] ????���
	//  2[arr] <==> *(2+arr) 
	int arr_[5] = { 1,2,3,4,5 };
	printf("2[arr_]=%d <==> arr_[2]=%d\n", 2[arr_], arr_[2]);
	 
	// why? --->  :  []��һ�������� 2/arr ���������������� ����λ��һ��
	// eg: a+b <==> b+a  +��Ҳ�ǲ�������

	// arr[2] ���������ջ�ת���� *(arr+2) p[2] Ҳ���ջ�ת���� *(p+2)
	int* p_ = &arr_;
	printf("arr_[2] = %d\n", arr_[2]);
	printf("p_[2] = %d\n", p_[2]);

	return 0;
}

// ����ָ��
int func9()
{
	int a = 10;
	int *pa = &a;  // pa ��һ��ָ��  һ��ָ��
	int **ppa = &pa; // pa Ҳ��һ������ . &pa ȡ��pa ���ڴ��е���ʼ��ַ
	// ��ʱppa ����һ������ָ�����
	// int*** pppa = &ppa;  ����ָ��  �� ���������أ���
	printf("%d\n" ,**ppa); // 10
	return 0;
}

// ָ������
int func10()
{
	int arr[10];  // ��������  --- ������͵�����
	char ch[5];  // �ַ�����  --- ��ŵ����ַ�
	// ָ������ --- ���ָ�������
	int *parr[10]; // ����ָ�������
	char *pch[5]; // �ַ�ָ�������
	return 0;
}

struct SS
{
	char c;
	short b;
	double d;
};

// �ṹ�����
struct Stu
{
	// ����
	int age;
	char name[20];
	char id[20];
	// �ṹ��ĳ�ԱҲ��������һ���ṹ��
	struct SS sb; 
}; // �ֺŲ��ܶ�������
// } s1,s2;  ����Ҳ�Ǵ����������ṹ�����  
// ���� �� s1, s2��ȫ�ֱ��� ��������Ǿֲ�����

int func11()
{
	// ����
	// �ṹ�������ʼ��
	struct Stu s =
	{
		21,
		"Wxylkxy",
		"201940440003",
		{'w', 1,0}
	};
	// ע�� char������Ҫ "" 
	// ���ʽṹ�����
	printf("%c\n", s.sb.c);
	printf("%s\n", s.name);
	struct Stu *ps = &s;
	printf("%c\n", (*ps).sb.c);
	printf("%c\n", ps->sb.c);
	return 0;
}

// ģ��ʵ��strlen()
int func12()
{
	char arr[] = "Wxylkxyzz";
	// int len = strlen(arr);
	int len = MyStrlen(arr);
	printf("len = %d\n", len);
	return 0;
}

int MyStrlen(const char* str)
{
	assert(str != NULL);
	// assert(str);
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}










