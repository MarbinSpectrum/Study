#include <iostream>
using namespace std;

int main() 
{
	char ch;

	/*while (cin.get(ch)) 
	{
		cout.put(ch);
	}*/

	for (int i = 0; i < 10; i++) 
	{
		cout.width(3);
		cout.fill('_');
		cout << i;
	}
	cout << "\n";
}