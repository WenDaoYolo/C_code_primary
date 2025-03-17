#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//判断闰年
void loopyear(int year) {
	if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
		printf("%d年是闰年",year);
	else
		printf("%d年不是闰年",year);
}	

//打印1-100之间素数 复刻
//穷举试除法
void su1(){
	int i, j;
	for (i = 2; i <= 100; i++) {
		for (j = 2; j < i; j++)
			if (i % j == 0)
				break;
		if (j == i)
			printf("%d ", i);
	}	
}
//定理试除法
void su2() {
	int i, j;
	printf("%d ", 2);						//2的情况单独处理
	for (i = 3; i <= 100; i+=2) {			//优化，偶数除2外其他都不是素数
		for (j = 2; j <=sqrt(i); j++)
			if (i % j == 0)
				break;
		if (j>sqrt(i))
			printf("%d ", i);
	}
}

//交换两个整数
void SWAP(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

//递归和非递归实现打印实现打印一个数的每一位
//递归
void print(int n) {
	if (n > 9)
		print(n/10);

		printf("%d ",n%10);
}
//迭代
void print2(int n) {
	while (n != 0) {
		printf("%d ", n % 10);			//无法直接正序输出(从高位到低位)
		n /= 10;
	}
}

//递归和非递归求n的阶层		不考虑溢出

//迭代
int function1(int n) {
	int res = 1,i=1;
	if (n == 0)
		return 1;
	while (i <= n) {
		res *= i;
		i++;
	}
	return res;
}
//递归
int function2(int n) {
	if (n == 0)			//0的阶层是1
		return 1;
	else if (n > 1)
		return n * function2(n - 1);
	else
		return 1;
}

//递归和非递归求第n个斐波那契数
//迭代
int Fib(int a) {

	if (a == 1)
		return 0;
	else if (a == 2)
		return 1;

	int x = 0, y = 1, z = x + y;
	while ((a-2)>=1) {
			z = x + y;
			x = y;
			y = z;
			a--;
	}
	return z;
}
//递归
int Fib2(int a) {
	if (a == 1)
		return 0;
	else if (a == 1)
		return 1;
	else if (a > 2)
		return Fib2(a-1)+Fib2(a - 2);
}

//递归和非递归模拟实现strlen函数功能,不允许使用操作字符串的相关函数
//迭代
int my_strlen1(char* arr) {
	int count = 0;
	while (*arr != '\0') {
		count++;
		arr++;
	}
	return  count;
}
//递归
int my_strlen2(char* arr){
	if (*arr != '\0')
		return 1 + my_strlen2(arr + 1);
	else
		return 0;
}






int main() {
	int year = 0;
	printf("请输入年份:");
	scanf("%d",&year);
	loopyear(year);
	putchar('\n');
	su1();
	putchar('\n');
	su2();
	putchar('\n');
	printf("请输入两个整数:");
	int a=0, b=0;
	scanf("%d%d",&a,&b);
	SWAP(&a, &b);
	printf("交换后:a=%d,b=%d",a,b);
	putchar('\n');
	printf("请输入一个整数:");
	int test = 0;
	scanf("%d",&test);
	print(test);
	putchar('\n');
	printf("请输入一个整数:");
	int test2 = 0;
	scanf("%d", &test2);
	print2(test2);
	printf("请输入要求阶层的数:\n");
	int test3 = 0;
	scanf("%d",&test3);
	int res1 = function1(test3);
	printf("%d的阶层是%d\n",test3,res1);
	printf("请输入要求阶层的数:\n");
	int test4 = 0;
	scanf("%d", &test4);
	int res2 = function2(test4);
	printf("%d的阶层是%d\n", test4, res2);
	putchar('\n');
	printf("请输入要求的斐波那契项数：");
	int aaa = 0;
	scanf("%d",&aaa);
	printf("%d",Fib(aaa));
	putchar('\n');
	printf("请输入要求的斐波那契项数：");
	int bbb = 0;
	scanf("%d", &bbb);
	printf("%d", Fib2(bbb));
	char arr1[] = "string";
	char arr2[] = "hello string";
	printf("\nstring的长度是%d\n",my_strlen1(arr1));
	printf("hello string的长度是%d", my_strlen2(arr2));
	return 0;
}






























