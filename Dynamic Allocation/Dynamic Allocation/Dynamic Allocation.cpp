#include <iostream>;
using namespace std;

int main() 
{
	int* Pa;
	int num;

	cout << "몇 명의 시험 점수를 입력하시겠습니까?" << "\n";

	cin >> num;

	Pa = new int[num];

	cout  << num << "명 분의 점수를 입력하십시오." << "\n";

	for (int n = 0; n < num; n++) 
	{
		cin >> Pa[n];
	}

	for (int n = 0; n < num; n++)
	{
		cout << n + 1 << "번째 사람의 점수는 "<< Pa[n] << "입니다." << "\n";
	}

	delete[] Pa;

}