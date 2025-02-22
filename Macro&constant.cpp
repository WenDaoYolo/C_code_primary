#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX 4000 //定义标识符常量，在程序中MAX就代表4000
#define ADD(x,y) x+y	//定义宏，将传入的代码片段替换为x+y
#define ADD_Plus(x,y) ((x)+(y))	//针对ADD的改进版，考虑直接替换可能会出现运算优先级的问题：
																		//1.整个表达式作为一个整体
																		//2.x和y可能不是一个普通的单独量，也可能是一个复合表达式

int main() {
	/*
	预处理命令--在程序执行之前执行的操作
	#define定义符号
	1.#define定义标识符常量，将标识符定为常量
		（类似于数学计算中，PI就代表3.14）
	2.#define定义宏---宏：一种替换操作，具有参数
		tip:定义宏时应该考虑直接替换是否会影响运算优先级
	*/
	printf("%d\n", ADD(3,4));	//传入实参3，4，直接将这个宏替换为3+4
	printf("%d\n", 4*ADD(3, 4));//直接替换为3+4,结果为:4*3+4,所以结果为16
	printf("%d\n", 4 * ADD_Plus(3, 4));	//改进
	return 0;
}
