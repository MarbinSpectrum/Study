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
	cout << "구매한 차량 번호는 " << c.Getnum() << "입니다.\n";
	cout << "구매한 차의 연료의 양은 " << c.Getgas() << "입니다.\n";
}

void Car::show()
{
	cout << "차량 번호는 " << num << "입니다.\n";
	cout << "연료의 양은 " << gas << "입니다.\n";
}

void Car::setting(int a, double b)
{
	if (a >= 0 && b >= 0) {
		num = a;
		gas = b;
	}
	else if (a < 0 || b < 0)
	{
		cout << "입력값이 올바르지 않습니다.\n";
	}
}

int main()
{
	Car car;

	car.setting(1234,20.5);
	car.show();
	buy(car);
}