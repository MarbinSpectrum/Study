#include <iostream>
using namespace std;

class Car
{
	public :
		void show();
		void setting(int a, double b);
		int Getnum() 
		{
			return num;
		}
		double Getgas()
		{
			return gas;
		}

	private:
		int num;
		double gas;
};
void buy(Car& c) 
{
	cout << "������ ���� ��ȣ�� " << c.Getnum() << "�Դϴ�.\n";
	cout << "������ ���� ������ ���� " << c.Getgas() << "�Դϴ�.\n";
}

void Car::show()
{
	cout << "���� ��ȣ�� " << num << "�Դϴ�.\n";
	cout << "������ ���� " << gas << "�Դϴ�.\n";
}

void Car::setting(int a, double b)
{
	if (a >= 0 && b >= 0) {
		num = a;
		gas = b;
	}
	else if (a < 0 || b < 0)
	{
		cout << "�Է°��� �ùٸ��� �ʽ��ϴ�.\n";
	}
}

int main()
{
	Car car;

	car.setting(1234,20.5);
	car.show();
	buy(car);
}