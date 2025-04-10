#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdio.h>
#include<assert.h>
/*
			调试技巧
		尽量减少和预防错误

		常用的编码技巧
		1.assert	断言
		2.const		常量
		3.良好的编程风格
		4.添加到必要的注释
		5.避免编码的陷阱

*/
void my_strcpy(char* dest, char* src) {
	while (*(src-1)!='\0') {			// \0也要拷贝过去,等判断条件为指针走到了\0的后面->或者再循环执行完后再手动拷贝个\0
		*dest = *src;				
		dest++;
		src++;
	}									//但这种写法不够好		
}										//以下为更优更好的写法


void my_strcpy_1(char* dest,char* src) {			
	while (*dest++=*src++) {			//先赋值再判断,这样一次性既完成了赋值又完成了判断		\0的ascll值为0,即为假
		;								//要不断模仿和研究,写出更好更优的代码,不断地去培养优良的代码风格
	}									//但是这个写法还是有缺陷,还可以进一步优化
}	


//进一步优化-->涉及到相关知识点

/*	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
1.若传递的是空指针,则解引用会出现问题				使用assert(条件表达式)断言(假设)函数		<实际上是定义的宏>

				头文件assert.h		与常规思维相反,是不满足条件才触发报错(可以理解为:以合法为主,不希望这个错误发生,所以为真则合法,为假则不合法报错)
				假设是对的,如果真是对的(真)则无任何行为,如果不是对的(假)则终止并输出错误		 											//类似于srccmp字符串比较函数, 是以比较不同为主
	 
				条件为<假>时,断言失败并终止程序并输出相关错误信息,用于捕捉和快速定位程序中不应该出现的错误或数据(可以是语法本身也可以是用户自定义的)

				例如:希望不能输入负数,则assert(xxx>=0);假设他就是大于等于0的
				     不能传空指针,则assert(xxx!=NULL); 假设他不是空指针
				输出信息格式: 文件名,行号,条件表达式内容


				assert是针对调试的函数, 先前讲过debug版本下才有调试的相关功能,所以只有再debug版本下才能使用assert函数
				release版本定义了NDEBUG,禁用了调试的一些列功能和函数
				assert属于防御性编程,设置判断,能够提前暴露一些潜在的错误
													

				断言的解释		-->更利于去深入理解这个概念
				断言就是假设,是程序员写的"自信检查"			例如:我断言这个指针不是空指针,是合法的！  ->assert(xxx!=NULL)
				那如果这个指针确实不是空指针,即非空指针!=空指针,条件为真则不触发任何错误	假设是对的->断言成功
				那如果这个指针是空指针,即空指针!=空指针,条件为假则终止并输入错误信息		假设是错的->断言失败
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
2.const			const修饰的变量具有常量属性,不能被修改,但本质还是变量

				如果在传参时源值和目的地写反了,编译器是不会察觉的,任然会对其进行赋值,这样就会造成一些错误
				为了避免这种错误可以通过<const不可被修改的特性>来限定源值--->如果写反就会提示(是不可修改的左值)

				
				编译器特性(现编译器vs2022已经不支持这种特性)
				const修饰的值无法被被改变的,但可以通过指针的方式去改变	        --->但这种方式是违背const本身的意愿的	注:这是vs以前的版本可以这么做
				现编译器已不支持这样的语法,自动优化了该写法,常变量就只能用被const修饰的指针去接收
				const 类型* p;		->const修饰的是p地址对应的值,即*p,所以*p是一个常量从而无法被修改,这样常变量指针解引用后依然是一个不能被修改的常量
									->所以此写法cosnt修饰的是解引用的值,指针本身没有被修饰,所以指针仍然可以改变

				<const修饰指针的几种情况>		一个是指针,一个是内容,还可以两个都修饰
				const 类型* p;			const修饰*p,上面已经提到	->用于接收常变量地址的方式
				类型* const p;			此时const修饰的是指针变量p,而*p并没有被修饰->所以此时指针p不能被改变,而指针指向的对象可以被改变(前提是指向的对象不是常变量) 
				const 类型* const p;	此时const既修饰p也修饰*p

				注意修饰*p还有一种写法,const写在*左边	int const * p	-->写法灵活多变,选择自己的习惯即可

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/																								
										
	//优化1							
void my_strcpy_2(char* dest, char* src) {
	assert(dest != NULL);						//注意：此次假设的对象是指针,而不是指针解引用的值
	assert(src != NULL);						
												//assert(src!=NULL&&dest!=NULL);不建议这样写，如果只是其中之一出了问题呢->那又得去判断是哪个出了问题
	while (*dest++ = *src++) {
		;
	}
}
	// 优化2			使用const限定
/*
	void my_strcpy_3(char* dest,const char* src){
					....
	}
*/


int main() {
	/*
		 
		 模拟实现字符串函数strcpy-字符串拷贝	strcpy(表达式1,表达式2)		将表达式2的值拷贝并赋值给表达式1(通过调试发现拷贝内容包括结束符\0)

	*/
	char a[20] = "xxxxxxxxx";			//缺省空间自动补\0(整数型则自动补0)
	char b[] = "hello";
	char c[] = "test";
	char d[] = "test2";					//strcpy的特性
	strcpy(a,b);						//"hello\0"依次按顺序赋值给a[]相应的元素
	printf("%s\n",b);					//打印结果为hello,因为\0也拷贝过去了,<字符串特性>遇到\0就结束了,所以即使后面还有内容也不会打印
	my_strcpy(b,c);
	printf("%s\n", b);
	my_strcpy_1(b, d);
	printf("%s\n", b);

	int ss = -3;
	assert(ss>=0);						//注意只写ss表达式有歧义的,因为在这里他只能判断真和假,即0和非0，不能判断是否大于0
	
	my_strcpy_2(b, c);
	printf("test3:%s\n", b);
	
	const int h = 3;
	const int* ps = &h;					//*ps被修饰为常量属性,其指向对象无法被修改		
	ps = &ss;							//指针ps仍然可以改变

	int h2 = 5;
	int h3 = 6;
	int* const ps2 = &h2;				//此时const修饰的是指针,所以其指针无法就修改
	//ps2 = &h3;			X				
	*ps2 = 133;							//*ps2没有被修饰,所以仍然可以改变
	int test6 = 10;
	const int* const test7 = &test6;	//此时*test6和test6都被修饰了,都无法被改变	
	 //*test7 = 16;			X
	 //test7 = &h3;			X
	return 0;
}
