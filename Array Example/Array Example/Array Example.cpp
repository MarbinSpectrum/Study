#include <iostream>;
using namespace std;

int max(int x[]);

int main()
{
	cout << "���� ������ �Է��Ͻʽÿ�." << '\n';

	int point[5];

	for (int i = 0; i < 5; i++)
	{
		cin >> point[i];
	}

	cout << "���� ���� ������ " << max(point) << "���Դϴ�." << '\n';
}

int max(int x[]) 
{
	int max = x[0];
	
	for (int i = 0; i < 5; i++)
	{
		if (x[i] > max) 
		{
			max = x[i];
		}
	}
	return max;
}