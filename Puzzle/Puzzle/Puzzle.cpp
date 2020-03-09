#include <iostream>
#include <windows.h>        // system 함수를 위해 추가
#include <conio.h>          // khit 함수를 위해 추가
#include <time.h>

#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 

#define LEFT 75 
#define RIGHT 77 
#define UP 72
#define DOWN 80 
#define SPACE 32 

#define WIDTH 4

using namespace std;

int PuzzleMap[WIDTH][WIDTH];
int ax = 0;
int ay = 0;
int bx = -1;
int by = -1;
int flag = 0;

void SetPos(int x, int y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);	// 출력윈도우 식별자값 받음
	COORD c = { x , y };
	SetConsoleCursorPosition(h, c);
}

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void FindZero()
{
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (PuzzleMap[i][j] == WIDTH * WIDTH)
			{
				PuzzleMap[i][j] = 0;
				return;
			}
		}
	}
}

void Shuffle(int i)
{
	while (i--)
	{
		int a1 = rand() % (WIDTH * WIDTH);
		int a2 = rand() % (WIDTH * WIDTH);

		int e1x = a1 % WIDTH;
		int e1y = a1 / WIDTH;

		int e2x = a2 % WIDTH;
		int e2y = a2 / WIDTH;

		swap(PuzzleMap[e1x][e1y], PuzzleMap[e2x][e2y]);
	}
}

void Init()
{
	int count = 1;
	for (int i = 0; i < WIDTH; i++)
		for (int j = 0; j < WIDTH; j++)
			PuzzleMap[i][j] = count++;

	Shuffle(5);

	FindZero();
}



void DrawTable()
{
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			SetPos(j * 4, i);
			if (ax == by && ax == by && bx == j && by == i)
				textcolor(BLUE, BLACK);
			else if (ax == j && ay == i)
				textcolor(RED, BLACK);
			else if (bx == j && by == i)
				textcolor(CYAN, BLACK);

			if (PuzzleMap[i][j] != 0)
				printf("[%2d]", PuzzleMap[i][j]);
			else
				printf("[  ]");

			textcolor(WHITE, BLACK);
		}
		printf("\n");
	}
}



void Input()
{
	while (1)
	{
		if (_kbhit())
		{
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case LEFT: ax--;
					break;
				case RIGHT: ax++;
					break;
				case UP: ay--;
					break;
				case DOWN: ay++;
					break;
				}

				ax = ax < 0 ? 0 : ax;
				ax = ax >= WIDTH ? WIDTH - 1 : ax;
				ay = ay < 0 ? 0 : ay;
				ay = ay >= WIDTH ? WIDTH - 1 : ay;

				break;
			}
			else
			{
				if (flag == 0)
				{
					flag = 1;
					bx = ax;
					by = ay;
				}
				else
				{
					if (PuzzleMap[ay][ax] == 0 || PuzzleMap[by][bx] == 0)
					{
						if (ax == bx && by == ay - 1)
							swap(PuzzleMap[ay][ax], PuzzleMap[by][bx]);
						else if (ax == bx && by == ay + 1)
							swap(PuzzleMap[ay][ax], PuzzleMap[by][bx]);
						else if (bx == ax + 1 && ay == by)
							swap(PuzzleMap[ay][ax], PuzzleMap[by][bx]);
						else if (bx == ax - 1 && ay == by)
							swap(PuzzleMap[ay][ax], PuzzleMap[by][bx]);
					}
					flag = 0;
					bx = -1;
					by = -1;
				}
				break;
			}
		}
	}
}

bool Clear()
{
	bool clearCheck = true;
	int count = 1;
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (count == WIDTH * WIDTH)
				break;
			if (PuzzleMap[i][j] != count++)
				clearCheck = false;
		}
	}
	return clearCheck;
}

void Run()
{
	int iTime = time(0);
	srand(iTime);

	Init();

	do
	{
		DrawTable();
		Input();
		system("cls");
	} 
	while (!Clear());

	printf("Clear!!");
}