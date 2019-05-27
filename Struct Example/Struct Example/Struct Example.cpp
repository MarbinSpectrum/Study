#include <iostream>
using namespace std;

struct Person
{
	int age;
	double weight;
	double height;
};

void aging(Person* p);

int main()
{
	Person h;


		cout << "나이를 입력하십시오\n";
		cin >> h.age;
		cout << "몸무게를 입력하십시오\n";
		cin >> h.weight;
		cout << "키를 입력하십시오\n";
		cin >> h.height;

		cout << "나이 " << h.age << " 몸무게 " << h.weight << " 키 " << h.height << "입니다\n";
		aging(&h);
		cout << "1년이 지났습니다.\n";
		cout << "나이 " << h.age << " 몸무게 " << h.weight << " 키 " << h.height << "입니다\n";


}

void aging(Person* p) 
{
	p->age += 1;
}