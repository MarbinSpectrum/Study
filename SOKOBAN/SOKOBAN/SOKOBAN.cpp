#include <iostream>
#include <windows.h>        // system 함수를 위해 추가
#include <conio.h>          // khit 함수를 위해 추가
#include <time.h>
#include <vector>

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

#define WIDTH 19
#define HEIGHT 11

using namespace std;

struct Vector2
{
	int x;
	int y;
};

Vector2 playerPos;
vector<Vector2> boxPos;
vector<Vector2> targetPos;

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

int gameMap[HEIGHT][WIDTH] =
{
	{'□','□','□','□','■','■','■','■','■','□','□','□','□','□','□','□','□','□','□'},
	{'□','□','□','□','■','□','□','□','■','□','□','□','□','□','□','□','□','□','□'},
	{'□','□','□','□','■','▣','□','□','■','□','□','□','□','□','□','□','□','□','□'},
	{'□','□','■','■','■','□','□','▣','■','■','□','□','□','□','□','□','□','□','□'},
	{'□','□','■','□','□','▣','□','▣','□','■','□','□','□','□','□','□','□','□','□'},
	{'■','■','■','□','■','□','■','■','□','■','□','□','□','■','■','■','■','■','■'},
	{'■','□','□','□','■','□','■','■','□','■','■','■','■','■','□','□','▒','▒','■'},
	{'■','□','▣','□','□','▣','□','□','□','□','□','□','□','□','□','□','▒','▒','■'},
	{'■','■','■','■','■','□','■','■','■','□','■','♥','■','■','□','□','▒','▒','■'},
	{'□','□','□','□','■','□','□','□','□','□','■','■','■','■','■','■','■','■','■'},
	{'□','□','□','□','■','■','■','■','■','■','■','□','□','□','□','□','□','□','□'}
};

bool checkBoxPos(int x, int y)
{
	for (int i = 0; i < boxPos.size(); i++)
		if (boxPos[i].x == y && boxPos[i].y == x)
			return true;

	return false;
}

int getBox(int x,int y)
{
	for (int i = 0; i < boxPos.size(); i++)
		if (boxPos[i].x == y && boxPos[i].y == x)
			return i;

	return -1;
}

bool checkPlayerPos(int x, int y)
{
	if (playerPos.x == y && playerPos.y == x)
		return true;

	return false;
}



void Render()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			SetPos(2*x, y);
			if (checkBoxPos(x, y))
			{
				textcolor(BROWN, GREEN);
				printf("▣");
			}
			else if (checkPlayerPos(x, y))
			{
				textcolor(RED, GREEN);
				printf("♥");
			}
			else
			{
				switch (gameMap[y][x])
				{
				case '□':
					textcolor(GREEN, GREEN);
					printf("  ");
					break;
				case '■':
					textcolor(WHITE, GREEN);
					printf("■");
					break;
				case '▒':
					textcolor(CYAN, GREEN);
					printf("※");
					break;
				}
			}

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

				Vector2 movePos;
				movePos.x = playerPos.x;
				movePos.y = playerPos.y;

				switch (key)
				{
				case LEFT: movePos.y--;
					break;
				case RIGHT: movePos.y++;
					break;
				case UP: movePos.x--;
					break;
				case DOWN: movePos.x++;
					break;
				}

				bool canMove = true;
				if (movePos.x < 0)
					canMove = false;
				if (movePos.x >= HEIGHT)
					canMove = false;
				if (movePos.y < 0)
					canMove = false;
				if (movePos.y >= WIDTH)
					canMove = false;

				if (gameMap[movePos.x][movePos.y] == '■')
					canMove = false;

				int boxN = getBox(movePos.y, movePos.x);

				if (boxN != -1)
				{
					//LEFT
					if (playerPos.y == movePos.y + 1 && playerPos.x == movePos.x)
					{
						if (gameMap[movePos.x][movePos.y - 1] != '■'&& getBox(movePos.y - 1, movePos.x) == -1)
						{
							boxPos[boxN].x = movePos.x;
							boxPos[boxN].y = movePos.y - 1;
						}
						else
							canMove = false;
					}
					//RIGHT
					else if ((playerPos.y == movePos.y - 1 && playerPos.x == movePos.x))
					{
						if (gameMap[movePos.x][movePos.y + 1] != '■' && getBox(movePos.y + 1, movePos.x) == -1)
						{
							boxPos[boxN].x = movePos.x;
							boxPos[boxN].y = movePos.y + 1;
						}
						else
							canMove = false;
					}
					//UP
					else if ((playerPos.y == movePos.y && playerPos.x == movePos.x - 1))
					{
						if (gameMap[movePos.x + 1][movePos.y] != '■' && getBox(movePos.y, movePos.x + 1) == -1)
						{
							boxPos[boxN].x = movePos.x + 1;
							boxPos[boxN].y = movePos.y;
						}
						else
							canMove = false;
					}
					//DOWN
					else if ((playerPos.y == movePos.y && playerPos.x == movePos.x + 1))
					{
						if (gameMap[movePos.x - 1][movePos.y] != '■' && getBox(movePos.y, movePos.x - 1) == -1)
						{
							boxPos[boxN].x = movePos.x - 1;
							boxPos[boxN].y = movePos.y;
						}
						else
							canMove = false;
					}
				}

				if (canMove)
				{
					playerPos.x = movePos.x;
					playerPos.y = movePos.y;
				}
				break;

			}
		}
	}
}

void Init()
{
	int boxC = 0;
	int targetC = 0;
	
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (gameMap[y][x] == '▒')
			{
				Vector2 emp;
				emp.x = y;
				emp.y = x;
				targetPos.push_back(emp);
			}
			else if (gameMap[y][x] == '▣')
			{
				gameMap[y][x] = '□';
				Vector2 emp;
				emp.x = y;
				emp.y = x;
				boxPos.push_back(emp);
			}
			else if (gameMap[y][x] == '♥')
			{
				gameMap[y][x] = '□';
				playerPos.x = y;
				playerPos.y = x;
			}
		}
	}
	
}

bool Clear()
{
	int count = 0;
	for (int i = 0; i < targetPos.size(); i++)
	{
		for (int j = 0; j < boxPos.size(); j++)
		{
			if (targetPos[i].x == boxPos[j].x && targetPos[i].y == boxPos[j].y)
			{
				count++;
				break;
			}
		}
	}

	return count >= targetPos.size();
}

void Run()
{

	Init();
	while(1)
	{
		Render();
		Input();
		system("cls");

		if (Clear())
			break;
	}

	textcolor(RED, BLACK);
	printf("Clear!!");
	textcolor(WHITE, BLACK);
}