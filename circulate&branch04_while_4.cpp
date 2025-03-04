#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {
	/*
	* 输入函数与缓冲区
	实例:scanf(先)和getchar(后)的组合使用————>造成输入结果与实际读取结果不符
	分析：
	输入函数如scanf等和getchar的运行原理一样，区别的是scanf<不会识别回车(转义字符\n)>
	在输入端输入数据后，scanf会读取除了回车以外的所有字符
	缓冲区会剩下一个\n,而此时getchar判断缓冲区有数据会直接读取，从而造成getchar读取的不是正确数据
	所以需要在getchar之前清除掉缓冲区的\n       解决方法：再加入一个getchar来专门清除缓存区
	*/
	int a, b;
	printf("请输入:\n");			//scanf不会读取\n，因此只用scanf函数的重复输入不需要考虑缓冲区的问题
	scanf("%d", &a);
	if (a == 1)
		printf("Yes\n");
	printf("请再输入:\n");
	scanf("%d", &b);
	if (b == 2)
		printf("No\n");

	return 0;
}

