#include <iostream>;
using namespace std;

int main() 
{
	int* Pa;
	int num;

	cout << "�� ���� ���� ������ �Է��Ͻðڽ��ϱ�?" << "\n";

	cin >> num;

	Pa = new int[num];

	cout  << num << "�� ���� ������ �Է��Ͻʽÿ�." << "\n";

	for (int n = 0; n < num; n++) 
	{
		cin >> Pa[n];
	}

	for (int n = 0; n < num; n++)
	{
		cout << n + 1 << "��° ����� ������ "<< Pa[n] << "�Դϴ�." << "\n";
	}

	delete[] Pa;

}