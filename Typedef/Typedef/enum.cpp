#include <iostream>
using namespace std;

enum Week {Mon, Tue , Wed , Thu , Fri , Sat , Sun};

int main() 
{
	Week w;

	w = Sun;

	switch(w) 
	{
	case Mon: cout << "������\n"; break;
	case Tue: cout << "ȭ����\n"; break;
	case Wed: cout << "������\n"; break;
	case Thu: cout << "�����\n"; break;
	case Fri: cout << "�ݿ���\n"; break;
	case Sat: cout << "�����\n"; break;
	case Sun: cout << "�Ͽ���\n"; break;
	default: cout << "������ ���������̳�? \n"; break;

	}
}