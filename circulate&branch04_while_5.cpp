#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {

	//scanf和getchar的组合使用，则需要考虑缓冲区的问题
	char password[20];
	int Flag = 0;
	int temp = 0;
	printf("请输入密码\n");
	scanf("%s", password);		//数组名就是数组的地址
	getchar();					//getchar读取缓冲区并清除数据
	printf("确认密码(Y/N)\n");
	while ((temp = getchar()) != '\n')//一次getchar只能清除一个数据，若缓存区存在多个数据，getchar的循环调用可以清除多个数据，直到读取到回车就结束循环
		;								//空语句
		Flag = getchar();			//此时缓冲取没有其他数据，等待输入端输入数据后，getchar便能读取到正确的数据了
	if (Flag == 'Y')			//整型和字符型，会自动转换其Ascll码再进行比较
		printf("确认成功\n");
	else
		printf("确认失败\n");

	/*
		循环调用getchar的应用场景——>用于清除缓冲区的多个数据
		拓展1：scanf函数使用字符串格式(%s)读取数据,读取到\0(字符串的结束标志),空格,换行,制表符等时会停止读取数据
		分析:
		此时若scanf输入数据是:123456 abcde回车
		scanf此时只会读取到123456
		缓冲区的数据:空格abcde回车		 此时单个getchar只能清除一个数据，便可以用循环的方式来清除
		int temp=0;
		while((temp=getchar())!='\n');	读取到回车就结束循环(详见line13)

	*/
	return 0;
}