#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int extern_test = 2024;	//我是外部全局变量extern_test
static int extern_test02 = 2025;//我是被static修饰的外部全局变量，
								//为内部链接属性无法链接到其他源文件被使用
void extern_function(int a,int b){	//我是外部函数extern_function
	int c = a + b;
	printf("I am extern_function\t%d\n",c);
}
void extern_function02() {			//我是被static修饰的外部函数extern_function02
	printf("No!\n");				//为内部链接属性无法链接到其他源文件被使用
}