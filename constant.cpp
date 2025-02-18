#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 10000 //预处理命令定义的标识符常量,类似于数学中定义PI固定为3.14
#include<stdio.h>
int main() {
	
	int a = 10;
	a = 20;
	const int b = 10;
	printf("变量a=%d,const修饰的常变量b=%d\n",a,b);
	int arr[b] = { 0 };//数组的长度只能指定为常量（数组是已经开好的连续空间不可再改变）
	for (int n = 0; n < b;n++) {
		printf("%d\n",arr[n]);
	}
	printf("#define定义的标识符常量MAX=%d\n",MAX);
	enum Sex { MALE,FEMALE=9 };//自定义的枚举常量数据类型Sex
	enum Sex t = MALE;
	enum Sex m = FEMALE;
	printf("我是自定义的枚举常量数据类型MALE我未赋初值，默认值为：%d\n", t);//枚举常量从第一个元素开始，若未赋初值，其数值默认固定为0，往后依次增加
	printf("我是自定义的枚举常量数据类型FEMALE,我赋了初值：%d", m);
	return 0;
}