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


		cout << "���̸� �Է��Ͻʽÿ�\n";
		cin >> h.age;
		cout << "�����Ը� �Է��Ͻʽÿ�\n";
		cin >> h.weight;
		cout << "Ű�� �Է��Ͻʽÿ�\n";
		cin >> h.height;

		cout << "���� " << h.age << " ������ " << h.weight << " Ű " << h.height << "�Դϴ�\n";
		aging(&h);
		cout << "1���� �������ϴ�.\n";
		cout << "���� " << h.age << " ������ " << h.weight << " Ű " << h.height << "�Դϴ�\n";


}

void aging(Person* p) 
{
	p->age += 1;
}