#include<stdio.h>
int main() {
	int a = 1;//对应输入输出格式字符%d
	char b = 'b';//对应输入输出格式字符%c
	short int c = 2;//对应输入输出格式字符%d
	long int d = 3;//对应输入输出格式字符%d
	long long e = 4;//对应输入输出格式字符%d
	float f = 1.2f;//对应输入输出格式字符%f
	double g = 1.33;//对应输入输出格式字符%f
	printf("常见的几种数据类型及其空间大小:\n");
	printf("int:%d\n", sizeof(int));
	printf("char:%d\n", sizeof(char));
	printf("short int:%d\n", sizeof(short int));
	printf("long int:%d\n", sizeof(long int));
	printf("long long:%d\n", sizeof(long long));
	printf("float:%d\n", sizeof(float));
	printf("double:%d\n", sizeof(double));

	printf("sizeof操作符求变量的空间大小:\n");
	printf("float g=1.33占%d个字节\n", sizeof(g));
	return 0;

}
