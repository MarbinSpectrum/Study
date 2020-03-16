#include<iostream>
#include"Vector2.h"

using namespace std;

int main()
{
	Vector2 pos1(2, 3);
	Vector2 pos2(4, 5);
	Vector2 pos3;

	cout << "pos1 = (" << pos1.x << "," << pos1.y << ")" << endl;
	cout << "pos2 = (" << pos2.x << "," << pos2.y << ")" << endl;

	pos3 = pos1 + pos2;
	cout << "pos1 + pos2 = (" << pos3.x << "," << pos3.y << ")" << endl;

	pos3 = pos1 - pos2;
	cout << "pos1 - pos2 = (" << pos3.x << "," << pos3.y << ")" << endl;

	pos3 = pos1 * 3;
	cout << "pos1 * 3 = (" << pos3.x << "," << pos3.y << ")" << endl;

	pos3 = pos1  / 3;
	cout << "pos1 / 3 = (" << pos3.x << "," << pos3.y << ")" << endl;

	pos3 = Vector2::zero();
	cout << "pos3 = Vector2::zero(); --> (" << pos3.x << "," << pos3.y << ")" << endl;

	pos3 += pos1;
	cout << "pos3 += pos1; --> (" << pos3.x << ", " << pos3.y << ")" << endl;
}