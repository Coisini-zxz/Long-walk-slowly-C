#include <stdio.h>

int main()
{
    func1();
    return 0;
}

int func1()
{
    FILE* pFile;
    //打开文件
    pFile = fopen("myfile.txt", "w");
    //文件操作
    if (pFile != NULL)
    {
        fputs("fopen example", pFile);
        //关闭文件
        fclose(pFile);
    }
    return 0;
}


/*
直接看 文件操作的pdf即可
比较简单

printf和scanf就是fprintf和fscanf的简版，默认流参数为stdout和stdin
*/