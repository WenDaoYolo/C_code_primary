#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
	结构体structure
	用来描述和创造更复杂的数据类型,比如学生这个类型就包含名字，学号，班级等，而这些成员数据可能都是不同的类型
	//多个不同类型的数据构成的复合数据类型
	 tip:创建的结构体的类型，应为本质是属于结构体大类的，所以其完整类型为大类下的自定义类型：struct 结构体名
	struct 结构名{
		类型 成员1；
		类型 成员2；
		...
		};
*/
//创建一个Stu的数据类型
int main() {
	struct Stu{
		char name[20];
		int age;
		char Sex[20];
	};								
	Stu stu1 = { "小王",20,"男" };	//创建一个Stu类型的变量stu1,并为其赋初值(赋初值又称为<初始化>)
	Stu stu2 = { "小红",21,"女" };	//创建一个Stu类型的变量stu2,并为其赋初值
									//实现创建了各种不同的学生

//创建一个Book的数据类型
	struct Book{
		char name[20];
		float price;
		char id[20];
	};
	Book book1 = {"jojo的奇妙大冒险",666.6,"20114"};  //创建一个Book类型的变量book1,并为其赋初值
	Book book2 = {"我是doro大王",999.9,"20115"};	  //创建一个Book类型的变量book2,并为其赋初值
	                                                  //实现创建了各种不同的书籍
	//.结构体调用操作符,-> 
	//访问调用结构体复合类型中的具体类型(即结构体中的成员):结构体名.成员名			
	printf("1:%s性别%s,年龄%d\n",stu1.name,stu1.Sex,stu1.age);	//调用结构体中的成员并输出
	struct Stu * ps = &stu1;										//将结构体的地址赋值给指针变量p

	printf("2:%s性别%s,年龄%d\n",*(ps).name, *p.Sex, *p.age);	//????
	return 0;
}