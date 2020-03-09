#include <iostream>
using namespace std;

class Car 
{
	protected:
		int Basic = 4;
	private:
		int speed;
		double energy;
	public :
		void SetSpeed(int a) { speed = a; };
		void SetEnergy(double a) { energy = a; };
		int GetSpeed() { return speed; };
		double GetEnergy() { return energy; };
};

class RaceCar : public Car 
{
	private:
		int carnum;
	public:
		void SetNum(int a) { carnum = a; };
		int GetNum() { return carnum; };
		void Default() { cout << Basic << "\n"; };
};
int main() 
{
	RaceCar rc;
	rc.SetSpeed(5);
	rc.SetEnergy(14.3);
	rc.SetNum(23233);

	cout << "속도 : " << rc.GetSpeed() << ", 에너지 : " << rc.GetEnergy() << ", 차량번호 : " << rc.GetNum() << "\n";

	rc.Default();

	Car c;
	c.SetSpeed(2);
	c.SetEnergy(7.3);

	cout << "속도 : " << c.GetSpeed() << ", 에너지 : " << c.GetEnergy() << "\n";
	
}