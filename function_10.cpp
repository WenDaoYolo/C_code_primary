#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//非递归非字符串操作函数
void Reverese(char* arry){
	int i = 0,j=0;
	while (arry[j] != '\0')
		j++;		//获取最后元素的下标
	j = j - 1;		//最大下标为元素个数-1,(避免将\0交换到第一个元素，否则字符串格式输出遇到\0则直接结束)
	for (; i <= j; i++, j--) {		//双下标操作
		char temp = arry[i];		
		arry[i] = arry[j];
		arry[j] = temp;
	}

}
int mystrlen(char* arry1) {
	int count = 0;			//模拟strlen获取字符串内容长度
	while (*arry1!='\0') {
		count++;
		arry1++;
	}
	return count;
}

/*

		分析，例如abcdef逆序,
		可以拆分为af的逆序+中间字符的逆序
		再拆分为af的逆序，be的逆序，和中间字符的逆序(即cd)
		由此可以判断出最小最简单的事件：为两个字符的逆序
		参与条件判断的量则为两个指针，通过不断传入+1-1来进行变化
		限制条件则为(左指针地址+1与右指针地址相等)并且(左指针与右指针地址相等)—>考虑到奇数个字符的问题

		达到限制条件开始回溯执行	——>回溯每个函数，从字符串的中间开始向两边，进行每一对数的交换

*/

//思路一:通过双指针控制两端的变化
void Reverese2(char* arry,char* arry2) {	
	if ((arry!=arry2)&&((arry+1)!=arry2))	//地址是否相等作为限制条件，并判断有没有遍历完每一对数
		Reverese2(arry+1,arry2-1);
		char temp = *arry;
		*arry = *arry2;
		*arry2 = temp;
}


//思路二：使用单指针控制首端,通过字符串\0的特性来控制尾端的变化
void Reverese3(char* arry1) {
	int tmp = *arry1;
	int right = mystrlen(arry1) - 1;
	*arry1 = *(arry1 + right);
	*(arry1 + right) = '\0';//尾部字符串赋值\0,创造条件判断量的变化->每次完成首指针的++和尾部的缩小,求出的字符串长度就会变小
	if(mystrlen(arry1)>=2)	//条件限制：去判断字符串的长度
	Reverese3(arry1 + 1);	//首端的变化
	*(arry1 + right) = tmp;
}
/*


与思路一不同的是：
思路一的条件限制和条件判断量变化的不同,替换操作是两边同时进行
而单指针的思路,先替换完左边，再回溯替换右边：调用过程中一层一层地先将左边的元素暂时存起来，然后替换成右边的元素，
结束调用后开始回溯，存起来的元素赋值给右边的元素来完成替换


本质上都是通过两端的变化来控制递归，只是方式不同

一个是两端指针通过++--来向中间靠拢，通过是否重叠来限制

一个是首端指针++和尾端赋\0来缩小字符串，然后通过求字符串的长度是否大于等于2来限制
(即首元素到尾元素一共有多少个字符,若长度为2则表示偶数字符只剩首尾则不需要再调用，
 若长度为1，则表示奇数字符,只剩最中间的元素,则不需要去交换)

*/
int main(){

	//递归和非递归实现，一个函数将字符串逆序存储，不能使用操作字符串的相关函数
	//迭代方法	
		char arry1[] = "!gnirts olleh";
		Reverese(arry1);		//非递归
		printf("%s",arry1);
		putchar('\n');
		char arry2[] = "?uoy era erehw";
		int x=mystrlen(arry2)-1;
		Reverese2(arry2,arry2+x);//递归1
		printf("%s\n", arry2);
		Reverese3(arry2);		//递归2
		printf("%s", arry2);
		
		putchar('\n');

		//输出乘法口诀表，行数和列数自己定，例如输入9，输出9*9的乘法表，输入12，输出12*12的乘法表
		int n = 0;
		printf("请输入数字:");
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++)
				printf("%d*%d=%d ", j, i, j * i);

			putchar('\n');

		}



	return 0;
}