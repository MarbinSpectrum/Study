#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>

#include "TETRIS.h"

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int Score = 0;

int gameTable[20][12] = 
{
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},	
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1}, 
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1}
};

int frame = 0;

Pos polygonType[6][4][4] =
{
	// ┌
	{
			{{-1,-1},{-1,+0},{+0,+0},{+1,+0} },
			{{-1,+1},{+0,+1},{+0,+0},{+0,-1} },
			{{+1,+0},{+1,-1},{+0,-1},{-1,-1} },
			{{+0,-1},{-1,-1},{-1,+0},{-1,+1} }
	},
	// ┐
	{
			{{-1,-1},{-1,+0},{+0,-1},{+1,-1} },
			{{+0,+1},{-1,-1},{-1,+0},{-1,+1} },
			{{+1,+0},{+1,-1},{+0,+0},{-1,+0} },
			{{-1,-1},{+0,+1},{+0,+0},{+0,-1} }
	},
	// │
	{
			{{+1,-1},{+0,-1},{-1,-1},{-2,-1} },
			{{-1,-2},{-1,-1},{-1,+0},{-1,+1} },
			{{+0,-1},{-1,-1},{-2,-1},{-3,-1} },
			{{-1,-3},{-1,-2},{-1,-1},{-1,+0} }
	},
	// ㅁ
	{
			{{+0,-1},{+0,+0},{+1,+0},{+1,-1} },
			{{+0,-1},{+0,+0},{+1,+0},{+1,-1} },
			{{+0,-1},{+0,+0},{+1,+0},{+1,-1} },
			{{+0,-1},{+0,+0},{+1,+0},{+1,-1} },
	},
	// 
	{
			{{+1,-1},{+0,-1},{+0,+0},{-1,+0} },
			{{+0,+1},{+0,+0},{-1,+0},{-1,-1} },
			{{+1,-1},{+0,-1},{+0,+0},{-1,+0} },
			{{+0,+1},{+0,+0},{-1,+0},{-1,-1} }
	},
	{
			{{-1,-1},{+0,-1},{+0,+0},{+1,+0} },
			{{+0,-1},{+0,+0},{-1,+0},{-1,+1} },
			{{-1,-1},{+0,-1},{+0,+0},{+1,+0} },
			{{+0,-1},{+0,+0},{-1,+0},{-1,+1} }
	}

};

Tetris::Tetris() : m_startPos(-1 ,6)
{
	m_gameEnd = 0;
	m_pos = m_startPos;
	m_polyType = 5;
	m_rotation = 0;
	m_time = 0;
	// 차후 게임을 생긴하기 위한 테이블 값
	memcpy(m_initTable, gameTable, sizeof(gameTable));

	//0.6초마다 도형이 떨어져나감
	m_gameSpeed = 300;
}

Tetris::~Tetris()
{

}

void Tetris::Input()
{
	Pos e_pos = m_pos;
	int e_rotaion = m_rotation;

	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();

			switch (key)
			{
			case LEFT :
				e_pos.col--;
				break;
			case RIGHT:
				e_pos.col++;
				break;
			case UP:
				e_rotaion++;
				break;
			case DOWN:
				e_pos.row++;
				break;
			}

			if (MoveCheck(e_pos.col, e_pos.row, m_polyType, e_rotaion % 4))
			{
				m_pos = e_pos;
				m_rotation = e_rotaion;
			}
		}
		else
		{
			for (int i = 0; i < 19; i++)
			{
				e_pos.row++;
				if (MoveCheck(e_pos.col, e_pos.row, m_polyType, e_rotaion % 4))
				{
					m_pos = e_pos;
					m_rotation = e_rotaion;
					m_time++;
				}
				else
					break;
			}
		}
	}
}

void Tetris::Init()
{
	srand(GetTickCount());

	m_polyType = rand() % 6;
	m_nextpolyType = rand() % 6;

	m_prevTime = GetTickCount();
}

void Tetris::Update()
{
	int elapsedTime = GetTickCount() - m_prevTime;
	if (elapsedTime > m_gameSpeed)
	{
		MoveDown(m_polyType, m_rotation % 4);
		m_prevTime = GetTickCount();
	}
}

void Tetris::Draw()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int r = 0; r < 20; r++)
	{
		for (int c = 0; c < 12; c++)
		{
			switch (gameTable[r][c])
			{
			case 0:
				SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
				printf("  ");
				break;
			case 1:
				SetConsoleTextAttribute(h, BACKGROUND_BLUE);
				printf("  ");
				SetConsoleTextAttribute(h, BACKGROUND_RED || BACKGROUND_GREEN || BACKGROUND_BLUE);
				break;
			case 2 :
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_GREEN);
				printf("▨");
				SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
				break;
			case 3:
				SetConsoleTextAttribute(h, FOREGROUND_GREEN);
				printf("▨");
				SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
				break;
			default :
				SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
			}
		}
		printf("\n");
	}
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
	SetPos(26, 0);
	printf("Score : %d",Score);
}

void Tetris::DrawPoly(int x, int y, int polyType, int rotation,const char *pStr, short color = FOREGROUND_RED | FOREGROUND_BLUE)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	for (int i = 0; i < 4; i++)
	{
		int rX = (x + polygonType[polyType][rotation][i].col) * 2;
		int rY = y + polygonType[polyType][rotation][i].row;
		if (/*rX >= 0 && rX < 24 &&*/ rY >= 0 && rY < 20)
		{
			SetPos(rX, rY);
			printf(pStr);
		}
	}
}

void Tetris::SetPos(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int Tetris::MoveCheck(int col, int row, int polyType, int rotation)
{
	for (int i = 0; i < 4; i++)
	{
		int Col = col + polygonType[polyType][rotation][i].col;
		int Row = row + polygonType[polyType][rotation][i].row;

		if (Col >= 0 && Col < 12 && Row >= 0 && Row < 20)
			if (gameTable[Row][Col] != 0)
				return 0;
	}
	return 1;
}

void Tetris::MoveDown(int polyType, int rotation)
{
	if (frame > 6 || true)
	{
		if (MoveCheck(m_pos.col, m_pos.row + 1, polyType, rotation))
		{
			m_pos.row++;
			m_time++;
		}
		else if(m_time > 0)
		{
			for (int i = 0; i < 4; i++)
			{
				int Col = m_pos.col + polygonType[polyType][rotation][i].col;
				int Row = m_pos.row + polygonType[polyType][rotation][i].row;
				if (Col >= 0 && Col < 12 && Row >= 0 && Row < 20)
					gameTable[Row][Col] = 2;
			}
			m_pos.row = -1;
			m_pos.col = 6;
			m_polyType = m_nextpolyType;
			m_nextpolyType = rand() % 6;
			m_rotation = 0;
			m_time = 0;

			for (int r = 1; r < 19; r++)
			{
				int check = r;
				for (int c = 1; c < 11; c++)
				{
					if (gameTable[r][c] != 2)
						check = 0;
				}
				if (check != 0)
				{
					Score += 100;
					DownBlocks(check);
				}
			}
		}
		else if(m_time == 0)
		{
			m_gameEnd = 1;
			for (int r = 0; r < 20; r++)
			{
				for (int c = 0; c < 12; c++)
				{
					if (gameTable[r][c] == 2)
						gameTable[r][c] = 3;
				}
			}
		}

		frame -= 6;
	}
	frame++;
}

void Tetris::DownBlocks(int n)
{
	for (int r = n; r >= 1; r--)
	{
		for (int c = 1; c < 11; c++)
		{
			gameTable[r][c] = gameTable[r - 1][c];
		}
	}
}

void Tetris::Run()
{
	Init();
	while (m_gameEnd == 0)
	{
		Input();
		Draw();
		Update();
		DrawPoly(m_pos.col, m_pos.row,m_polyType, m_rotation % 4,"▨");
		DrawPoly(15, 4, m_nextpolyType,0, "▨");
		system("cls");
	}
	Draw();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	printf("GAME OVER\n");
}
