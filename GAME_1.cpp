#define _CRT_SECURE_NO_WARNINGS 1
#include "SanZiQi.h"
								//思考:如何实现n子棋,为电脑设计一个更加智能的算法（自定义电脑难度）,掷色子决定先手,自定义棋盘符号,显示战绩,查看战绩...

void StartGame(){				//测试游戏逻辑函数

	char arr[ROW][COL];
	char Status;
	//初始化棋盘为空格
	Reboard(arr);
	//打印初始棋盘
	Printboard(arr);
	while (1) {
		//玩家走
		PlayerMove(arr);
		//打印棋盘		
		Printboard(arr);
		//获取游戏状态
		Status=IsGameStatus(arr);
		if (Status != 'c')
			break;

		//电脑走
		printf("电脑回合中...\n");
		ComputerMove(arr);
		Sleep(3500);
		//打印棋盘
		Printboard(arr);
		//获取游戏状态
		Status=IsGameStatus(arr);
		if (Status != 'c')
			break;
	}

	Sleep(1000);
	//判定游戏状态
	{
		if (Status == 'x')
			printf("Player win!\n");
		else if (Status == 'o')
			printf("Computer win!\n");
		else if(Status=='q')
			printf("Draw!\n");
	}
	Sleep(1000);
}

int main() {
	//定义参数
	int choose = 0;
	srand((unsigned int)time(NULL));
	//打印游戏菜单
	do{
		Menu();
		printf(">");
		scanf("%d",&choose);
		switch (choose) {
		case 1:
			StartGame();
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