#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {
	int a;
	char c;
	float b;
	scanf("%d,%c,%f",&a,&c,&b);		//输入格式
	printf("a:%d,c:%c,b:%f",a,c,b);	//输出格式
	//数组，一组相同类型的数据，也有int，char等类型
	//数组以转义字符\0结束，不作为数组内容,所以字符串所占空间大小为字符数+1(隐藏的\0也占一个字节的空间)
	//转义字符\0是结束符的意思
	char u[5] = "adbd";//内存监视，需要F10进入调试模式后才能监视
	u[3] = 'w';
	///////////////////////////////////////////////////////////////////////////////////////////////////////


	return 0;
}