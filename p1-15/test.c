#define _CRT_SECURE_NO_WARNINGS	1	// ���ڿ�ͷ ��ֹscanf����
#include <stdio.h> 	
#include <string.h>

int main()
{
	// data_type();
	// Variable_types();
	// Variable_used();
	// g_val_s();
	// constant();
	// string();
	// Escape_character();
	Select();
	return 0;

}


// ��������
int data_type()
{
	// sizeof - �ؼ��� - ������ - �������ͻ��߱�����ռ�ռ�Ĵ�С ��λΪbyte
	// C���Ա�׼ : sizeof(long) >= sizeof(int)
	printf("%d\n", sizeof(char));		//�ַ���������
	printf("%d\n", sizeof(short));		//������
	printf("%d\n", sizeof(int));		//����
	printf("%d\n", sizeof(long));		//������
	printf("%d\n", sizeof(long long));	//��������
	printf("%d\n", sizeof(float));		//�����ȸ�����
	printf("%d\n", sizeof(double));		//˫���ȸ�����
	return 0;
}


// ��������  (�ֲ���������ԭ��)
int global = 2019;//ȫ�ֱ���
int Variable_types()
{
	int local = 2018;//�ֲ�����
	//���涨���global�᲻�������⣿
	int global = 2020;//�ֲ�����
	printf("global = %d\n", global);
	return 0;
}


// ����ʹ��
int Variable_used()
{
	int a = 0;
	int b = 0;
	int sum;
	scanf("%d %d", &a, &b);
	sum = a + b;
	printf("sum = %d\n", sum);
	// scanf()���뺯�� printf()�������
	return 0;
}


//��������
extern int g_val;
int g_val_s()
{
	printf("%d\n", g_val);
	return 0;
}


// ����
#define MAX 10000
int constant()
{
	/*
	1.���泣��
	3.14;
	10;
	"abcdfw";
	*/

	/*
   2.const���εĳ�����
   int num = 10; //�����Ǳ���
   num = 20;
   const int num = 10; // ��ʱnum�ͽг����� - ���г�����(���ܱ��ı�) �����ϻ��Ǳ���ֻ��const���κ���г�����
   num = 20;
   printf("num = %d\n", num); //20

   int arr1[10] = { 0 };
   int n = 10;
   int arr2[n] = { 0 }; // ��ʱ n Ϊ���� �ᱨ��
   const int n_ = 10;
   int arr2[n_] = { 0 }; // ��ʱ n_ Ϊ������ ����n_�ı����Ǳ��������������������޷�����ʹ��!!!
   */

   /*
   3. #define ����ı�ʶ������
   MAX = 222; Error ���ܸ��ģ�
   int n = MAX;
   printf("n = %d\n", n);
   */

   // 4.ö�ٳ��� (����һһ�оٵĳ���) ���ؼ���enum
   // eg: �Ա�
	enum Sex
	{
		// ����ö�����ͱ�����δ������ȡֵ
		// MALE = 5 ���Ը���ֵ Ĭ��Ϊ0������ 
		MALE,
		FAMALE,
		SECRET
	};
	// ע: ��������ֵ�ģ�
	printf("%d\n", MALE);   //0
	printf("%d\n", FAMALE); //1
	printf("%d\n", SECRET); //2

	enum Sex Zz = MALE; // ��ʱ��ö�ٳ��� ֻ�������������е�һ����

	return 0;
}


// �ַ���
// VScode F10 ���� ���� 
int string()
{
	// �ַ����� - ������һ����ͬ���͵�Ԫ��
	// char �ַ��������� ������һ�� arr[]���� []�ڲ������ݻ��Զ����ݺ����ַ�������
	char arr1[] = "abcde"; // ������������Ԫ�� ��Ϊ �ַ�����β�Զ�������\0 (�ַ����Ľ�����־)
	char arr2[] = { 'b', 'i', 't' };  // �������� ����������Ϊû�н�����־
	char arr3[] = { 'b', 'i', 't', '\0' };  // ���߶Աȸ��� \0 ��β����
	printf("%s\n", arr1);
	printf("%s\n", arr2);
	printf("%s\n", arr3);
	// strlen() �� �ַ�������
	// ����strlenδ����ľ��� ˵��û������ͷ�ļ�
	strlen("abc"); //string length
	int len = strlen("abc");
	printf("%d\n", len);// ����Ϊ3�� \0 ֻ�ǽ�����־ �����ַ�������ʱ���ƣ��������ַ����������\0��
	printf("%d\n", strlen(arr1)); // 5
	printf("%d\n", strlen(arr2)); // ���ֵ! ��β��֪����ʲô ��һֱѰ�ҵ� \0 ������������������ֵ
	printf("%d\n", strlen(arr3)); // 3
	return 0;

}


// ת���ַ�
int Escape_character()
{
	printf("%d\n", strlen("abcdef"));
	// \62��������һ��ת���ַ�
	printf("%d\n", strlen("c:\test\628\test.c")); //���Ϊ14  �Ʊ����һ���ַ��� \ddd ��628���ǰ˽�������
	return 0;
}


// ѡ�����
int Select()
{
	int input = 0;
	printf("��ϲ��ѧ��ѧ�𣡣���ѡ��1 or 0��:>\n");
	scanf("%d", &input);
	if (input == 1)
	{
		printf("�������\n");
	}
	else
	{
		printf("�ؼ�������\n");
	}
	return 0;
}
