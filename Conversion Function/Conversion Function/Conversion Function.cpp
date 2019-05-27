#include <iostream>
using namespace std;

class Number
{
	private:
		int num;

	public:
		Number() { num = 0; }
		Number(int a) { num = a; }
		operator int() { return num; }
		Number operator++();
		Number operator++(int a);
		Number operator--();
		Number operator--(int a);
};

Number Number::operator++()
{
	num++;
	return *this;
}

Number Number::operator++(int a)
{
	Number n = *this;
	num++;
	return n;
}

Number Number::operator--()
{
	num++;
	return *this;
}

Number Number::operator--(int a)
{
	Number n = *this;
	num--;
	return n;
}

int main() 
{
	Number n(4);
	int i = (int)n;

	cout << i << "\n";
}