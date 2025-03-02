#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
typedef unsigned int ui;

void fun1(int a, int b){//函数内部尽量不要输出，要精简从而保证函数的<通用性>(建议)
	if (a >= b)				//void 改int                                                                                    c程序是逐行执行代码（面向过程）
		printf("%d\n",a);		//return a;		注意函数可以有多个return，但只有一个return值(在执行到return语句后函数就结束了，只会执行到其中一个)，但必须有(非空类型)

	else
		printf("%d\n",b);		//return b;
}

int main() {
	/*
	字符数组的两种赋值方式:
	char[]={'a','b','c','\0'};单字符式不会添加结束符
	char[]=-"abc";字符串式会默认自动添加结束符
	*/							//区别:
	char arr[] = { 't','r','s'};//strlen():字符串长度(字符个数)计算函数
								//sizeof():计算数据占用空间(字节)
	printf("%d\n",strlen(arr));	//因为单字符数组赋值(即字符串的一种形式)没有结束符\0,所以计算其元素个数时为随机值！！
	char arr3[] = "hello";
	printf("improve:%d\n", strlen(arr3));//字符串的赋值形式，字符串后面会默认添\0
	char arr2[] = { 't','r','s','\0' };		//数组初始化时即可不用赋值长度(会自动根据初始化数据数量来决定长度)
	printf("Int:%d\n", strlen("Int"));
	printf("Int memorry:%d\n", sizeof("Int"));	//字符串以\0(转义字符也占一个字节空间)结束，所以占用空间数为字符数+1
	printf("%d\n", strlen(arr2));
	printf("八进制转义字符:\130\n");			//转义字符，转换为其十进制对应的ASCLL字符
	printf("十六进制转义符:\x58\n");
	//变长数组(即数组长度可以定义为变量，但是<不能初始化>)--只有支持C99的标准的编译器来能使用的语法
	int n = 10;		
	arr[10];	//可以定义,说明VS2022支持C99标准	--:变长数组暂不深入
	int a, b,d;
	d = strlen("c:\test\121");
	printf("%d\n", d);
	printf("请输入两个整数:\n");//printf输出格式函数，规定数据的输出格式
	scanf("%d-%d",&a,&b);		//scanf输入格式函数,规定数据输入的格式
	fun1(a,b);					
	ui y = 3;				//自定义数据类型ui变量
	printf("%d",y);
	return 0;



}
