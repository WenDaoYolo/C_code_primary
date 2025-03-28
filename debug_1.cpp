#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
	调试技巧		debug,找bug的过程就称为调试
	
	拒绝迷信式调试

	什么是bug？		计算机执行程序过程中出现的错误

	1.发现错误存在
	2.以隔离,消除等方式对错误进行定位
	3.确定错误产生的原因
	4.提出纠正错误的解决方法
	5.对程序错误给予改正，重新测试

	正确认识和对待bug

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 编译器的两种环境
	 debug版本和release版本
	 不同环境下编译产生不同版本的文件

	 debug:调试版本
	 程序员自己用来调试的版本

	 release:发布版本
	 调试完,最后发布发售的版本

	 区别:
	 debug版本的文件比release版本产生的文件要大
	 因为debug版本包含调试文件,release版本不包含调试信息，无法进行调试(F10,F11逐语句和过程等)


	 所以发布版本的运行速度是要优于debug版本,提高了用户的体验

	 其次debug版本编译器不会对程序进行任何优化以此方便程序员进行调试,而release版本编译器会自己对程序进行优化，所以可能也会产生不同的结果

	 未来研发人员写的debug版本，测试人员测试的是release版本,所以可能存在bug和差异


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   windows环境下的调试				不同系统的调试方式不一样

	   前提:编译器环境处于debug版本下

	   调试相关快捷键:
	   开始执行不调试					trl+F5

	   两种逐步调试
	   逐过程执行调试					F10			->只逐步展示调试过程,调用函数只会展示函数调用后的结果,不会进入该函数内部
	   逐语句执行调试					F11			->逐步展示每一条语句,调用函数后会进入该函数内部分析每一条语句

	   断点											-->程序会执行到断点处会停下来	-->从断点处开始调试
	   开始执行并跳转到下一个断点处		F5			没有断点的情况下直接F5，则程序会一路执行直至程序结束
	   在某位置创建断点和取消断点		F9			所以F5和F9一般配合使用	->也可以通过鼠标点击代码行首部实现

	   Fn辅助键										当以上键没有反应,可以通过Fn+以上键来使用
		

		断点的应用场景								->对于可能出现错误的地方打上断点,避免前面已确定无错代码的重复调试,提高效率,避免大量时间的浪费		->例如循环语句
													->没问题的代码部分直接跳过,可能出现问题的部分开始逐步调试

		打破局限思维,这些调试方式是灵活的,可以穿插着使用		例如F5跳到可能出现问题的地方,F10逐过程往下走,发现函数调用想进入内部,则F11 进入函数内部...

		博客:多去学习一些vs常见快捷键		采用结合记忆法

		例如:
		ctrl+shift+F9删除所有断点
		shift+F5退出调试状态

		快速注释和取消注释:
		选中代码:ctrl+k+c	注释			ctrl控制键	kernel核心	coment注释
				 ctrl+k+u	取消注释		ctrl控制键	kernel核心	uncoment取消注释
		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		

		调试程序时查看相关信息				通过调试菜单--->包含各种调试工具
		
		最常用的功能:窗口				    查看调试过程中的各种数据				-->前提:针对调试的工具,所以要在调试状态下才有这些工具
		例如监视窗口,自动窗口,局部变量窗口,内存窗口,断点窗口,反汇编(代码区右击鼠标也可以查看),寄存器(涉及微机原理与接口技术),线程等				

		监视窗口,是用的最多的工具,想查看什么信息输入即可,可以看的信息及其类型最多										可以清除监视的数据
		自动窗口,和监视窗口一样,区别是不需要手动添加查看信息,当程序执行到某一处语句时,会自动添加并监视相关变量和值		不能清除监视的数据
		内存窗口:左边是16进制地址,中间边是内存地址中对应存放的数据(内存中存储的是二进制,但是为了开发人员的查看,是以16进制展示),右边是数据翻译后的内容(有时候翻译的不准)

		打破局限思维,语言语法的一些操作符同样适用于这些调试工具			-->例如想查看a的值,在监视窗口下输入a,想查看a的地址,则取地址符输入&a

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		

*/	   



void print() {
	for (int i = 1; i <= 10; i++)
		printf("%d\n", i);
}

int main() {
	int arr[100] = { 0 };				
	for (int j = 0; j < 100;j++) {
		arr[j] = j;
	}
	
																	//若确定循环部分没有问题,在循环之后打断点,避免逐过程或语句调试过程的大量重复执行
	char s[] = "hello,this is a test!\n";
	printf("%s",s);

	print();

	return 0;
}