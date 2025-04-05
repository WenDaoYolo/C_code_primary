#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>


int minnum(int m,int n) {				//欧几里得算法求最大公约数
	int temp=m%n;
	while (temp) {
		temp = m % n;
		if (temp == 0)
			return n;

		m = n, n = temp;
	}
	return n;
}

void Reinput(char arr[],unsigned int num) {
	int i = num,temp=0;
	while (i >= 0) {
		while (arr[i] != ' '&&i>=0)
			i--;

		temp = i+1;

		while (arr[temp] != ' ' && arr[temp] != '\0') {
			putchar(arr[temp]);
			temp++;
		}
		putchar(' ');
		i--;
	}
}





int main() {
	/*
	
		C语言本身是没有输入输出语句的	<C语言本身只规定了一些基础语法以及关键字>

		而输入输出则是依靠的系统提供的库函数--->本质上就是开发者用C语言语法写出来的函数,方便用户快速实现某些功能
		所以<函数库是独立于C语言的>,其中的库函数不是C语言本身的东西,而是人为的用c语法写出来的函数,用来完成某些特定功能
		例如printf是stdio函数库中的一个函数,是开发人员已经写好了直接提供给用户使用的库函数
		
		所以C语言本身是很简洁的,而这些库函数是人为的作为C语言的拓展,避免让开发这从0开始去实现这些功能,提高了工作效率
		后面学到的一些其他的函数库,框架,游戏引擎等都是如此

		不同编译器,其库函数的实现方式都不一样	

		test.c	到	test.exe的实现

		test.c->预处理->编译->汇编->链接->test.exe


		纠正:操作符的运算顺序看优先级和结合律,而++--的规则是针对其操作数的运算顺序而非操作符本身的运算顺序
		++--运算分两个部分:使用和增值

		例如*p++,++的优先级高于*，所以先算++运算再*					
		而后置++是先使用后++,则先使用p(将p的值取出来),然后p++,最后*p(注意,这里解引用的是原先取出来的值而非p++后的值)
		也可以理解为:先使用p的值,*p解引用,最后p++
		两种理解其逻辑都是一样的

		所以是先解引用p的值,然后p++(注意,此时++的操作数是p而不是*p)

		*p++<==>*(p++)		注意,虽然p和++进行了聚组()，但后置++所以其执行过程仍然是先把p的值给*解引用,然后再p++
							所以:不要被这个聚组操作符给误导-->被误导为增值p,再*p
															  实际是先使用p,将p的值给*用,然后p再++
		

	*/
	int arr[] = { 10,20,30 };
	int* p = arr;
	printf("%d",*(p++));

	/*
	
	char a,int b,float c,double d
	a+b+c+d最后的结果是什么类型?										 double
	a+b,先对a进行整型提升然后运算得到结果
	然后结果进行算术转换,转换为float和c进行运算,然后算术转换为double和d进行运算
	
	*/


	/*
	输入a和b,求a和b的最小公倍数
	

	int a = 0, b = 0; int res = 0;
	printf("\n请输入a和b:");
	scanf("%d%d",&a,&b);
	res = minnum(a,b);
	printf("最大公约数:%d\n",res);
	printf("最小公倍数:%d\n", (a*b)/res);

	*/
	

	/*
		练习1:将一个字符串,其单词逆序输出
		例如:I like English	-> English like I
	*/
	char arr1[100];
	printf("请输入语句(不超过100个字母):");				//scanf读取到空格,制表符,换行等则会停止读取，改用gets(在vs高版本也已经完全移除->不安全)	  最后改用fgets函数
	fgets(arr1,sizeof(arr1),stdin);						//例如输入:I like it,则读取I,剩下的 like it则会留在缓冲区
	arr1[strcspn(arr1,"\n")] = 0;						//fgets会读取换行符，处理掉换行符->fgets函数暂不深入了解	mark
	Reinput(arr1,strlen(arr1)-1);
	return 0;
}