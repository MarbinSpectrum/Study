#include <iostream>
using namespace std;

class Car
{	
	public :
		virtual void show();
};

class Bus : public Car
{
	public:
		void show();
};

class Taxi : public Car
{
public:
	void show();
};

void Car::show()
{
	cout << "Car \n" ;
}

void Bus::show()
{
	cout << "Bus \n";
}

void Taxi::show()
{
	cout << "Taxi \n";
}

int main() 
{
	Car* c[3];
	Car car;
	Bus bus;
	Taxi taxi;

	c[0] = &car;
	c[1] = &bus;
	c[2] = &taxi;

	for (int i = 0; i < 3; i++) 
		{
		c[i] -> show();
		}
}