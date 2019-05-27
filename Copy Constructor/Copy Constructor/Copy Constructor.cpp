#include <iostream>
#include <string>
using namespace std;

class Point
{
	private :
		int* x = new int;
		int* y = new int;
	public :
		Point(int a, int b);
		~Point();
		Point(const Point& c);
		Point& operator= (const Point& c);
};

Point::Point(int a, int b)
{
	*x = a;
	*y = b;
}

Point::~Point()
{
	delete x;
	delete y;
}

Point::Point(const Point& c)
{
	x = new int(*(c.x));
	y = new int(*(c.y));
	//x = c.x;
	//y = c.y;
}

Point& Point::operator= (const Point& c)
{
	if (this != &c) 
	{
		delete x;
		delete y;

		//x = c.x;
		//y = c.y;
		x = new int(*(c.x));
		y = new int(*(c.y));
	}
	return *this;
}
int main() 
{
	Point p(4, 5);

	Point p1 = p;

	Point p2(2, 3);

	p2 = p;
}