#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
	操作符详解
	以下区分:
	&取地址符					 单目
	&按位与						 双目
	*							 定义时声明指针变量
	*间接操作符 				*地址,解引用操作, 访问对应地址的对象 
	(类型)表达式				强制类型转换

	关系操作符
	>,<,>=,<=,!=,==				==只能用来判断数值是否相等,例如比较字符串则比较的是地址

	逻辑操作符
	&&	逻辑与					
	||	逻辑或

	逻辑操作符的逻辑截断	在能确定逻辑值时后面语句则不会再去执行->逻辑操作符的特性
	例:
	&&						a&&b&&c,若a为0则就能确定整个逻辑值为0，后面的bc则不会再去执行
	||						a||b||c,若b为1则就能确定整个逻辑值为1，后面的c则不会再去执行

	条件操作符,三目运算符
	条件?表达式1:表达式2	条件为真执行表达式1,否则执行表达式2		
	和if else的逻辑一样							只会执行其一
	
	逗号表达式:
	用,隔开的多个表达式 会从左至右依次执行,整个逗号表达式的值取最后一个表达式的值	
	所以前面的表达式可能会影响最后表达式的值，即可能影响整个表达式的值


*/
int test(char arr[]) {			//接收的形参会退化为指针


	return sizeof(arr);			//所以求的是指针的大小
}
int main() {
	int a = (int)3.14;			//可以不转换,系统只会警告
	char arr[10];
	int res = test(arr);
	printf("%d\n",a);
	printf("%d\n", res);
	int b = 1, c = 0, d = 3;
	int x = (b++) ||(c)|| (d++);
	printf("test1 b=%d,c=%d,d=:%d",b,c,d);
	int y = (b++) && (c++) && (d++);
	printf("test2 b=%d,c=%d,d=:%d\n", b, c, d);

	d > b ? printf("haha\n") : printf("hehe\n");
	int g = 6 > 4 ? 30 : 40;
	printf("%d\n",g);

	int test5, test55 = 2;
	test5 = (test55++, test55 + 2, test55);	//注意此时不是结合使用，++是单独使用的
	printf("test5:%d\n",test5);

	//逗号表达式的妙用	减少代码冗余	
	/*
	
		int a=function1();
		function2(a);
		while(a>0){
			printf("%d\n",a);
			a=function1();
			function2(a);
		}

		减少冗杂↓

		int a;
		while(a=function(1),function2(a),a>0){
			printf("%d\n",a);
		}

	*/
	

	return 0;
}
