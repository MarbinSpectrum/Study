#include <iostream>
using namespace std;

class Base1
{
	public:
		void show()
		{
			cout << "Base1\n";
		}
};

class Base2
{
	public:
		void show()
		{
			cout << "Base2\n";
		}
};

class Body : public Base1, public Base2
{
public:
	void show()
	{
		cout << "Body\n";
	}
};

int main() 
{
	Body body;
	
	body.show();
	body.Base1::show();
	body.Base2::show();
}