#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//二分查找复刻

//冒泡排序
void arrysort(int* p,int num) {
	for(int i=1;i<num;i++)
		for (int j = 0; j < num - i; j++) {		//-i每轮排出的一个最大数，下轮则不需要再排
			if (p[j] > p[j + 1]) {
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
}
//二分查找
void arryfind(int* pp,int num,int num2){
	int left = 0, right = num - 1, mid;
	while (left<=right) {
		mid = (left + right) / 2;
		if (pp[mid] == num2) {
			printf("找到了\n");
			break;
		}
		else if (pp[mid] < num2) {
			left = mid + 1;
		}
		else
			right = mid - 1;

	}
	if (left > right)
		printf("没找到\n");

}





int main() {
	int arry[10],x;
	int numlong = sizeof(arry) / sizeof(int);
	printf("请输入10个数：");
	for (int i = 0; i < 10; i++)
		scanf("%d",&arry[i]);
	arrysort(arry,numlong);
	printf("排序后:");
	for (int i = 0; i < 10; i++)
		printf("%d ", arry[i]);
	putchar('\n');
	printf("请输入要查找的数:");
	scanf("%d",&x);
	arryfind(arry, numlong, x);
}