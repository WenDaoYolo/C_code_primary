#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>	

int main() {
	//单个数组名代表整个数组，访问数组的单个元素通过下标访问,默认下标从0开始
	/*
	格式:
	类型 数组名[长度]
	定义时省略长度，则系统会自动更具赋值数为数组定义长度
	长度必须为不可变的常量
	*/
	int a1[] = { 2,3,4 };//长度为3
	char a2[] = "string";//字符数组
	char a3[] = { 'a','b'};//若涉及到字符串等相关计算时需用\0结束符
	printf("%s\n",a2);
	for (int i=0;i<=2;i++)
		printf("%d\n",a1[i]);
	/*
	数组初始化：
	1.赋值数小于长度时，剩余自动补0(整型)	不完全初始化
	2.赋值单个0，则默认全部初始化为0		完全初始化

	*/
	int test[3] = {0};
	int test2[6] = { 3,2 };




	return 0;
}