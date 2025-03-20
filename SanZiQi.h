#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define ROW 3															//棋盘参数配置
#define COL 3
void Menu();															//打印游戏菜单												
void Reboard(char arr[ROW][COL]);										//初始化棋盘为空格
void Printboard(char arr[ROW][COL]);									//打印棋盘
void PlayerMove(char arr[ROW][COL]);									//玩家移动-更新棋盘
void ComputerMove(char arr[ROW][COL]);									//电脑移动-更新棋盘
char IsGameStatus(char arr[ROW][COL]);									//获取游戏状态并返回	   x玩家赢 o电脑赢 q平局 c游戏继续