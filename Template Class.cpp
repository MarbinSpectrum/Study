#include <iostream>
#include <string>
using namespace std;

template <class T>
class Array 
{
	private :
		T Data[5];
	public :
		void SetData();
		void Show();
};

template <class T>
void Array<T> ::SetData() 
{
	for (int a = 0; a<5; a++)
	{
		cin >> Data[a];
	}
}
 
template <class T>
void Array<T> ::Show()
{
	for (int a = 0; a<5; a++)
	{
		cout << Data[a] << '\n';
	}
}

int main() 
{
	Array<int> array;
	array.SetData();
	array.Show();

	Array<string> array2;
	array2.SetData();
	array2.Show();
}
