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
	Stu person;			//结构体成员可以是另一个结构体的类型		结构体的嵌套定义,初始化和访问↓
	int money;
	double sss;
}test1;

void print1(test t) {
	printf("%s %d %f %d %lf\n",t.person.name,t.person.age,t.person.score,t.money,t.sss);//通过变量访问
}

void print2(test* pt) {
	printf("%s %d %f %d %lf\n", pt->person.name, pt->person.age, pt->person.score, pt->money, pt->sss);//通过地址(指针)访问
}

int add(int x, int y) {
	int z;
	z = x + y;
	return z;
}
int main() {
	int a = 10, b = 20;
	add(a, b);
	return 0;
}


int main() {
	Stu student1;						 //自定义结构体类型Stu创建的对象student1	->main函数内定义的,属于局部变量
	student1 = { "张三",20,59.5 };		 //对student1初始化-->全局变量 
	student2 = { "李四",21,99.5 };	
	test1 = { {"王五",20,29.5},33,22.13}; //嵌套结构体类型变量的初始化-->里面{}为test1对象成员person的初始化

	Stu* p = &student1;
	test* p2 = &test1;

	printf("%s\n",student1.name);		  //直接通过结构体变量访问

	printf("%d\n", (*p).age);			  //通过解引用结构体的指针找到结构体变量,再通过结构体变量访问       比较麻烦,一般直接用下面的方法
										  //注意.的优先级高于*的优先级,所以一定要用()聚组操作符来改变一下优先级 

	printf("%f\n", p->score);			  //直接通过结构体指针访问

	printf("test:%s\n",p2->person.name);  //结构体的嵌套访问	先通过指针访问Stu类型对象person,再通过结构体变量person访问其成员name数组

/*
	函数的传参调用
	传值调用
	传址调用				
	传址调用更好
	1.可以直接操作并改变实参	  
	2.节约空间,不用像传值调用一样要另外开辟一个空间来接收值	                 
	3.效率更高,函数只需要接收一个指针,而传值则要开辟一块空间,然后来接收这个值   -->函数的调用,以及其参数的创建都需要压栈
				    --->进一步优化了时间和空间上的复杂度,这也是指针的一大优势	

	但传值相对更加安全-->实参不会轻易被改变,无法通过形参来直接改变实参


	结构体作为参数传递同理

	数据结构:

	栈;先进(压栈)后出(出栈)			
	队列:先进先出

	压栈:又称入栈,在栈区上开辟一块空间,将数据存储到这块空间之中
	出栈:数据执行完后自动销毁,释放这块空间

	栈区:用于存储临时量的空间			例如函数调用(打破局限思维,主函数也是临时调用的),形参等
	
	栈区的工作原理->详见Memory&Stack in program_2.png

*/

	print1(test1);			//传值调用
	print2(&test1);			//传址调用	
							



	return 0;
}