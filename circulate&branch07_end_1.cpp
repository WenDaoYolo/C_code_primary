#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>



void testsort(int* a,int num) {									//通过指针直接操作主调程序中的数组
	int temp;													//定义了一个冒泡排序的函数(从小到大)
	for (int j = 1; j <= (num - 1); j++)
		for (int i = 0; i <(num-1); i++){					//sizeof的使用事项：
			if (a[i] > a[i + 1]) {							//sizeof(数组名)则是求整个数组的长度
				temp = a[i];								//sizeof(指针变量)求的是指针变量的大小(和机器字长有关),而不是指针指向对象的大小
				a[i] = a[i + 1];							//但在自定义函数中，无论是用数组还是指针来接收传入的数组,都会退化为指针,所以用sizeof求出来的都是指针的大小
				a[i + 1] = temp;							//存储接收数组的方法：1.定义数组接收   2.定义指针接收
			}												//<指针访问数组>的方法:定义指针变量a-->1.下标法a[i]   2.指针法*(a+n)———>数组中元素的地址都是连续的
															//									   数组就采用下标法：数组名本身就是地址
		}
		
}



int testfind(int b[],int n,int arryL){					//定义了二分查找函数testfind
	int r = 0, s = arryL-1,value=NULL;							//算法的写法不唯一，但思路都是大体一致的
	while(1){											//写法2:条件可以改为r<=s(即左小于右)作为循环条件，用来终止循环———或者b[t]!=n
		int t = (r + s) / 2;							
		if (b[t] < n)
			r = t + 1;
		else if (b[t] > n)
			s = t - 1;
		else if (b[t] == n) {
			value = t;
			break;										//写法2:去掉break用whie的条件语句来控制循环	
		}

		if (r>s){
			printf("未查找到元素\n");				//若最后剩的一个元素也不等于n则未查找到——>是最数组中最接近目标数的元素
			break;
		}
		}
			
	return value;							//返回匹配到的结果
}



int main(){
	/*
	三种循环的练习
	

	*/
	//有序数组中查找某个具体数字n(数组中存在的,不存在以下写法就会死循环)							
	int v[] = { 33,44,55,19,18,17,100 }, n,y;
	printf("请输入要查找的数n:\n");
	scanf("%d",&n);
	for (int i = 0; i < sizeof(v)/sizeof(int);i++) {		//假设在不知道数组长度的情况下求数组大小:
		if (v[i] == n) {															   //整型数组总字节/整型字节大小
			y = i;								//i是局部变量，无法在循环体外未使用，需要将值存储到全局变量中
			break;								//若是字符数组(即字符串形式)，则需要考虑sizeof后再减一(字符串以'\0'结束也占一个字符)
												//可以考虑使用strlen(计算字符串的长度(\0只占空间，不记作字符串的内容))
		}							
	}
	printf("查找到%d\n",v[y]);	//注意此时i是定义在循环体内的局部变量，出了作用域则会销毁,无法被使用




	//每次都遍历整个数组来查找，效率太慢
	/*
	算法:二分查找法(折中查找法)
	前提:线性结构且有序(一个接一个，排成一排)
	原理:用数组下标和整数除法来定位,通过中间元素与目标元素的大小关系来判断,
		 不断的折中数组来缩小查找范围直至中间元素与目标元素相等
	时间复杂度:log2 N(数组长度)
	推理过程:
	时间复杂度为循环执行的次数,以算法的最坏情况为标准
	即数组进行m次除2折中后剩下的最后一个元素才为所求元素(最坏情况)
	N/2/2/2/2...(m次)
	N/2^m=1
	N=2^m
	m=log2 N
	*/

	int v1[] = { 3,4,5,6,1,2,3,4,100,1000,999,1001,520};
	printf("排序前的元素:\n");
	for (int i = 0; i < (sizeof(v1) / 4); i++)
		printf("%d ", v1[i]);
											//排序
	putchar('\n');
	testsort(v1,sizeof(v1)/4);				//将数组地址和数组长度传进去
			
	printf("排序后的元素:\n");
	for (int i = 0; i < (sizeof(v1) / 4); i++)
		printf("%d ", v1[i]);

	//排完序,开始二分查找法
	
	int n1,result,arryL=sizeof(v1)/sizeof(int);
	printf("\n请输入要查找的数n1:\n");
	scanf("%d",&n1);
	result = testfind(v1,n1,arryL);			//调用testfind函数,参数(数组,查找数,数组长度)
	if(result!=NULL)						//判断数组中是否存在元素
	printf("查找到%d", v1[result]);
	return 0;
}
