#include <iostream>;
using namespace std;

int main() 
{
	int test[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> test[i];
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (test[i] > test[j]) 
			{
				int temp = test[i];
				test[i] = test[j];
				test[j] = temp;
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		cout << test[i] << '\n';
	}

	
}