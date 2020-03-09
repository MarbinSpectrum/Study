#include <iostream>;
using namespace std;

int main() 
{
	int count;
	int sum = 0;
	cin >> count;
	for (int i = 0; i < count; i++) 
	{
		cout << i << '\n';
		sum += i;
	}
	while (sum > 10) 
	{
		cout << "È£¿ËÀÌ" << '\n';
		sum -= 1;
	}
}