#define _crt_secure_no_warnings 1
#include<stdio.h>
#include<string.h>

/*
		练习2:和练习1一致,要逆序存储并输出

		三步翻转法
		1.整体翻转
		2.每个单词翻转
		例如:I like beijing
		ginjieb ekil I
		beijing like I
		思维:创建字符串逆序函数,逆序完成后再又对各个单词调用逆序函数

		地址与地址之间的算术比较(>,<,==),前提是两个地址处于同一块连续的空间
		比较的规则是高地址>低地址

*/


//实现字符串的逆序
void reverse(char* left,char* right) {
	int temp = 0;
	while (left<right) {					
		temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}


int main() {
	char arr1[100];							//数组地址从低到高依次增加	
	fgets(arr1, sizeof(arr1), stdin);		//fgets函数--暂不深入了解	mark				
	arr1[strcspn(arr1, "\n")] = 0;
	int num=strlen(arr1);
	reverse(arr1,arr1+num-1);

	//找到每个单词,对每个单词进行逆序
	char* start = arr1; char* end = arr1;
	while (*start != '\0') {
		end = start;
		while (*end != ' ' && *end != '\0') {
			end++;
		}
		reverse(start, end - 1);
		if (*end == ' ')
			start = end + 1;
		else
			start = end;
	}

	printf("\n%s\n", arr1);
	return 0;
}