#include <iostream>
using namespace std;

int main() 
{
	int num;
	cin >> num;
	try 
	{
		if (num <= 0) 
		{
			throw "0 이하의 수";
		}
		if (num >= 10)
		{
			throw "10 이상의 수";
		}
		cout << num << "입니다.\n";
	}
	catch (char* err) 
	{
		cout << "에러 : " << err << "\n";
		return 1;
	}
	return 0;
}