#include <iostream>;
using namespace std;

int main() 
{
	int res;
	cin >> res;
	if (res < 5) 
	{
		cout << "res�� 5 �����Դϴ�. \n";
	}
	else if (res == 5) 
	{
		cout << "res�� 5 �Դϴ�. \n";
	}
	else
	{
		cout << "res�� 5 �̻��Դϴ�. \n";
	}
	switch (res)
	{
	case 1:
		cout << "res�� 1 �Դϴ�. \n";
		break;
	case 6:
		cout << "res�� 1 �Դϴ�. \n";
		break;
	case 10:
		cout << "res�� 1 �Դϴ�. \n";
		break;
	default:
		break;
	}
}