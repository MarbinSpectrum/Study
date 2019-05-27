#include <iostream>;
using namespace std;

int multiply(int a, int b);
void buy(int a, int b);

int main() 
{
	for (int j = 1; j < 10; j++) {
		for (int i = 1; i < 10; i++)
		{
			buy(j,i);
		}
	}
}

int multiply(int a, int b)
{
	return a * b;
}

void buy(int a, int b)
{
	cout << a << "*" << b << "=" << multiply(a, b) << '\n';
}
