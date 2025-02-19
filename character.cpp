#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main() {
	 //转义字符，通过\组合,转变了原本的意思，有着特殊含义
	printf("ab\ncd\n");//换行
	printf("C:\test\team\n");//水平制表
	printf("\a");//警告提示-蜂鸣
	//反转义字符，用于特殊字符输出,\+单个特殊字符
	//转义字符是单个字符，也占一个字节的空间
	printf("%s", "\"");
	printf("%c", '\'');
	printf("%c", '\\');
	//other:\b,\r,\f,\v,\ddd(8进制),\xdd(16进制)，\0空字符
	//每个字符都有对应的十进制ASCLL码，
	//当字符以整数形式输出时会输出对应的ASCLL码，反之亦然
	printf("%d", 'a');
	printf("%c",65);
	//详见ASCLL码对照表
	return 0;
}
