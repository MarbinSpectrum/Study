#include <iostream>
using namespace std;

struct Car
{
	int num;
	double energy;
};

void show(Car* c);

int main()
{
	Car c;

	cout << "���� ��ȣ�� �Է��Ͻʽÿ�.\n";
	cin >> c.num;
	cout << "������ ���� �Է»�ʽÿ�.\n";
	cin >> c.energy;
	show(c);
}


void show(Car& c) 
{
	cout << "���� ��ȣ�� " << c.num << " : ���ᷮ�� " << c.energy << "�Դϴ�\n";
}