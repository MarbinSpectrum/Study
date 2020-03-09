#include <iostream>
#include "TETRIS.h"


int main()
{

	Tetris *pTetris = new Tetris;

	pTetris->Run();

	delete pTetris;
}
