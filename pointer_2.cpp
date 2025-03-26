#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
/*
	初阶指针

	野指针:指针指向的位置不可知(随机,不正确,没有明确限制的)
	
	造成野指针的原因:
	1.指针未初始化
	2.指针访问越界
	3.指针指向的空间被释放		                        例如定义的函数或者动态内存开辟(后面章节详解)
	  指针指向了一块空间，后面这块空间被释放掉了,然后这块空间就不属于当前程序,于是造成了野指针的问题


	test1
	int* p;				//指针未初始化,则会指向随机值 ->变量若不初始化都会赋予随机值
	*p=20				//操作了不属于当前程序的内存单元-->非法访问内存
						//只有申请了内存空间，才能使用该内存空间

	test2
	int arr[10]={0},int* p=arr;
	for(int i=0;i<=10;i++){
		printf("%d\n",*p)
		p++;			//数组最大元素为arr[9],而在i=10时，p的指向超出了数组的范围即越界
	}					//越界其本质也是非法访问内存->越界指向了一个未知地址
		

	test3	见下程序
	...
	
	


	如何规避野指针

	1.定义即初始化				一个良好的编程习惯,不管是指针还是什么都能有效减少错误
	通用初始化指针:若不知道初始化为什么,可以初始化为NULL	    
	NULL空指针,头文件stdio.h,系统定义的常量0被强制转换为void*类型(即空指针类型)

	2.小心指针越界				c语言本身不会检查数据越界行为	

	3.内存空间释放后,及时将相关的指针置为NULL(空指针)		
	注意空指针也不能直接用(解引用),因为空指针不指向任何地址

	4.在使用指针前检查其有效性   —>尽量保证指针只有两种状态：有效地址和NULL
    良好的编程习惯,指针用的时候指向地址,不使用或者失效时置为NULL
	此时指针就只有两种状态,有效地址和NULL,因此就可以通过空指针来判断其有效性
		if(p!=NULL)			
			*p....
	



	指针运算:

	指针+-整数			 +,-													地址从低到高变化
	指针的关系运算		 >,<,==判断指针(地址)的大小								高地址大于底地址

	指针-指针			 前提:两个指针指向的是同一块内存空间		   得到的是两个指针(即地址)之间元素的个数
																		  注:之间,则不包含尾指针指向的元素

	



*/
int* test3() {
	int a = 10;
	return &a;			//返回局部变量a的地址
}



//迭代计数器法
int my_strlen1(const char* str) {
	int count = 0;
	while (*str != '\0') {
		count++;
		str++;
	}
	return count;
}
//递归法
int my_strlen2(const char* str) {
	if (*str != '\0')
		return 1 + my_strlen2(str + 1);
	else
		return 0;
}
//指针运用法
int my_strlen3(char* str) {
	char* start = str;
	while (*str != '\0')		//获取'\0'的地址
		str++;
	
	return str - start;			//获取首地址和尾地址('\0')之间的元素个数并返回
}



int main() {
	//test2
	int arr[10] = { 0 };			
	int* p = arr;
	for (int i = 0; i <=10; i++) {			//最终指针的指向超出了数组范围,指向了一个随机的内存单元
		printf("%d\n", *p);
			p++;			
	}


	//test3				      打破局限思维,指针类型也是类型，也可以作为函数的返回类型
	int* p2;
	p2 = test3();		    //函数调用结束则会自动销毁，其中的局部变量也会销毁，而此时指针就会指向未知的地址
	*p2 = 20;			    //解引用操作了未知内存
	printf("test3:%d",*p2);	//也许可以正常输出，但会存在未知的问题和风险
	putchar('\n');
	int arr2[] = { 1,2,3,4,5 };
	int* pa = arr2;
	int* pa2 = arr2 + 4;
	if (pa2 > pa)
		printf("pa2的地址:%p大于pa的地址:%p\n",pa,pa2);
	printf("pa2-pa的结果是%d\n",pa2-pa);		//即&arr2[0]到&arr2[4]<之间>元素的个数-->即arr2[0]到arr2[3]
											//注意 arr[4](4个字节)在 & arr[4](4个字节的首地址)地址的后面,所以不算中间

	//模拟实现strlen函数
	int test111=my_strlen1("abcd");			//字符串也是一块连续的空间，是一个字符数组，但是常量类型,得用常量类型的指针来接收
	char arr4[] = "abcdefghd";
	printf("abcd的长度%d\n",test111);
	int test222 = my_strlen2("abcdedg");
	printf("abcdedg的长度%d\n", test222);
	int test333 = my_strlen3(arr4);
	printf("abcdefghd的长度%d\n", test333);


	return 0;
}