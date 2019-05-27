#include <iostream>;
using namespace std;
void Add(int& x, int& y);

int main() 
{
	int n1 = 65;  
	int n2 = 55;
	cout << n1 << ',' << n2 << '\n';
	Add(n1,n2);
	cout << n1 << ',' << n2 << '\n';
}

void Add(int& x, int& y) 
{
	x += 12;
	y += 12;
}