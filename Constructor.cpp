#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	Point(int a = 0, int b = 0);
	void setX(int a);
	void setY(int b);
	int getX() { return x; }
	int getY() { return y; }
	static int N;
	static void showN();
};

Point::Point(int a, int b)
{
	N++;
	x = a;
	y = b;
}

void Point::setX(int a)
{
	if (a > 10 || a < 0)
	{
		x = 0;
	}
	else
	{
		x = a;
	}
}

void Point::setY(int b)
{
	if (b > 10 || b < 0)
	{
		y = 0;
	}
	else
	{
		y = b;
	}
}

int Point::N = 0;

void Point::showN() 
{
	cout << "ÁÂÇ¥ÀÇ °³¼ö : " << N << '\n';
}
int main()
{
	Point p[3]
	{
		Point(),
		Point(),
		Point(3,7)
	};

	int input;
	cout << "X ÁÂÇ¥¸¦ ÀÔ·ÂÇÏ½Ê½Ã¿À.\n";
	cin >> input;
	p[0].setX(input);

	cout << "Y ÁÂÇ¥¸¦ ÀÔ·ÂÇÏ½Ê½Ã¿À.\n";
	cin >> input;
	p[0].setY(input);

	cout << "ÁÂÇ¥´Â(" << p[0].getX() << ',' << p[0].getY() << ")ÀÔ´Ï´Ù.\n";
	cout << "ÁÂÇ¥´Â(" << p[1].getX() << ',' << p[1].getY() << ")ÀÔ´Ï´Ù.\n";
	cout << "ÁÂÇ¥´Â(" << p[2].getX() << ',' << p[2].getY() << ")ÀÔ´Ï´Ù.\n";
	Point::showN();
}