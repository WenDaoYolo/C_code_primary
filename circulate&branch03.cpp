#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*	
    <编程思路>---各种代码语法之间都是灵活相通的，打破传统的固定思维，要学会灵活搭配组合和嵌套(计算机语言,像人类的语言一样)
	
	循环circulate&分支branch
	分支循环等结构在非代码块的情况下其默认作用范围为一行
	if(xxx)
		xxxxx		一行范围
	for(xxx;xxx;xxx)
		xxxxx		一行范围
	for(xxx;xxx;xxx)
	{		代码块：范围为整个代码块
			....
			....
	}
	顺序结构

	选择结构(分支语句)
	if:
	if else,else

	switch:	适用于多分支，相比于if会更加简便
	case,break,default

	循环结构
	for		tip:C++和C99标准才支持在写for循环时创建变量->for(int a=0;a<100;a++)——>注意此变量定义在循环体内是<局部变量>，出了循环体则会销毁
	while
	do while

	goto语句

	专业术语:
	代码块：{}分隔使代码结构清晰
	{
		代码
		...
	}
    表达式:可以是单个变量或者复合组合，其形式不唯一,如a,a+1，(x+u),y=3,6,....
*/

int main() {
	{
		int testif = 40;
		if (testif >= 0 && testif <= 18)
			printf("青年\n");
		else if (testif <= 26)//在前面if不成立的情况下(即testif>18)才会进行判断,所以可以省略testif>18
			printf("成年\n");
		else if (testif <= 40)//同理
			printf("中年\n");
		else
			printf("老年\n");
	}
	//tip:如果在没有划分代码层次结构的情况下，else会与最近的if匹配
	/*
		if(xxx)			表达式xxx的值为真执行...
			if(xxx)		配对
			...
			else		配对
			...
	tip写法推荐:
	在写if相等条件判断时可以写为例如：5==x的这种写法,避免写成赋值的表达式(例如x=5，则表达式为永真)
	switch(表达式)
	{						代码块
		语句项1		      
		语句项2
		...
	}
	*/
		int testif2;
		for (testif2 = 1; testif2 <= 100; testif2++) {
			if (testif2 % 2 != 0)
				printf("%d是奇数\n",testif2);
		        }

		{	
			//小记:case决定结构入口,break决定结构出口
			char testswitch = 'T';
			switch (testswitch) {			//需要进行匹配的表达式(值)--->是一个整形常量表达式
			case 'M':printf("今天是星期一\n"); break;//语句项		补充知识:字符其本质是以ASCLL码(十进制整数)的形式存储在计算机中，所以也是常量(字符型整型常量)
			case 'T':printf("今天是星期二\n"); break;//case表达式,与case表达式相匹配则从此语句项开始执行语句(注:所有语句项)-->最后一个语句项break可以省略(本身执行完就结束了)
			case 'W':printf("今天是星期三\n"); break;//break用于跳出当前循环/结构，避免继续执行下面的所有代码--所以switch和break是绑定的
			case 5/2:printf("今天是星期四\n"); break;//此处表明在需要的情况下可以混写(不一定全是一个类型的值,也不一定是单个值)
			case 'F':printf("今天是星期五\n"); break;
			default:printf("今天是周末\n");			//若以上条件都不满足则默认执行这条语句(可以省略,但大多数情况下为了考虑问题全面会写)
			}						//各子句项包括default没有先后顺序而言
			int testswitch2 = 6;
			switch (testswitch2/2){			//表达式(值)
			case 1:
				printf("Yes\n");			//写法不唯一,其作用范围为case与case之间(所以不需要代码块符号)
				break;
			case 2:
				printf("No\n");
				break;
			default:
				testswitch2 = 666;
				printf("%d\n", testswitch2); 
				break;
			}
			//case语句项的省略写法-->省略不写则会默认与下一个语句项相同
			int day = 8;
			int day2 = 3;
			switch (day) {
			case 1:								//1省略则与2相同
			case 2:								//2省略则与3相同
			case 3:								//3省略则与4相同
			case 4:								//4省略则与5相同	--传递了省略写法
			case 5:printf("工作日\n"); break;	
			case 6:								//6省略则与7相同
			case 7:printf("休息日\n"); break;
			case 8:								//switch的嵌套
				switch(day2){
					case 3:printf("switch嵌套测试！\n");break;			//跳出内层结构				
					default:printf("nothing\n"); break;
				}
				break;													//跳出外层结构
			default:printf("error!\n"); break;
			}

		}
	return 0;
}
