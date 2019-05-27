#include <iostream>
#include "Function.h"
using namespace std;

int main()
{
	int num1, num2;

	cout << "첫 번째 정수를 입력하십시오.\n";

	cin >> num1;

	cout << "두 번째 정수를 입력하십시오.\n";

	cin >> num2;

	cout << "최대 값은 "<< max(num1,num2) << "입니다.\n";
}