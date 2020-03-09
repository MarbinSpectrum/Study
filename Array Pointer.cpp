#include <iostream>;
using namespace std;

int avg(int a[]);
int avg2(int* a);
int avg3(int* a);
int main()
{
	int test[] = { 4,6,7,8,5 };
	for (int i = 0; i < 5; i++)
	{
		//cout << test[i] << '(' << &test[i] << ")\n";
		cout << *(test+i) << '(' << test + i << ")\n";
	}
	cout << avg(test) << "\n";
	cout << avg2(test) << "\n";
	cout << avg3(test) << "\n";

}

int avg(int a[]) 
{
	int sum = 0;
	for (int i = 0; i < 5; i++) 
	{
		sum += *(a + i);
	}
	return sum/5;
}

int avg2(int* a)
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += *(a + i);
	}
	return sum / 5;
}

int avg3(int* a)
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += a[i];
	}
	return sum / 5;
}