#include <iostream>;
using namespace std;

int max(int x[]);

int main()
{
	cout << "시험 점수를 입력하십시오." << '\n';

	int point[5];

	for (int i = 0; i < 5; i++)
	{
		cin >> point[i];
	}

	cout << "가장 높은 점수는 " << max(point) << "점입니다." << '\n';
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