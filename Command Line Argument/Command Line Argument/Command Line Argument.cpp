#include <iostream>
#include <fstream>
using namespace std;

int main(int argc , char* argv[]) 
{
	if (argc != 2) 
	{
		cout << "�μ��� ������ �ٸ��ϴ�.\n";
		return 1;
	}

	ifstream fin(argv[1]);
	if (!fin) 
	{
		cout << "������ �� �� �����ϴ�.\n";
		return 1;
	}

	char ch;
	fin.get(ch);
	
	while(!fin.eof())
	{
		cout.put(ch);
		fin.get(ch);
	}

	fin.close();
}