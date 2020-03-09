#include "SOKOBAN.h"
#include <iostream>
using namespace std;


int main()
{
	int **p = new int*[3];

	p[0] = new int[3]{ 10,20,30 };
	p[1] = new int[4]{ 11,21,31,41 };
	p[2] = new int[4]{ 12,22,32,42 };

	for (int i = 0; i < 3; i++)
	{
		int * pRemove = p[i];
		delete[] pRemove;
	}

	Run();
}