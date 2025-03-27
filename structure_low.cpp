#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
/*
	结构体初阶
	
	结构体     一种自定义的结构类型,是一组不同类型(也可以相同类型)的变量集合
	
	可以用来描述更复杂类型的对象(变量),每个类型的值都是这个结构体的成员
	
	访问成员的方式
	结构体变量操作符			结构体变量.成员
	结构体指针操作符		    结构体指针->成员

	两种创建对象的方法
	1.结构体定义即对象创建
	struct tag{			
	xxxx;
	...
	xxxx;
}对象1,对象2,...;			//创建结构体时顺便创建该类型的对象(变量)
	
	2.类型创建
	(struct) tag 对象;

<结构体的嵌套:结构体的成员类型可以是另一个结构体>

*/



struct Stu {			//自定义结构体类型:struct(可省略) Stu
	char name[20];		//结构体的成员
	int age;			//结构体的成员
	float score;		//结构体的成员
}student2,student3;		//定义即创建对象Student2和Student3	->此方式创建的是全局的变量

struct test {
	Stu person;			//结构体成员可以是另一个结构体的类型
	int money;
	double sss;
}test1;



int main() {
	Stu student1;						 //自定义结构体类型Stu创建的对象student1	->main函数内定义的,属于局部变量
	student1 = { "张三",20,59.5 };		 //对student1初始化-->全局变量 
	student2 = { "李四",21,99.5 };	
	test1 = { {"王五",20,29.5},33,22.13}; //嵌套结构体类型变量的初始化-->里面{}为test1对象成员person的初始化

	Stu* p = &student1;

	printf("%s\n",student1.name);		  //直接通过结构体变量访问

	printf("%d\n", (*p).age);			  //通过解引用结构体的指针找到结构体变量,再通过结构体变量访问       比较麻烦,一般直接用下面的方法
										  //注意.的优先级高于*的优先级,所以一定要用()聚组操作符来改变一下优先级 

	printf("%f\n", p->score);			  //直接通过结构体指针访问

	printf("%s",);

	return 0;
}