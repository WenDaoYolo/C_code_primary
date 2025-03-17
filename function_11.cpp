#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//递归和非递归实现计算一个数每位数字之和

int ReturnValue(int xt) {				//递归
	if (xt > 9)
		return xt % 10 + ReturnValue(xt / 10);
	else
		return xt;
}

int ReturnVlue1(int xt1) {				//迭代
	int sum = 0;
	while (xt1) {
		sum += xt1 % 10;
		xt1 /= 10;
	}
	return sum;
}

//递归和非递归实现n的k次方的值		


//递归
float ReturnValue2(int n,int k) {			//负数k
	if (k >=1)
		return n * ReturnValue2(n, k - 1);
	else if(k==0)
		return 1;
	else if(k<0)
		return (1.0/n) * ReturnValue2(n, k +1);	//或者1.0/ ReturnValue2(n, -k),--得正，走上面的return，然后将整个结果返给最下面的return再被1.0除上最后返给主函数
}

int ReturnValue3(int n, int k) {			//正数k
	if (k >= 1)
		return n * ReturnValue2(n, k - 1);
	else if (k == 0)
		return 1;
}
//迭代
int ReturnValue4(int x,int y) {						//正数k,负数略
	int res = 1;
	for (int i = 1; i <= y; i++) {
		res *= x;
	}
	return res;
}									





int main() {


	int n = 667766;
	int x=ReturnValue(n);
	printf("%d\n",x);

	int n1 = 123666111;
	int x1 = ReturnVlue1(n1);
	printf("%d\n", x1);

	putchar('\n');
	int n2 = 0, k = 0,n3=0,k2=0;
	printf("请输入n2,k;n3和k2:");
	scanf("%d%d%d%d",&n2,&k,&n3,&k2);
	float value2 = ReturnValue2(n2,k);
	printf("\n%d的%d次方是%f\n",n2,k,value2);
	int value3 = ReturnValue3(n3, k2);
	printf("\n%d的%d次方是%d\n", n3, k2, value3);
	int t = 0, y = 0;
	printf("请输入t,y:");
	scanf("%d%d", &t,&y);
	int value4 = ReturnValue4(t,y);
	printf("\n%d的%d次方是%d\n", t, y, value4);
	return 0;
}