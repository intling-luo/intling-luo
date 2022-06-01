#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<graphics.h>


#define ROW 10//行 
#define COL 10//列 
#define NUM 10//雷 
#define SIZE 90

int map[ROW + 2][COL + 2];
IMAGE img[12];//img存放12张图


void GameInit()//初始化 
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < ROW + 2; i++)
	{
		for (int j = 0; j < COL + 2; j++)
		{
			map[i][j] = { 0 };
		}
	}
	for (int n = 0; n < NUM; n++)//布置雷 
	{
		int r = rand() % ROW + 1;//随机行 
		int c = rand() % COL + 1;//随机列 

		if (map[r][c] == 0)
		{
			map[r][c] = -1;
		}
	}
}

void GameNum()//扫出的数字
{
	for (int i = 1; i < ROW + 1; i++)
	{
		for (int j = 1; j < COL + 1; j++)
		{
			if (map[i][j] != -1)
			{
				for (int m = i - 1; m <= i + 1; m++)
				{
					for (int n = j - 1; n <= j + 1; n++)
					{
						if (map[m][n] == -1)
						{
							map[i][j]++;
						}
					}
				}
			}
		}
	}
}

void GameDraw()//打印 
{
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			printf("%2d", map[i][j]);
			if (map[i][j] == -1)
			{
				putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[9]);//雷
			}

			else if (map[i][j] >= 0 && map[i][j] <= 8)
			{
				putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[map[i][j]]);
			}
			else if (map[i][j] >= 19 && map[i][j] <= 28)
			{//空白
				putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[10]);
			}
			else if (map[i][j] > 30)
			{//标记
				putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[11]);
			}
		}
		printf("\n");
	}
}



int main()
{
	initgraph(ROW * SIZE, COL * SIZE, SHOWCONSOLE);
	loadimage(&img[0], L"0.png", 90, 90);//空
	loadimage(&img[1], L"1.png", 90, 90);//雷
	loadimage(&img[2], L"2.png", 90, 90);
	loadimage(&img[3], L"3.png", 90, 90);
	loadimage(&img[4], L"4.png", 90, 90);
	loadimage(&img[5], L"5.png", 90, 90);
	loadimage(&img[6], L"6.png", 90, 90);
	loadimage(&img[7], L"7.png", 90, 90);
	loadimage(&img[8], L"8.png", 90, 90);//数字
	loadimage(&img[9], L"9.png", 90, 90);//雷
	loadimage(&img[10], L"10.png", 90, 90);//背景
	loadimage(&img[11], L"11.png", 90, 90);//标记

	GameInit();
	GameNum();
	GameDraw();
	while (1);
	return 0;
}