#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
	ofstream fout("test0.txt");

	if (!fout) 
	{
		cout << "������ ���� �����ϴ�." << endl;
		return 1;
	}

	fout << "Hello! \n";
	fout << "Goodbye! \n";

	fout.close();




	ifstream fin("test0.txt");

	if (!fin)
	{
		cout << "������ ���� �����ϴ�." << endl;
		return 1;
	}

	char str1[16];
	char str2[16];
	fin >> str1 >> str2;
	cout << "���Ͽ� ��ϵ� 2���� ���ڿ��� \n";
	cout << str1 << " �Դϴ�. \n";
	cout << str2 << " �Դϴ�. \n";

	fin.close();

}