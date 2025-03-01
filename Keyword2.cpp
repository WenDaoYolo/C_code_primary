#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>	
void test01(){
	static int a=1;	//static修饰，改变了其存储类型,因此变量出了作用域会被保留而非销毁
	a++;
	printf("%d\t",a);
}

int main() {
	/*
	typedef：类型定义，自定义数据类型及其关键字
	*/
	typedef unsigned int uns_int;	//自定义数据类型uns_int
	uns_int a = 10;					//通过自定义数据类型创建变量
	printf("%d\n",a);
	/*
	程序中，内存分为3个存储区
	栈区(Stack)：存储局部变量，函数参数等临时数据	  其生命周期为进入作用域创建，出作用域销毁
	堆区(Heap)：用于动态内存分配
	静态区：存储全局变量和static修饰的量	  其生命周期为进入作用域创建，出作用域销毁(即整个程序的生命周期)

	extern:声明外部符号，用于链接引用其他源文件中的数据和函数
	extern 类型 名字
	extern 类型 函数名(类型[名字,可省略],.....)
	tip:该数据或者函数应该具有外部链接属性

	static:静态修饰，改变数据的存储类型，并将数据改为内部链接属性
	链接属性
	内部链接：只能在所在源文件内使用
	外部链接：可以在链接到外部其他源文件被使用，<全局变量>,<函数>具有外部链接属性

	常见应用场景
	1.修饰局部变量---更改存储类型--生命周期的改变
	2.修饰全局变量---改变链接属性
	3.修饰函数--改变链接属性
 	tip:static修饰变量只是改变存储类型和链接属性，其本质还是可以改变的量
	*/
	for (int j = 0; j <= 10; j++)
		test01();
	extern int extern_test;		//声明外部全局变量
	extern void extern_function(int,int);//声明外部函数
	printf("%d\n",extern_test);			
	extern_function(11,2);			

	return 0;
}
