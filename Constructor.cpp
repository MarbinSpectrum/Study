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
	cout << "��ǥ�� ���� : " << N << '\n';
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
	cout << "X ��ǥ�� �Է��Ͻʽÿ�.\n";
	cin >> input;
	p[0].setX(input);

	cout << "Y ��ǥ�� �Է��Ͻʽÿ�.\n";
	cin >> input;
	p[0].setY(input);

	cout << "��ǥ��(" << p[0].getX() << ',' << p[0].getY() << ")�Դϴ�.\n";
	cout << "��ǥ��(" << p[1].getX() << ',' << p[1].getY() << ")�Դϴ�.\n";
	cout << "��ǥ��(" << p[2].getX() << ',' << p[2].getY() << ")�Դϴ�.\n";
	Point::showN();
}