#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
int main() {
	/*
	编写代码，实现多个字符从两端移动，向中间汇聚
	welcome to c program!
	w###################!
	we#################m!
	wel###############am!
	welc#############ram!
	...
	welcome to c program!
	简单的输出无法达到动态效果
	实现思路：每次输出完一行,停顿一小会儿再将这行清除然后输入下一行,
			  利用延时和程序执行速度极快的特性从而达到视觉差效果

	原理:输出,停顿,清屏+输出,停顿,清屏+输出,停顿,清屏+输出...	
	第一次执行程序屏幕没有任何数据所以不用清屏

	*/
	/*
	头文件<stdlib.h>   windows系统下可用windows.h头文件
	Sleep(参数)	睡眠函数：让当前线程暂时陷入一段时间的睡眠,从而达到延时执行代码或等待的效果,时间单位ms
	system("指令")    操作系统函数:让执行执行操作系统的命令或指令，如关机，打开文件等操作..
	cls指令:clear screen 清除屏幕
	*/
	char arry1[] = "#####################";
	char arry2[] = "welcome to c program!";
	int i = 0, j = (sizeof(arry1)-1)/sizeof(char)-1;
	for (i,j; i<=j; i++,j--){
		arry1[i] = arry2[i];
		arry1[j] = arry2[j];
		printf("%s\n", arry1);		//字符数组本质上就是字符串
		Sleep(1000);
		system("cls");
	}
	printf("%s\n", arry1);			//上面代码执行完会清屏，再输出保留视觉效果
	
	return 0;
}
