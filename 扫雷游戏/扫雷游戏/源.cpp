#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<graphics.h>
#pragma comment(lib,"winmm.lib")
#include<Windows.h>

#define ROW 10//行 
#define COL 10//列 
#define NUM 10//雷 
#define SIZE 90

int count = 0;
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
	for (int i = 1; i < ROW + 1; i++)
	{
		for (int j = 1; j < COL + 1; j++)
		{
			map[i][j] += 20;
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
void OpenZero(int r,int c)
{
			for (int p = r - 1; p <= r + 1; p++)
			{
				for (int q = c - 1; q <= c + 1; q++)
				{
					if (map[p][q] == 20)
					{
						map[p][q] -= 20;
						count++;
						OpenZero(p, q);
					}
					else if (map[p][q] > 20 && map[p][q] <= 28)
					{
						map[p][q] -= 20;
						count++;
					}
				}
			}
}

int PlayGame()
{
	//定义鼠标消息
	MOUSEMSG msg = { 0 };
	int r, c;
	
	while (1)
	{
		msg = GetMouseMsg();
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN://翻开扫雷
			mciSendString(L"close dj", NULL, 0, NULL);
			mciSendString(L"open dianji.mp3 alias dj", 0, 0, 0);
			mciSendString(L"play dj", 0, 0, 0);
			r = msg.x / SIZE + 1;
			c = msg.y / SIZE + 1;
			if (map[r][c] >= 19 && map[r][c] <= 28)
			{
				if (map[r][c] == 20)
				{
					mciSendString(L"close jz", NULL, 0, NULL);
					mciSendString(L"open jizhong.mp3 alias jz", 0, 0, 0);
					mciSendString(L"play jz", 0, 0, 0);
					OpenZero(r ,c);
				}
				else if (map[r][c] != -1) {
					map[r][c] -= 20;
					count++;
				}
				return map[r][c];
				break;
		case WM_RBUTTONDOWN://标记空白 取消标记
			mciSendString(L"close jz", NULL, 0, NULL);
			mciSendString(L"open jizhong.mp3 alias jz", 0, 0, 0);
			mciSendString(L"play jz", 0, 0, 0);
			r = msg.x / SIZE + 1;
			c = msg.y / SIZE + 1;
			if (map[r][c] >= 19 && map[r][c] <= 28) 
			{
				map[r][c] += 50;
			}
			else if (map[r][c] >= 69)
			{
				map[r][c] -= 50;
				return map[r][c];
				break;
			}
			GameDraw();
			}
		}
	}
}


int main()
{
	
	mciSendString(L"open BGM.mp3 alias music", 0, 0, 0);
	mciSendString(L"open du.mp3 alias du", 0, 0, 0);
	
	mciSendString(L"open jizhong.mp3 alias jz", 0, 0, 0);
	mciSendString(L"play music", 0, 0, 0);

	HWND chuangkou=initgraph(ROW * SIZE, COL * SIZE);//定义并打开窗口

	loadimage(&img[0], L"0.png", SIZE,SIZE);//空
	loadimage(&img[1], L"1.png", SIZE, SIZE);//雷
	loadimage(&img[2], L"2.png", SIZE, SIZE);
	loadimage(&img[3], L"3.png", SIZE, SIZE);
	loadimage(&img[4], L"4.png", SIZE, SIZE);
	loadimage(&img[5], L"5.png", SIZE, SIZE);
	loadimage(&img[6], L"6.png", SIZE, SIZE);
	loadimage(&img[7], L"7.png", SIZE, SIZE);
	loadimage(&img[8], L"8.png", SIZE, SIZE);//数字
	loadimage(&img[9], L"9.png", SIZE, SIZE);//雷
	loadimage(&img[10], L"10.png", SIZE, SIZE);//背景
	loadimage(&img[11], L"11.png", SIZE, SIZE);//标记

	GameInit();
	GameNum();
	
	while (1)
	{
		
		GameDraw();
		if (PlayGame() == -1)
		{
			mciSendString(L"play du", 0, 0, 0);
			GameDraw();
			MessageBox(chuangkou, L"排查失败!", L"",MB_OK);
			break;
		}
		if (count >= ROW * COL - NUM) {
			GameDraw();
			MessageBox(chuangkou, L"你成功排查出了所有有毒礼物，获得了十三娘的称赞！", L"", MB_OK);
			break;
		}
	}
	return 0;
}