#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//冒泡排序
void Sort(int arr[],int num) {
	int i = 0, j = 0;
	for (i = 0; i < num-1;i++) {
		for (j = 0; j < num - 1 - i;j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				}
		}
	}


}
 //打印数组
void PrintArr(int arr[],int num) {
	int i = 0;
	while (i < num) {
		printf("%d ",arr[i]);
		i++;
	}
	putchar('\n');
}

//初始化数组为0
void ReArr(int arr[],int num) {
	int i = 0;
	while (i < num) {
		arr[i] = 0;
		i++;
	}
}

//逆序1
void Reverse(int arr[],int num) {
	int left = 0, right = num - 1;
	while (left < right) {
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
}

//逆序2				递归思维
void Reverse2(int* lp,int* rp) {
	if ((lp != rp) && (lp + 1 != rp)) {
		Reverse2(lp + 1, rp - 1);
	}

	{
		int temp = *lp;
		*lp = *rp;
		*rp = temp;
	}
	
}

//交换数组内容	->数组一样大
void SwapArr(int arr1[],int arr2[],int num) {
	int i = 0;
	while (i < num) {
		int temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
		i++;
	}
}

	//数组名是常量,是不可修改的左值!!

int main() {
	int arr[] = { 1,2,3,6,6,12,91,44,1002,11 };
	int arr2[] = { 2,3,4,5,6,7 };
	int arr3[] = { 1,2,3,4,5,5,3,8,9,10 };
	int arr4[] = { 1,2,2,2,4,5,6,7 };
	int test1[] = { 1,2,3,4,5 };
	int test2[] = { 6,7,8,9,10 };
	int num = sizeof(arr) / sizeof(int);
	int num2 = sizeof(arr2) / sizeof(int);
	int num3= sizeof(arr3) / sizeof(int);
	int num4 = sizeof(arr4) / sizeof(int);
	printf("排序前:");
	PrintArr(arr, num);
	Sort(arr, num);
	printf("排序后:");
	PrintArr(arr, num);
	putchar('\n');
	printf("初始前:");
	PrintArr(arr2, num2);
	printf("初始后:");
	ReArr(arr2,num2);
	PrintArr(arr2,num2);
	printf("逆序前:");
	PrintArr(arr3,num3);
	Reverse(arr3,num3);
	printf("逆序后:");
	PrintArr(arr3, num3);
	printf("逆序前:");
	PrintArr(arr4, num4);
	printf("逆序后:");
	Reverse2(arr4, &arr4[num4 - 1]);
	PrintArr(arr4, num4);

	printf("交换前:\n");
	PrintArr(test1,sizeof(test1)/sizeof(int));
	PrintArr(test2,sizeof(test2) / sizeof(int));
	SwapArr(test1,test2, sizeof(test1) / sizeof(int));
	printf("交换后:\n");
	PrintArr(test1, sizeof(test1) / sizeof(int));
	PrintArr(test2, sizeof(test2) / sizeof(int));
	return 0;
}