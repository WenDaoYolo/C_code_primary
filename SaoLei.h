#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define ROW 9																//定义棋盘参数
#define COL 9
#define	ROWS ROW+2
#define	COLS COL+2

void Menu();																//打印游戏菜单
void Reboard(char arr[ROWS][COLS], char flag);								//初始化棋盘
void PrintBoard(char arr[ROWS][COLS]);										//打印棋盘
void RandPlant(char arr[ROWS][COLS],char arr2[ROWS][COLS]);					//随机布雷
char Playerscan(char arr[ROWS][COLS],char arr2[ROWS][COLS],int x,int y);	//获取游戏状态	C踩雷 W游戏胜利 C游戏继续
int isHow(char arr[ROWS][COLS], int x, int y);								//排雷算法,返回雷数	左右扩散->上下扩散