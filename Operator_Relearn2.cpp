#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>



int Judgment1(int m, int n) {				//不适用于负数
	int i = 0,res=0;
	for (i = 0; i < 32; i++) {
		if (m % 2 != n % 2)
			res++;
		m /= 2;
		n /= 2;
	}
	return res;
}

int Judgment2(int m, int n) {
	int res = 0, t = 0,i=0;
	t = m ^ n;
	while (i<32) {
		t >>= i;							//第一次无需右移--->即右移0位
		if (t % 2 == 1)
			res++;
		i++;
	}
	return res;
}






/*
	操作符复习2

	先看操作符优先级,再算操作符操作的数

	输入两个数字m，n,求两个32位数不同位的个数
	例如15和14
	
	算法1:简单粗暴
	将m和n的每一个对应的位拿出来比较


	算法2:优化更好,循环更少,效率更高
	1111
	1110		有1个不同

	思维:进行依次异或运算,都出来的结果,其1就是不同的部分,其0就是相同的部分
	再用之前的方式去统计1的个数
	1111
	1110

	0001		n=n&(n-1)或者&+>>或者取模2再除2(只适用与正数)
	...



	方法总结:

	除r,模r		不适用于负数
	n&(n-1)
	与1,右移
	异或,再求1
	...
	方式灵活，不限方法

*/

int main() {
	int m, n,m1,n2;
	int res = 0,res1;
	printf("请输入m和n:");
	scanf("%d%d",&m,&n);
	printf("请输入m1和n2:");
	scanf("%d%d", &m1, &n2);
	res=Judgment1(m,n);
	printf("%d和%d有%d个不同位\n",m,n,res);
	res1 = Judgment2(m, n);
	printf("%d和%d有%d个不同位\n", m1, n2, res1);

	//分别打印出一个数的偶数位和奇数位
	int temp = 0,k=0;
	printf("请输入数字:");
	scanf("%d",&temp);
	printf("\n奇数:");
	for (k = 31; k >= 1; k -= 2)
		printf("%d",(temp >>k )&1);
	printf("\n偶数:");
	for (k = 30; k >= 0; k -= 2)
		printf("%d", (temp >> k) & 1);

	//交换两个整数的内容,不能创建第三个变量
	int test1 = 10, test2 = 11;
	//方法1		局限性,数过大或者过小时会溢出
	test1 = test1 + test2;
	test2 = test1 - test2;
	test1 = test1 - test2;
	printf("\n%d-%d\n",test1,test2);
	//方法2		异或的互补特性和结合律
	test1 = test1 ^ test2;			//test1^test2^test2->test1^0->test1
	test2 = test1 ^ test2;			//test1^test2^test1->test2^0->test2
	test1 = test1 ^ test2;
	printf("\n%d-%d\n", test1, test2);

	//指针类型的访问权限			详见Operator_Relearn2.png
	int arr[] = { 1,2,3,4,5 };
	short* p = (short*)arr;			
	int i = 0;
	for (i = 0; i < 4;i++) {
		*(p + i) = 0;
	}
	for (i = 0; i < 5; i++) {
		printf("%d ",arr[i]);
	}
	


	return 0;
}