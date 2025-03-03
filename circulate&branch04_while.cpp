#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {
	/*
	break跳出(结束)当前循环/结构
	continue跳出(结束)本次循环/结构 (<跳过conitue后面的代码>,继续下一次循环)

	while(表达式)			表达式为真则进入代码块并执行
	{
		代码块
		...
	}
	*/
	int i = 1, j = 1, k = 1;
	while (i <= 10) {
		printf("%d\n", i);
		i++;
	}
	while (k <= 10) {
		if (k == 5)
			break;				//i==5时跳出循环
		printf("%d\n", k);
		k++;

	}
	/*
	while (j <= 10) {
		if (j % 5 == 0)	//j==5时开始死循环(程序分析-->j==5后就跳过j++,此时j不变化小于10又进入循环然后又跳过j++...)
			continue;
		printf("%d\n", j);
		j++;
	}
	*/
	return 0;
}
