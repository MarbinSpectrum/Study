#include <iostream>;
using namespace std;

int count(char str[], char ch);

int main()
{
	cout << "문자열을 입력하십시오." << '\n';
	char test[100];
	cin >> test;

	cout << "문자열에서 검색할 문자를 입력하십시오." << '\n';
	char c;
	cin >> c;
	cout << test << "안에 " << c << "은 총" << count(test, c) << "개 있습니다." << '\n';

}
int count(char str[],char ch)
{
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ch) {
			count++;
		}
	}
	return count;
}

