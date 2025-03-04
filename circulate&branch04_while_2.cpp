#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {

	/*
	//字符型与整数型(ASCLL码)的自动转换---赋值，输出
	//字符型数值赋值给整型变量时赋值其字符对应的ASCLL码	          输出同理
	//整型数值赋值给字符型变量时赋值其十进制ASCLL码对应的字符     输出同理
	 函数原型：
	 int getchar(void);
	 putchar(参数);

	getchar()函数:读取(本质输入端读取)一个字符并返回(返回类型为int，所以返回的是字符的ASCLL码-->因为字符的本质是以十进制整数ASCLL码的形式存储在计算机中)   一般与赋值一起用:xxx=getchar()
											  xxx为char型则赋值ascll对应字符(字符型与ASCLL的自动转换)，xxx为整型则赋值ASCLL码
	putchar(参数):输出一个字符

	*/

	int a = 'A';
	char b = 97;							//赋值转换
	printf("%c:%d\n", a, b);
	int test1;
	test1 = getchar();
	char test2 = test1;
	printf("getchar_int:%d\n", test1);		//输出转换
	printf("getchar_char:%c\n", test1);
	putchar(97);							
	putchar('A');
	putchar(test2);
	


	return 0;
}
