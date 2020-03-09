#include <iostream>
using namespace std;

union Year
{
	int ad;
	int dangi;
};

int main()
{
	Year y;
	cout << "서기를 입력하십시오.\n";
	cin >> y.ad;

	cout << "서기 " << y.ad << "년입니다.\n";
	cout << "단기 또한 " << y.dangi << "년입니다.\n";

	cout << "단기를 입력하십시오.\n";
	cin >> y.dangi;

	cout << "단기 " << y.dangi << "년입니다.\n";
	cout << "서기 또한 " << y.ad << "년입니다.\n";
}