#include <iostream>;
using namespace std;
void Swap(int* a, int* b);
void Swap2(int& a, int& b);
int main() 
{
	int n1 = 5;
	int n2 = 7;
	cout << n1 << ',' << n2 << '\n';
	Swap(&n1,&n2);
	cout << n1 << ',' << n2 << '\n';
	Swap2(n1, n2);
	cout << n1 << ',' << n2 << '\n';
}

void Swap(int* a, int* b) 
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

void Swap2(int& a, int& b)
{
	int temp2 = b;
	b = a;
	a = temp2;
}