#include <iostream>
using namespace std;

class Vehicle 
{
	private:
		double speed;
		int power;
		char name[10];
	public:
		void SetSpeed(double s) 
		{
			speed = s;
		};

		void SetPower(int p)
		{
			power = p;
		};
		virtual void show() = 0;
};

class Plane : public Vehicle 
{
	private:
		double speed = 10;
		int power = 10;
		char name[10] = "비행기";
	public :
		void show() 
		{
			cout << name << "속도 :" << speed << ", " << name << "파워 : " << power << '\n';
		}
};

class Train : public Vehicle
{
private:
	double speed = 10;
	int power = 10;
	char name[10] = "기차";
public:
	void show()
	{
		cout << name << "속도 :" << speed << ", " << name << "파워 : " << power << '\n';
	}
};
int main() 
{
	Plane plane;
	Train train;
	Vehicle* v[2];

	v[0] = &plane;
	v[1] = &train;

	v[0]->show();
	v[1]->show();
}