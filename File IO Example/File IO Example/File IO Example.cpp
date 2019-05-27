#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
	int num[8];
	int min, max;

	ifstream fin("test.txt");

	for (int i = 0; i < 8 ; i++) 
	{
		fin >> num[i];
		cout << "No." << i << " " << num[i] << endl;
	}

	min = num[0];
	max = num[0];

	for (int i = 0; i < 8; i++)
	{
		if (num[i] < min) 
		{
			min = num[i];
		}

		if (num[i] > max)
		{
			max = num[i];
		}
	}

	cout << "가장 높은 점수는 " << max << "입니다. \n";
	cout << "가장 낮은 점수는 " << min << "입니다. \n";
}