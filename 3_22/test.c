// C�����Ǵ��������ĵ�һ�п�ʼִ�е�
// 1. һ�����̿����ж��.c�ļ� ����ֻ����һ��main����
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
	return 0;
}
