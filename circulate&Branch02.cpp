#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main() {
	int x = 0;
	int n = 3;
	while (1) {
		printf("我是while循环\n");
		if (x > 2)
			break;//break跳出当前循环/结构(只能跳出当前所在层的循环,多层循环嵌套需要分别用多次break)
				  //continue跳出本次循环(只结束本次循环,不会跳出当前整个循环)
		x++;
	}
	do {
		printf("我是do while循环\n");
	}while(n<3);
	if (n == 2)
		printf("我是选择语句1\n");
	else if (n == 3)
		printf("我是选择语句2\n");
	else
		printf("我是选择语句3\n");
	
	
	return 0;
}
