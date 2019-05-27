#include <iostream>;
using namespace std;

int length(char* str);

int main()
{
	cout << "문자열을 입력하십시오." << '\n';
	char test[100];

	cin >> test;

	cout << "문자열의 길이는 "<<length(test) << "입니다." <<'\n';

}
int length(char* str) 
{
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
			count++;
	}
	return count;
}

