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
	cout << "���⸦ �Է��Ͻʽÿ�.\n";
	cin >> y.ad;

	cout << "���� " << y.ad << "���Դϴ�.\n";
	cout << "�ܱ� ���� " << y.dangi << "���Դϴ�.\n";

	cout << "�ܱ⸦ �Է��Ͻʽÿ�.\n";
	cin >> y.dangi;

	cout << "�ܱ� " << y.dangi << "���Դϴ�.\n";
	cout << "���� ���� " << y.ad << "���Դϴ�.\n";
}