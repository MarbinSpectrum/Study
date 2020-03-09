#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
	ofstream fout("test0.txt");

	if (!fout) 
	{
		cout << "파일을 열수 없습니다." << endl;
		return 1;
	}

	fout << "Hello! \n";
	fout << "Goodbye! \n";

	fout.close();




	ifstream fin("test0.txt");

	if (!fin)
	{
		cout << "파일을 열수 없습니다." << endl;
		return 1;
	}

	char str1[16];
	char str2[16];
	fin >> str1 >> str2;
	cout << "파일에 기록된 2개의 문자열은 \n";
	cout << str1 << " 입니다. \n";
	cout << str2 << " 입니다. \n";

	fin.close();

}