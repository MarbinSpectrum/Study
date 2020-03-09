#include <iostream>
using namespace std;

class Point
{
	private:
		int x;
		int y;

	public:
		void setX(int a);
		void setY(int b);
		int getX() { return x; }
		int getY() { return y; }
};

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

int main()
{
	Point p;
	int input;
	cout << "X ��ǥ�� �Է��Ͻʽÿ�.\n";
	cin >> input;
	p.setX(input);

	cout << "Y ��ǥ�� �Է��Ͻʽÿ�.\n";
	cin >> input;
	p.setY(input);

	cout << "��ǥ��(" << p.getX() << ',' << p.getY() << ")�Դϴ�.\n";
}