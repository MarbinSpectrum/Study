#include <iostream>;
using namespace std;

int length(char* str);

int main()
{
	cout << "���ڿ��� �Է��Ͻʽÿ�." << '\n';
	char test[100];

	cin >> test;

	cout << "���ڿ��� ���̴� "<<length(test) << "�Դϴ�." <<'\n';

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

