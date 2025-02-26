#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
	结构体structure
	用来描述和创造更复杂的数据类型,比如学生这个类型就包含名字，学号，班级等，而这些成员数据可能都是不同的类型
	//多个不同类型的数据构成的复合数据类型
	 tip:定义的结构体本质上是一个类类型(struct大类下的自定义类),在使用定义的结构体类型时，前面的struct可以省去(默认会自动添加)
		结构名{
		类型 成员1；
		类型 成员2；
		...
		};
*/
//创建一个Stu的数据类型
int main() {
	struct Stu {
		char name[20];
		int age;
		char Sex[20];
	};
	 Stu stu1 = { "小王",20,"男升" };	//创建一个Stu类型的变量stu1,并为其赋初值(赋初值又称为<初始化>)
	struct Stu stu2 = { "小红",21,"女" };	//创建一个Stu类型的变量stu2,并为其赋初值
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
	//.结构体调用操作符
	//访问调用结构体复合类型中的具体类型(即结构体中的成员):结构体名.成员名

	// *解引用操作符:调用访问地址指向的数据
	// 三种结构体成员调用的方式：			
	printf("1:%s性别%s,年龄%d\n",stu2.name,stu2.Sex,stu2.age);	//调用结构体中的成员并输出
	Stu * p= &stu1;										//将结构体的地址赋值给指针变量p
	printf("2:%s性别%s,年龄%d\n", (*p).name, (*p).Sex, (*p).age);	//*操作符解引用指针变量p中存储的地址来访问结构体，然后.操作符调用成员
																	//tip:.的优先级高于*,所以要使用()操作符来改变优先级!!
	printf("3:%s性别%s,年龄%d\n",p->name,p->Sex,p->age);		// ->结构体指针对象操作符:通过指针访问结构体中的成员：结构体指针->成员，等价于上面指针访问的一种简便写法
	struct stuu {
		double score;
		char id[20];
		char name[20];
	};
	stuu s = { 33.2,"2011","wangwu" };
	struct stuu* p1 = &s;
	printf("%s,%lf,%s\n", (*p1).id, (*p1).score, (*p1).name);


	return 0;
}