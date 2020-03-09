#pragma once

typedef struct TetrisPosition
{
	int row;
	int col;

	TetrisPosition()
	{

	}

	TetrisPosition( int r , int c )
	{
		row = r;
		col = c;
	}
}Pos;

class Tetris
{
private :
	Pos m_pos;
	const Pos m_startPos;
	int m_gameEnd;
	int m_initTable[20][12];
	int m_rotation;
	int m_polyType;
	int m_nextpolyType;
	int m_time;
	unsigned int m_prevTime = 0;
	int m_gameSpeed;
public :
	Tetris();
	~Tetris();
private :
	void Input();
	void Init();
	void Update();
	void Draw();
	void DrawPoly(int x, int y, int polyType, int rotation, const char *pStr, short color);
	void SetPos(int x, int y);
	int MoveCheck(int col, int row, int polyType, int rotation);
	void MoveDown(int polyType, int rotation);
	void DownBlocks(int n);
public :
	void Run();
};