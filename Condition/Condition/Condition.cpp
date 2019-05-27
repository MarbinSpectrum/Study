#include <iostream>;
using namespace std;

int main() 
{
	int res;
	cin >> res;
	if (res < 5) 
	{
		cout << "res는 5 이하입니다. \n";
	}
	else if (res == 5) 
	{
		cout << "res는 5 입니다. \n";
	}
	else
	{
		cout << "res는 5 이상입니다. \n";
	}
	switch (res)
	{
	case 1:
		cout << "res는 1 입니다. \n";
		break;
	case 6:
		cout << "res는 1 입니다. \n";
		break;
	case 10:
		cout << "res는 1 입니다. \n";
		break;
	default:
		break;
	}
}