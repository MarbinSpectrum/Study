#include <iostream>;
using namespace std;
template <class T>
T max(T x,T y)
{
	cin >> x >> y;

	if (x > y) 
	{
		return x;
	}
	else 
	{
		return y;
	}
}

template <class T>
T square(T x)
{
		return x*x;
}

int main() 
{
	int n1 = 0;
	int n2 = 0;
	cout << max(n1,n2) << '\n';

	char c1 = NULL;
	char c2 = NULL;
	cout << max(c1, c2) << '\n';
	cout << square(5) << '\n';
	cout << square(1.5) << '\n';
}

