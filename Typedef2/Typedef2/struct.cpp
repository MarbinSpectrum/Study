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

	cout << "차량 번호를 입력하십시오.\n";
	cin >> c.num;
	cout << "연료의 양을 입력사십시오.\n";
	cin >> c.energy;
	show(c);
}


void show(Car& c) 
{
	cout << "차량 번호는 " << c.num << " : 연료량은 " << c.energy << "입니다\n";
}