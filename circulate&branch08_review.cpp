#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
/*
	f10逐过程调试		—>只展示主函数中的过程
	f11逐语句调试		—>展示整个程序的过程，包括其他被调函数
*/
void test1() {
	int i = 0;
	while (i<10) {
		printf("%d\n",i);
		i++;
	}
}


int main() {

	test1();

	int arry[] = { 9,2,4,7,5,1,3,3,5,1,77 },temp=0;
	printf("排序前:");
	for (int k = 0; k < sizeof(arry) / sizeof(int); k++)
		printf("%d ",arry[k]);


	for(int i=0;i<(sizeof(arry)/sizeof(int))-1;i++)				//冒泡排序大到小
		for (int j = 0; j < (sizeof(arry) / sizeof(int)) - 1; j++) {
			if (arry[j] < arry[j + 1]) {
				temp = arry[j];
				arry[j] = arry[j + 1];
				arry[j + 1] = temp;
			}
		}


	printf("\n排序后:");
	for (int k = 0; k < sizeof(arry) / sizeof(int); k++)
		printf("%d ", arry[k]);



	for (int m = 3; m <= 100; m += 3)			//打印三的倍数
			printf("\n%d",m);

	//打印两个数的最大公约数				最大公约数:两个数共同的最大因数
	//1.穷举法
	int num1, num2,value,min;
	printf("请输入两个整数:");
	scanf("%d%d", &num1, &num2);
		min = num1;
	if (num1 > num2)
		min = num2;
	for (int p = min; p >= 1; p--) {
		if ((num1 % p == 0) && (num2 % p == 0)) {
			value = p;
			break;
		}	
	}
	printf("最大公约数是：%d\n",value);
	//2.辗转相除法(欧几里得算法)		原理:数学定理,递归迭代，逐步缩小问题规模
	/*
		初始:较大数除较小数，余数为0结果为较小数,余数不为0迭代
		迭代:上一轮较小数和余数迭代成新一轮的两个数，较大数除较小数，余数为0结果为较小数,不为0迭代


		tip:初始部分不用在意两个数的大小问题，因为进行一次迭代后，两个数就会调整为正确顺序
		例如:c=18;b=24;t=18%24—>t=18
		迭代:c=24;b=18;t=24%18—>t=6
		...
	*/
	int c, b, y;
	printf("请输入两个整数:");
	scanf("%d%d", &c, &b);
	if (c<b) {
		int temp = c;
		c = b;
		b = temp;
	}
	do {
		y = c % b;
		if (y != 0) {
			c = b;
			b = y;
		}
	} while (y != 0);
		printf("最大公约数是:%d",b);
	//求两个数的最小公倍数		18 24
	//方法1:穷举法
		int q, w,e;
		printf("\n请输入两个整数:");
		scanf("%d%d", &q, &w);
		if (q > w)
			e = q;
		else
			e = w;
		while (1) {
			if (e % q == 0 && e % w == 0)
				break;
			e++;
		}
		printf("\n两个数的最小公倍数:%d\n",e);

		//方法2:公式法
		//最小公倍数=m*n/最大公约数
		int x = (num1 * num2) / value;
		printf("num1和num2的最小公倍数是:%d\n",x);

		//总结技巧:最大公约数看较小,最小公倍数看较大
		//学会举一反三


	/*
	打印1000-2000之间的闰年		1.能被400整除	2.能被4整除但不能被100整除
	*/
		int count = 0;
		for (int year = 1000; year <= 2000; year++) {
			if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
				printf("%d年是闰年\n", year);
				count++;
			}
				
		}
		printf("一共有%d个闰年\n",count);
	/*
	打印100-200之间的素数		素数：只能被1和自己整除
	*/
	//1.
		int su = 100;
		while (su <= 200) {
			int flag = 1;
			for (int temp = 2; temp < su; temp++) {
				if (su % temp == 0) {
					flag = 0;
					break;
				}
			}
			if (flag)
				printf("%d ",su);
				su++;
		}
		putchar('\n');
		//2.

		int su2 = 100,temp2;
		while (su2 <= 200) {
			for (temp2 = 2; temp2 < su2; temp2++) {
				if (su2 % temp2 == 0) {
					break;
				}
			}

			if (temp2==su2)
				printf("%d ", su2);
			su2++;
		}
		//3.优化	数学思路
		/*
			su2，如果不是素数则可以因式分解，写成a*b的形式,su2=a*b;
			那么a和b中至少有一个是<=su2开平方根的，例如16=2*8=4*4；

			所以只要判断出：
			su2能被较小的一个数整除,那么su2就不是素数,另一个对应的因子就不用再去进行除法判断了
			如果所有因式分解中较小的那个数都不能被su2整除，那么剩下的那些对应的因子也一定不能被su2整除

			而较小的那个数一定是<=sqrt(su2)的
			所以只需要判断从2到su2的平方根之间的数即可

			sqrt()函数：开平方函数		头文件:matn.h

		进一步优化		数学思路2
		因为除了2以外，所有的偶数一定不是质数
		所以可以先把除2外的所有偶数排除掉，再在2和奇数中去判断素数


		*/
		putchar('\n');

		int su3 = 101, temp3;			//排除2以外的偶数
		while (su3 <= 200) {
			for (temp3 = 2; temp3 <= sqrt(su3); temp3++) {
				if (su3 % temp3 == 0) {
					break;
				}
			}

			if (temp3 > sqrt(su3))
				printf("%d ", su3);
			su3+=2;						//排除2以外的偶数
		}
		
		putchar('\n');







		return 0;
	
}