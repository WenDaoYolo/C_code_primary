#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>	
typedef unsigned int ui;	//typedef自定义数据类型
void test01(){
	int a = 3;	//局部变量
}
int main() {
	//关键字	系统提供的标识符,具有一定的含义,可以用于数据的修饰和定义
	//如int,float,const,continue,default,if,else,enum
	//auto(自动变量,每个局部变量都默认被auto修饰可以省略,自动创建变量，出了作用域scope,会自动销毁)
	//auto在其他语法中的作用---暂不深入研究
	/*
	extern:声明外部符号
	register:寄存器关键字	--应用场景:将会大量重复调用的数据放入存储器,其速度更快
	---现版本编译器更加智能,即使不建议也会自动将数据数据放入寄存器
	修饰的量会被建议放入寄存器中(是否放入取决于编译器)
	cpu读写存储器速度:寄存器>高速缓存>内存>外存
	return:返回函数结果,除void类型外,所有类型函数均要有返回值---函数的规范性
	signed:有符号类型(+,-)
	unsiged:无符号类型
	static:静态类型
	struct,switch,goto,void...
	typedef:自定义数据类型				type define 自定义的数据类型及其标识符
 	
	union:联合体(共用体)
	volatile					比较难，暂不深入


	*/
	register int value1 = 3;
	static int value2 = 4;
	unsigned int value3 = 4;
	ui k=30;		//自定义数据类型ui变量

	test01();
	return 0;//函数的规范性
}
