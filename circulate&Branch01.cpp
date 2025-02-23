#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {
	int a = 1, b = 2;
	char k = 'M';
	if (a > b)
		printf("if分支结构,a>b\n");
	else
		printf("a<b");
	for (int j = 0; j <= 10;j++) {
		printf("For循环,我是第%d条语句\n",j);
	}
	printf("switch选择循环\n");
	switch (k) {
	case 'M':printf("Monday"); break;
	case 'T':printf("Tuesday"); break;
	case 'W':printf("Wenday"); break;
	default :printf("other"); break;
	}
		int t = 0;
		while(t < 10) {
			printf("While循环%d次\n",t);
			t++;
		}



}
