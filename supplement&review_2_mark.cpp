#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
int main() {
	/*
	
	goto语句	跳转语句，跳转到对应的标识符去执行程序
	语法:
	
	跳转标识符:

	goto 跳转标识符;
	
	理论上goto语句是不需要的,可以用其他代码实现，会打乱程序的执行顺序,但在特定情况下有一定的作用		例如电脑关机,goto一次跳出多次循环等

	关机命令行:shutdown	-s -t xxx
	解读:		关机   设置setting	时间time 秒

	取消关机命令行:shutdown -a

	定时关机命令行....


	//////////////////////////////////////////////

	编译运行会在项目文件夹下产生一个可执行文件
	Debug编译模式：用于生成项目的调试和开发版本
	Release编译模式：用于生成最终的正式发行版

	tip:若代码更新，则需要重新编译才能生成新的可执行文件
	//////////////////////////////////////////////





	学习最新的dos命令...
 	
	命令行:
	把可执行文件添加到本地服务中,并更改其启动类型			—配合关机命令,实现病毒原理0.0

	添加服务命令行:
	sc.文件类型 create 服务名称 binpath= "文件的绝对路径"
	sc.exe create BUG binpath= "C:\Users\35474\Desktop\C\2025_2_18\01\x64\Release\01.exe"

	删除服务命令
	sc.exe delete 服务名称

	设置服务的启动类型:
	sc.文件类型 config 服务器名称 start= auto
	sc.exe config 服务器名称 start= auto
	auto		自动
	....


	C中实现可执行程序添加到服务
	system("sc create BUG binpath= C:\\Users\\35474\\Desktop\\C\\2025_2_18\\01\\01\\x64\\Release\\01.exe");
	此处路径就不再需要单独用引号处理，因为system函数已经引用了双引号




	关键问题：权限不够
	如何通过命令行切换管理员身份来调用这些指令?
	后续深入研究




	*/
	int i = 0;

	


	Flag:
	printf("hehe\n");
	i++;
	if (i < 5)
		goto Flag;

	char input[20];
	system("shutdown -s -t 240");

	again:
	printf("你的电脑将在四分钟后关机,输入：我是猪来取消关机O.o\n");
	scanf("%s",input);

	if (strcmp(input,"我是猪")==0)
		system("shutdown -a");
	else
		goto again;


	return 0;
}
