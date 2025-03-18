#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main() {
	int a;
	char c;
	float b;
	int arr5[] = {3,3,2};
	scanf("%d,%c,%f",&a,&c,&b);		//输入格式
	printf("a:%d,c:%c,b:%f",a,c,b);	//输出格式
	//数组，一组相同类型的数据，也有int，char等类型
	//字符串,字符数组以转义字符\0结束(划重点)，不作为字符串和数组内容和字符数
	// 所以字符串所占空间大小为字符数+1(隐藏的\0不算字符数和内容，但也占一个字节的空间)
	//转义字符\0是结束符的意思
	char u[4] = "adbd";//内存监视，需要F10进入调试模式后才能监视
	char arr2[4] = {'a','d','b','d'};//单字符型初始化，若是以字符串的形式输出，则需要手动补'\0'
	printf("aaa:%d\n",strlen(arr2));
	char arr3[] = {'a','b','c','d','\0'};
	int fi = strlen(u);//strlen函数属于string函数库
	int se = strlen(arr3);
	printf("%s\n",arr2);
	printf("%s\n",arr3);
	printf("u的字符数是%d\n",fi);
	printf("arr3的字符数是%d\n",se);
	u[3] = 'w';
	///////////////////////////////////////////////////////////////////////////////////////////////////////


	return 0;
}
