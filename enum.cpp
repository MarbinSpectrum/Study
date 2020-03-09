#include <iostream>
using namespace std;

enum Week {Mon, Tue , Wed , Thu , Fri , Sat , Sun};

int main() 
{
	Week w;

	w = Sun;

	switch(w) 
	{
	case Mon: cout << "월요일\n"; break;
	case Tue: cout << "화요일\n"; break;
	case Wed: cout << "수요일\n"; break;
	case Thu: cout << "목요일\n"; break;
	case Fri: cout << "금요일\n"; break;
	case Sat: cout << "토요일\n"; break;
	case Sun: cout << "일요일\n"; break;
	default: cout << "오늘이 무슨요일이냐? \n"; break;

	}
}