#define _CRT_SECURE_NO_WARNINGS	1	// ���ڿ�ͷ ��ֹscanf����
#include <stdio.h>
#include <string.h>

extern int pointer_1();
extern int pointer_2();
extern int pointer_3();
int main()
{
	// data_type();
	// Variable_types();
	// Variable_used();
	// g_val_s();
	// constant();
	// string();
	// Escape_character();
	// Select();
	// cycle();
	// Add(123, 456);
	// array();
	// operator();
	// arr_num();
	// Compl();
	// B_A_plusplus();
	// Type_cast();
	// Logical();
	// conditions();
	// Comma();
	// Keywords_typedef();
	// Keywords_static();
	// define_constant();
	// define_macro();
	// pointer_1();
	// pointer_2();
	// pointer_3();
	Structural_body();
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

// ѭ�����
int cycle()
{
	printf("����ѧϰC��������\n");
	int line = 0;
	while (line <= 200)
	{
		line++;
		printf("��Ҫ����Ŭ���ô���\n");
	}
	if (line > 200)
		printf("��offer\n");
	return 0;
}

// ����
int Add(int x, int y)
{
	int z = x + y;
	printf("%d\n", z);
	return z;
}

// ����
int array()
{
	/*
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	......
	*/
	// ���� - һ��ͬ�����͵�Ԫ�صļ���
	int arr[4] = { 1,2,3,4 };
	char ch[5] = { 'a', 'b', 'c' }; // ���� 5��,��ֻ�������� ���� ������ȫ��ʼ���� ʣ���Ĭ��Ϊ0. (ע:�����ţ�������python��һ��)
	int i = 0;
	while (i <= 3)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	return 0;

}


// ��ʼ������
int operator()
{
	int a = 9 / 2;
	float b = 9 / 2.0;
	int c = 9 % 2;
	printf("%d\n%f\n%d\n", a, b, c);
	int d = 2;
	int e = d << 1; //���Ʋ����� -- �ƶ����Ƕ�����λ
	printf("%d\n", e);

	int z = 1;
	printf("%d\n", !z); // 0��ʾ�� ��0��ʾ��
	if (z)
	{
		// ���aΪ�� ִ��
	}
	if (!z)
	{
		// ���aΪ�� ִ��
	}

	return 0;
}

// ��������Ԫ�ظ���
int arr_num()
{
	// ÿ��Ԫ��ռ4byte / sizeof�ǲ����� ���Ǻ���
	int arr[10] = { 0 };
	printf("%d\n", sizeof(arr)); //40
	printf("%d\n", sizeof(arr[0])); //4
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", sz); //10
	return 0;
}

// ��λȡ��
int Compl()
{
	int a = 0;
	printf("%d\n", ~a);
	// 00000000000000000000000000000000 ---> 11111111111111111111111111111111(ԭ��) --->10000000000000000000000000000000(����)
	// ---> 10000000000000000000000000000001(����) ---> �õ� -1
	// ������λȡ���������ж�����λȡ��	
	/*
	�������ڴ��д洢���ǲ���!!��
	������ԭ�뷴�벹����ͬ
	ֻ��Ը����� ԭ��ȡ��(����λ���䣡)+1 �õ�����
	eg��-1 ��ԭ�룺10000000000000000000000000000001  (��һλ 1 ��ʾ���� 1Ϊ����)
			 ���룺11111111111111111111111111111110
			 ���룺11111111111111111111111111111111

	*/
	return 0;
}

// ǰ��++/����++
int B_A_plusplus()
{
	int a = 10;
	int b = ++a; //ǰ��++  :  ��++ ��ʹ��
	printf("%d\n", b); // 11
	printf("%d\n", a); // 11

	int q = 10;
	int w = q++; // ����++ : ��ʹ�� ��++
	printf("%d\n", w); // 10
	printf("%d\n", q); // 11


	// �������о������˷�ʱ���о����Ǵ���Ĵ��� ��ͬ���������ܲ�ͬ���
	//int a = 1;
	//int b = (++a) + (++a) + (++a);
	//printf("%d\n", b);

	return 0;
}

// ǿ������ת�� 
int Type_cast()
{
	// ���� (����) ǰ׺����	
	int a = (int)3.14;
	printf("%d\n", a);
	return 0;
}

// �߼�������
int Logical()
{
	int a = 3;
	int b = 5;
	int c = a && b;  // ��
	// int c = a || b;  // ��

	printf("%d\n", c);
	return 0;
}

// ����������(��Ŀ������)
/*
	exp1 ? exp2 : exp3
	exp1 ����, exp2���� �������ʽ�ṹ��:exp2�Ľ��
	exp1 ������, exp3���� �������ʽ�ṹ��:exp3�Ľ��
*/
int conditions()
{
	int a = 0;
	int b = 3;
	int max = 0;

	//if (a > b)
	//	max = a;
	//else
	//	max = b;
	max = a > b ? a : b;

	printf("%d\n", max);

	return 0;
}


// ���ű��ʽ
int Comma()
{
	// 2��4+5��6
	int a = 0;
	int b = 3;
	int c = 5;
	int d = (a = b + 2, c = a - 4, b = c + 2);
	// ���ű��ʽ �Ǵ��������μ���� ���������ʽ�Ľ���� ���һ�����ʽ�Ľ��
	printf("%d\n", d);
	return 0;
}

// typedef �ؼ���  - ����˼�������Ͷ��壬����Ӧ�����Ϊ������������
typedef unsigned int u_int;
int Keywords_typedef()
{
	unsigned int num = 100;
	u_int num1 = 200;
	printf("%d\n%d\n", num, num1);
	return 0;
}

// static �ؼ��� 
/*
��C�����У�
static���������α����ͺ�����
1. ���ξֲ����� - ��Ϊ��̬�ֲ����� - �ı��˾ֲ���������������(�����Ǹ����˱����Ĵ洢����)
2. ����ȫ�ֱ��� - ��Ϊ��̬ȫ�ֱ��� - ��add.c
3. ���κ��� - ��Ϊ��̬����         - ��add.c
*/
void test()
{
	// int a = 1;
	static int a = 1;
	a++;
	printf("%d\n", a);
}
int	Keywords_static()
{
	// eg1
	int i = 0;
	while (i < 10)
	{
		test();
		i++;
	}
	// eg2
	// printf("%d\n", g__val) // ����ʹ��extern��������Ҳ�޷�ʹ�� ��add.c

	// eg3
	//int a = 1;
	//int b = 3;
	//int c = Add_(a, b);
	//printf("%d\n", c);
	return 0;
}

//  #define ���峣���ͺ�
// define ��һ��Ԥ����ָ�� 
// 1. define �������
#define zzz 100
int define_constant()
{
	printf("%d\n", zzz);
	return 0;
}
// 2.define ����� 
// C�����еġ��ꡱ���궨�壬��һ����������ĳ�ν��
// �������ѧ��ĺ���һ�ֳ������������һϵ��Ԥ����Ĺ����滻һ�����ı�ģʽ�����������������������ʱ���Զ�������һģʽ�滻��
#define ADD(X,Y) X+Y
// #define ADD(X,Y) ((X)+(Y))
int define_macro()
{
	printf("%d\n", ADD(2, 3)); // 5
	printf("%d\n", 4 * ADD(2, 3));// 11  ---> 4*2+3 �滻�ģ����� ���
	// Ҫ��õ� 20 Ҫ�� ע���������壡����
	return 0;
}


// �ṹ��


struct Stu
{
	char name[20];
	int age;
	double score;
};

int Structural_body()
{
	struct Stu s = { "����", 20, 85.5 }; // �ṹ��Ĵ����ͳ�ʼ��
	printf("1: %s %d %lf", s.name, s.age, s.score);

	struct Stu* ps = &s;
	// �����ò���
	printf("2: %s %d %lf", (*ps).name, (*ps).age, (*ps).score);
	// �ṹ��ָ�� -> ��Ա������
	printf("3: %s %d %lf", ps->name, ps->age, ps->score);
	return 0;
}


