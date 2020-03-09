#include<iostream>
using namespace std;

class Car 
{
	private :
		int num;
		double gas;
	public :
		Car(int a, double b);
		friend ostream& operator<<(ostream& out, Car& c);
};

Car::Car(int a, double b)
{
	num = a;
	gas = b;
}

ostream& operator<<(ostream& out, Car& c) 
{
	out << "������ȣ " << c.num << " : " << "���ᷮ " << c.gas << "\n";
	return out;
}
int main()
{
	Car car(4, 14.5);
	cout << car;
}