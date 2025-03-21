#define _CRT_SECURE_NO_WARNINGS 1
#include "SaoLei.h"				//涉及到坐标轴,最好在屏幕打印轴向--避免传统行列和数学坐标轴的混乱

void game() {
	//打印菜单						
	void Menu();					//优化视觉:单独放主函数显示，更好实现清屏幕
	//定义参数
	char real[ROWS][COLS];			//信息存储棋盘	A雷,a无雷
	char show[ROWS][COLS];			//信息展示棋盘	*未知或无雷,x雷,
	int guessx, guessy,flag;
	char Status=0;
	//初始化棋盘
	Reboard(real,'a');
	Reboard(show, '*');
	//随机布雷
	RandPlant(real, show);
	//打印棋盘
	PrintBoard(show);
	//玩家扫雷
	while (1) {				//判断合法性
		do {
			printf("请输入坐标>");
			scanf("%d%d", &guessx, &guessy);
			flag = !(guessx >= 1 && guessx <= ROW && guessy >= 1 && guessy <= COL&&(real[guessx][guessy] == 'A'|| real[guessx][guessy] == 'a'));
			if(flag)
				printf("坐标非法\n");
		} while (flag);
		system("cls");					//清屏
		//获取游戏状态
		Status = Playerscan(real,show, guessx, guessy);
		if (Status != 'C')
			break;						//跳出游戏
		//打印棋盘
		PrintBoard(show);
	}

		//判断游戏结果
		if (Status == 'G') {
			show[guessx][guessy] = 'x';	//显示踩到的雷
			PrintBoard(show);
			printf("GAME OVER!\n");
	}else if (Status == 'W') {
			PrintBoard(show);
			printf("YOU WIN!\n");
		}
		Sleep(2500);					//延时清屏
		system("cls");
}

int main() {
	//定义参数				
	int choose;
	srand((unsigned int)time(NULL));
	do {
		Menu();
		printf("请输入>");
		scanf("%d",&choose);
		switch (choose){
		case 1:
			game();
			break;
		case 2:
			printf("Game exited!\n");
			break;
		default:
			printf("输入错误!\n");
			break;
		}
	} while (choose!=2);

	return 0;
}