#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
/*
	
	函数的调用
	传值调用	将实参的值传入形参		形参与实参分别为不同内存空间
	传址调用	将实参的地址传入形参	形参和实参联系了起来
	
	函数定义时，若未定义返回类型，则默认为int类型		但不建议这样写，因为不符合规范




	function练习1
	编写如下函数并完成其功能

	1.判断一个数是不是素数			素数(prime)
	2.判断年份是不是闰年
	


*/
//1.穷举试除法
void su1(int su){
	int i = 2;
	while (i < su) {
		if (su % i == 0)
			break;
		i++;
	}
	if (i == su)
		printf("%d是素数\n", su);
	else
		printf("%d不是素数\n",su);
}

//1.数学定理
void su2(int su) {
	int i = 2;
	while (i <=sqrt(su)) {
		if (su % i == 0)
			break;
		i++;
	}
	if (i>sqrt(su))
		printf("%d是素数\n", su);		//不建议这样写代码,尽可能保持模块的单一性,只完成素数的判断即可
	else                                //保持模块的单一性能使函数更加通用
		printf("%d不是素数\n", su);
}

//2. 数学定理			
void judgyear(int year){				   //注意:1.能被四百整除   2.能被4整除但不能被100整除
	if ((year % 400 == 0)||(year%4==0&&year%100!=0))		// 1和2是两个独立的条件，不能互推
			printf("%d年是闰年", year);
	else
			printf("%d年不是闰年", year);
}


int main() {
	int test1,test2,test3;
	printf("判断素数\n");
	printf("请输入一个数:");
	scanf("%d",&test1);
	su1(test1);				
	printf("请再输入一个数:");
	scanf("%d", &test2);
	su2(test2);
	printf("请再输入年份:");
	scanf("%d", &test3);
	judgyear(test3);			
	return 0;
}