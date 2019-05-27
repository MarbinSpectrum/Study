#include <iostream>
using namespace std;

class Point
{
	private :
		int* x = new int;
		int* y = new int;
	public :
		Point(int a, int b);
		~Point();
		void show()
		{
			cout << *x << ", " << *y << '\n';
		}
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

	cout << "x,y°ª ¼Ò¸ê \n";
}

int main() 
{
	Point p(4, 5);
	p.show();
}