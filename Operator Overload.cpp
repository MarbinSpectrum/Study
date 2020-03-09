#include <iostream>
using namespace std;

class Point 
{
	private :
		int x;
		int y;
	public :
		Point()
		{
			x = 0;
			y = 0;
		}

		Point(int a, int b) 
		{
			x = a;
			y = b;
		}

		friend Point operator+ (Point p1, Point p2);
		friend Point operator+ (int a, Point p);
		friend Point operator+ (Point p,int a);
		Point operator++();
		Point operator++(int a);

		void show() 
		{
			cout << x << "," << y << '\n';
		};
};

Point operator+ (Point p1, Point p2)
{
	Point temp;
	temp.x = p1.x + p2.x;
	temp.y = p1.y + p2.y;
	return temp;
};

Point operator+ (int a, Point p)
{
	Point temp;
	temp.x = a + p.x;
	temp.y = a + p.y;
	return temp;
};

Point operator+ (Point p, int a)
{
	Point temp;
	temp.x = p.x + a;
	temp.y = p.y + a;
	return temp;
};
Point Point::operator++()
{
	x++;
	y++;
	return *this;
};

Point Point::operator++(int a)
{
	Point temp = *this;
	x++;
	y++;
	return temp;
};

int main() 
{
	Point p1(2, 3);
	Point p2(1, 5);
	Point p;

	p = p1 + p2;
	p.show();

	++p;
	p.show();

	p = 1 + p;
	p.show();

	p = p + (-10);
	p.show();

	p++;
	p.show();
	
}