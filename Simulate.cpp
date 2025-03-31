#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
/*		
		再次回顾NULL空指针,是一个void*类型的指针,其值为0,他不指向任何地址,可以用来初始化,但无法解引用

		紧接上回
		const修饰一级指针已了解,现在讨论const修饰二级指针

		const修饰的三种对象
		const int * const * const 
		第一个const修饰**p,第二个const修饰*p,第三个修饰二级指针变量p
		注意:若二级指针被const修饰,那么其指向的一级指针也必须被const修饰(都具有const属性才能进行接收)
*/

char* mystrcpy(char* dest,const char* src) {
	char* ret = dest;				    //存放目的地的起始地址用于后面的返回
	while (*dest++ = *src++)			//*src被const修饰了,但src没有
		;
	return ret;							//返回目的地的起始地址
}
				
size_t my_strlen(const char* src) {		//仅仅是求长度,不希望改变源数据,则用const保护源数据-->提高了代码的健壮性
	assert(src!=NULL);					//避免传空指针			或assert(src),空指针的值是0则为假,非空指针则为真
	size_t count = -1;
	while (count++,*src++ != '\0') {
		;
	}
	return count;
}										//进一步优化,返回的是长度,所以肯定是一个绝对值,即不会是负数并且没有符号,所以可以进一步优化为size_t类型
										//size_t,是系统定义的无符号整型类型	unsigned int
										//int也没有问题也不会出现负数,按照自己的思维来


int my_strlen3(char* str) {				//系统库函数的源文件写法
	char* start = str;					//详见操作符优先级表
	while (*str++);						//后置++的优先级高于*解引用的优先级	注:(*str)++是错的,这里表示解引用的值参与判断,然后其值+1,实际地址并未偏移
	return str - start-1;				//这里减一是因为str走到了\0的后面,所以要减回来指向\0的地址		
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
										//误区!:<前置自增/自减是针对复合语句而非操作符,操作符按照优先级和结合律运算>
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
int main() {
	int s = 10;
	int s1 = 20;
	const int* ps = &s;		
	const int** pps = &ps;				//const修饰**pps，则**pps无法被改变,而pps和*pps则可以改变
	printf("%d\n",**pps);
	*pps = &s1;							//解引用找到指针ps,改变了ps的指向
	printf("%d\n", **pps);
	putchar('\n');
	/*
		const的使用优势

		紧接上回,const修饰源值,不仅仅是可以防范源值与目的地写反,还可以有效的保护源值数据不被更改
		void my_strcpy(char* dest,const char* src){	只是仅仅将src的值赋值给dest,而src的值希望不被改变
				....
		}  
		
		注意哪些是要修改的哪些是不需要修改的,根据逻辑和需求去使用const,例如dest是要被修改的,所以肯定不能被const修饰

		系统的strcpy函数有返回类型,为char*，即返回了一个字符指针 ,返回的是目的地的起始地址
		其用处是是用户能直接拿到目标内容的地址从而查看其变化
		
		*/
	char test1[] = "hello,world!";
	char test2[] = "why?";
	char test3[] = "OK";
	char* try1=strcpy(test1,test2);				//系统提供的strcpy函数,将源值拷贝给目的地,并返回了目的地的地址(起始地址,即首地址)
	printf("%s\n",try1);	
	printf("%s\n", mystrcpy(test1, test3));		//模拟实现strcpy函数,函数的链式访问,mystrcpy函数的返回值作为printf函数的参数
												//再次回顾,printf函数也是有返回值的,返回的是<输出字符>的个数
												// -->注意这里看的是控制台输出字符的个数(包括转义字符,可能会被忽略或者不容易察觉)而不是输出格式里面的
	int testprintf = printf("hello,%d\n",13);
	printf("%d\n",testprintf);					//h e l l o , 1 3 \n共9个字符,则返回值为9

	//练习	模拟实现strlen函数
	//注意考虑const，assert等运用,是函数更加完美

	printf("%s的长度是%d\n", test2,my_strlen(test2));
	printf("%s的长度是%d\n", test2, my_strlen3(test2));
	

	//多参考系统提供的库函数源码	->网上开源代码或者编译器安装目录下(不同版本可能路径不同,得自己找)
	// vs2022:C:\Program Files (x86)\Windows Kits\10\Source\10.0.22621.0\ucrt
	
	//多看看去模拟实现

	/*
		常见的编程错误
		编译型错误:->编译不通过,一般都是语法错误
		链接型错误:->使用未定义的符号函数等

		运行时错误:->程序的运行结果和预期不符合,一般为思维逻辑的错误-->需要借助调试一步一步定位

	*/




	return 0;
}