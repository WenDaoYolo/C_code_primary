#define _CRT_SECURE_NO_WARNINGS 1
#include "SaoLei.h"

void Menu() {				
	printf("*************************************\n");
	printf("*** Menu:                         ***\n");
	printf("***          1.play               ***\n");
	printf("***          2.exit               ***\n");
	printf("***                               ***\n");
	printf("*************************************\n");
}

void Reboard(char arr[COLS][ROWS], char flag) {
	int i = 0,j = 0;
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
				arr[i][j] = flag;
		}
	}
}

void PrintBoard(char arr[ROWS][COLS]) {									//windows函数了解基础即可,暂不学习
	int i = 0, j = 0;													//system("color 14")				      设置全局字体颜色和背景颜色		
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);		//将控制台输出字符的颜色更改为绿色
	for (int k = 0; k <= 9; k++)					//打印横轴
		printf("%d ",k);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		//将控制台输出字符的颜色更改为白色(还原)
	putchar('\n');
																		//可以自定义写一个专门局部控制字体颜色的函数,避免重复且数量庞大的代码
	for (i = 1; i < ROWS-1; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);	//将控制台输出字符的颜色更改为绿色
		printf("%d ",i);							//打印纵轴
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//将控制台输出字符的颜色更改为白色(还原)
		for (j = 1; j < COLS-1; j++) {
			printf("%c ",arr[i][j]);
		}
		putchar('\n');
	}
	printf("-------------------\n");
	printf("mines:21\n");
}

void RandPlant(char arr[ROWS][COLS],char arr2[ROWS][COLS]) {
	for (int i = 1; i <=21;i++) {					//设置等级变换雷的数量,显示雷的数量	  雷的数量越多,布雷的过程就越长,程序不复杂,可以暂时忽略不计(雷不要超出棋盘数!)
		while (1) {
			int x = rand()%9+1;						//设置范围1-9
			int y = rand()%9+1;
			if (arr[x][y]=='a') {					//x >= 1 && x <= 9 && y >= 1 && y <= 9&&
							arr[x][y] = 'A';
							//arr2[x][y] = 'x';	    //用于代码预测,展示棋盘需要隐藏
							break;
			}
		}
	}
}

//排雷算法
int isHow(char arr[ROWS][COLS],int x,int y) {
	int count = 0;
	int i = 0, j = 0;
	for (i = x - 1;i <= x + 1;i++) {
		for (j = y - 1; j <= y + 1;j++) {
			if (arr[i][j] == 'A')
				count++;
		}
	}
	return count;
}

char Playerscan(char arr[ROWS][COLS], char arr2[ROWS][COLS],int x, int y) {
	if (arr[x][y] == 'A')							//arr完成对比,arr2对应展示
		return 'G';
	arr2[x][y] = isHow(arr, x, y) + '0';			//转换为字符'n'	    0的ASCLL码+偏移量n=n的ASCLL码值
	arr[x][y] = 'n';								//同步更新信息棋盘,判断坐标的重复、游戏的继续、游戏的胜利

	for(int i=1;i<=ROW;i++)
		for(int j=1;j<=COL;j++)
			if (arr[i][j]=='a') {
				return 'C';
			}

	return 'W';
}