#include <iostream>;
using namespace std;

int count(char str[], char ch);

int main()
{
	cout << "���ڿ��� �Է��Ͻʽÿ�." << '\n';
	char test[100];
	cin >> test;

	cout << "���ڿ����� �˻��� ���ڸ� �Է��Ͻʽÿ�." << '\n';
	char c;
	cin >> c;
	cout << test << "�ȿ� " << c << "�� ��" << count(test, c) << "�� �ֽ��ϴ�." << '\n';

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

