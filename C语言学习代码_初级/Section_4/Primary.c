#include <stdio.h>


int main()
{
	// array_create();
	// Using_arrays();
	// array_storage();
	// array_2d_creaet();
	// bubble();
	arr_discuss();
	return 0;
}

// 数组的创建 
int array_create()
{
	// type_t arr_name[const_n];
	//type_t 是指数组的元素类型
	//const_n 是一个常量表达式 指定数组的大小  注意是 必须常量表达式
	int arr0[10];
	char ch0[5];

	int a = 10; // 给了值就叫做数值初始化
	int arr1[3] = { 1,2,3 }; // 完全初始化
	int arr2[5] = { 1,2,3 }; // 不完全初始化 (其他位置 自动填充 0)
	int arr3[] = { 1,2,3 }; //  = int arr3[3] ={1,2,3}; 也就是说 - 会自动根据后面的内容来确定数组的元素 //建议

	// 字符数组
	char ch1[5] = { 'z','x','z' }; // 自动填充 '\0'
	char ch2[] = { 'w','x','y' }; // 自动确定元素个数
	char ch3[5] = "zxz"; // z x z \0 \0  !!!!!!!!!!!!!!!!!!!!!!!!!!(字符串末尾默认放一个\0)
	char ch4[] = "zxz"; // z x z \0  自动确定元素个数  不会腾出多余的空间！ // 建议

	// 对比区别
	char ch5[] = "zxz";
	char ch6[] = { 'z','x','z' };
	printf("%s\n", ch5); // zxz
	printf("%s\n", ch6); // zxz烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫號U:柳  --- 
	// strlen() 默认结束标志是 \0 所以会一直找到\0  结束 
	printf("%d\n", strlen(ch5)); // 3
	printf("%d\n", strlen(ch6)); // 42 --- 随机值

	// 数组长度跟字符串长度是两个不同的东西
	return 0;
}

int Using_arrays()
{
	int arr[10] = { 0 };
	arr[4] = 5; // 下标引用符
	// 计算数组长度 ！
	printf("%d\n", sizeof(arr)); 
	printf("%d\n", sizeof(arr[4]));
	return 0;
}


// %p 按地址格式打印 --- 以十六进制打印
int array_storage()
{
	// printf("%x\n", 0x12); // 12
	// printf("%p\n", 0x12); // 0000000000000012
	int arr[10] = { 0 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("&arr[%d]= %p\n", i, &arr[i]);
	}

	// 结果看出 
	// 1. --- 一维数组在内存中是连续存放的
	// 2. --- 随着数组下标的增长  地址是由低到高变化的

	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = arr1; // 数组名是数组首元素的地址
	int j = 0;
	for (j = 0; j < 10; j++)
	{
		printf("%d\n", *p);
		p++;

	}
	return 0;
}


int array_2d_creaet()
{
	// 创建
	int arr[3][4];
	char ch[5][8];
	// 初始化
	int arr1[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };  //完全初始化
	int arr2[3][4] = { 1,2,3,4,5,6,7,8 }; // 不完全初始化 其他部分填充0
	int arr3[3][4] = { {1,2},{3,4},{5,6} }; // 1200 3400 5600 分成一维数组
	int arr4[][4] = { {1,2},{3,4},{5,6} }; // 行可以根据后面确定可以省略 但是列不能！！！！
	
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", arr1[i][j]);
			printf("&arr1[%d][%d] = %p\n",i,j,&arr1[i][j]);

		}
		printf("\n");
	}

	// 结果看出
	// 1. --- 二维数组在内存中也是连续存放的;
	// 2. --- 一行内部连续 跨行也是连续的;

	int* p = &arr3[0][0];
	int e = 0;
	for (e = 0; e < 12; e++)
	{
		printf("%d ", *p);
		p++;

	}
	return 0;
}


//int bubble()
//{
//	int arr[] = { 5,8,6,9,3,2,4,1,10,7 };
//	// 计算数组内元素个数
//	int sz = sizeof(arr) / sizeof(arr[0]); //为什么在这里传 前面说过 数组传参 传递过去形参部分的数组在函数内部是无法计算元素个数的
//	bubble_sort(arr, sz);
//	return 0;
//}
//
//// 冒泡排序的思想  ： 两两相邻元素进行比较 并且可能的话需要排序
//void bubble_sort(int arr[], int sz) // 形参arr 实质上是一个指针
//{
//	// 确定趟数
//	int i = 0;
//	for (i = 0; i = sz - 1; i++);
//	{
//		// 一趟冒泡排序的过程
//		int j = 0;
//		for (j = 0; j < sz-1-i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				// 交换
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//
//			}
//		}
//	}
//}



// 讨论 数组名到底是什么
//		--- 数组名是首元素的地址
//          但是有两个例外！ ： 
//                        --- 1. sizeof(数组名) - 数组名表示整个数组 - 计算的是整个数组的大小 单位是字节
//                        --- 2. &数组名 - 数组名表示整个地址 - 取出的是整个数组的地址
int arr_discuss()
{
	int arr[10] = { 0 };

	printf("%p\n", &arr[0]);  // 000000B8DF0FF6E8         // 1
	printf("%p\n", arr);      // 000000B8DF0FF6E8         // 2
	printf("%p\n", &arr);      // 000000B8DF0FF6E8        // 3
	// 三个结果虽然一样  1 2 相等
	// 但是 - &arr 取出的是数组的地址 跟前面两个意义不同

	printf("-------------------------------------------------------------\n");
	// 验证 为什么不同
	printf("%p\n", arr);       // 000000792F6FF768
	printf("%p\n", arr + 1);     // 000000792F6FF76C      --- 差了 4
	printf("%p\n", &arr);      // 000000792F6FF768
	printf("%p\n", &arr + 1);    // 000000792F6FF790     --- 差了40 (差了十六进制的22 也就是十进制的 2*16+8=40)差除了一个数组的大小

	printf("-------------------------------------------------------------\n");
	int sz = sizeof(arr);
	printf("%d\n", sz);  // 40

	return 0;
}











