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
			throw "0 ������ ��";
		}
		if (num >= 10)
		{
			throw "10 �̻��� ��";
		}
		cout << num << "�Դϴ�.\n";
	}
	catch (char* err) 
	{
		cout << "���� : " << err << "\n";
		return 1;
	}
	return 0;
}