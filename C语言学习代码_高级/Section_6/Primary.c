#include <stdio.h>

int main()
{
    func1();
    return 0;
}

int func1()
{
    FILE* pFile;
    //���ļ�
    pFile = fopen("myfile.txt", "w");
    //�ļ�����
    if (pFile != NULL)
    {
        fputs("fopen example", pFile);
        //�ر��ļ�
        fclose(pFile);
    }
    return 0;
}


/*
ֱ�ӿ� �ļ�������pdf����
�Ƚϼ�

printf��scanf����fprintf��fscanf�ļ�棬Ĭ��������Ϊstdout��stdin
*/