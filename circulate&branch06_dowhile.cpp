#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(){
	/*
		do while和while循环一致,唯一区别是do while至少会执行一次
		
		do{
			循环语句
			...			代码块	
		}while(条件);		
	
	*/
	//三种循环的练习
	int n,i=1,value1 = 1;
	printf("请输入n:\n");
	scanf("%d",&n);
	while (i <= n) {
		value1 = (value1) * i;
		i++;
	}
	printf("%d的阶层是:%d\n",n,value1);
		
	int sum = 0,value2=1;
	for (int j = 1; j <= 10; j++) {
		for (int k = 1; k <= j; k++)
			value2 *= k;			//阶层的计算
				sum += value2;		//阶层结果的累加
					value2 = 1;		//初始化阶层变量value2
	}
	printf("1到10阶层的和为:%d\n",sum);

	/*
		算法优化:本质数学思想
		3!=3*2*1
		2!=2*1
		1!=1
		所以3!=3*2!
			2!=2*1!
			1!=1
	*/
	int test = 1,test2=0;
	for (int m = 1; m <=10; m++) {	//通过当前阶层求下一个阶层的结果，而非再单独重新循环计算
		test *= m;		//优化掉了一层循环	不重置计算阶层变量，继续使用这个结果求下一个阶层
		test2 += test;
	}
	printf("算法2:%d\n",test2);
	return 0;
}