#define _CRT_SECURE_NO_WARNINGS	1	// ���ڿ�ͷ ��ֹscanf����
#include <stdio.h> 	

int main()
{
	printf("��ӡ����\n");
	printf("%d\n", 100); //��ӡһ������ - %d
	// sizeof - �ؼ��� - ������ - �������ͻ��߱�����ռ�ռ�Ĵ�С ��λΪbyte
	// C���Ա�׼ : sizeof(long) >= sizeof(int)
	printf("%d\n", sizeof(char));		//�ַ���������
	printf("%d\n", sizeof(short));		//������
	printf("%d\n", sizeof(int));		//����
	printf("%d\n", sizeof(long));		//������
	printf("%d\n", sizeof(long long));	//��������
	printf("%d\n", sizeof(float));		//�����ȸ�����
	printf("%d\n", sizeof(double));		//˫���ȸ�����
	variable();
	sum_ab();
	return 0;
}
int variable()
{
	int age = 21;
	double weight = 67.8;
	age = age + 1;
	weight = weight - 10;
	printf("���� : %d\n", age);
	printf("���� : %lf\n", weight);
	return 0;
}
// %d int
// %f float
// %lf double

// scanf()���뺯�� printf()�������
int sum_ab() 
{
	int a = 0;
	int b = 0;
	int sum;
	scanf("%d %d", &a, &b);
	sum = a + b;
	printf("sum = %d\n", sum);
	return 0;
}