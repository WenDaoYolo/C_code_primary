#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
/*
		项目实例：猜数字游戏
		1.随机给一个1到100的数字
		2.猜数字，猜对结束本轮游戏，猜错会提示猜大或猜小，然后继续猜直到才对为止
		3.游戏可以一直进行，直到退出程序为止
*/
void menu(){
	printf("*---------------------------------------------*\n");
	printf("|MENU:            1.play                      |\n");
	printf("|                 2.exit                      |\n");
	printf("*---------------------------------------------*\n");
}

void menu2(int value1,int value2) {
	printf("*---------------------------------------------*\n");
	printf("|RESULT:          本轮猜测次数:%d              |\n",value1);
	printf("|                 历史最少次数:%d              |\n",value2);
	printf("*---------------------------------------------*\n");
}

void game() {
	int num,result,count=0;
	static int his_count=100;
	result = (rand()%100)+1;
	while (1){
		printf("请输入:");
		scanf("%d", &num);
		if (num<=100&&num>=1){
			if (num > result)
			{
				printf("猜大了!\n");
				count++;
			}
			else if (num < result)
			{
				printf("猜小了!\n");
				count++;
			}
			else {
				count++;
				printf("\a恭喜猜对了!\n");
				Sleep(2000);
				system("cls");
				break;
			}
		}
		else
			printf("error!\n");
		}
	if (count < his_count)
		his_count = count;
	menu2(count,his_count);
	}

void judge(){
	int choose, flag = 1;
	do {
		menu();
		scanf("%d", &choose);
		switch (choose) {
		case 1:
			printf("猜1到100的数字 ");
			game();
			break;
		case 2:
			flag = 0;
			break;
		default:
			printf("输入错误!\n");
			break;
		}

	} while (flag);
}

int main() {
	srand((unsigned int)time(NULL));
	judge();
	printf("程序已退出!\n");
	return 0;
}




