#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	vector<int> vt;

	for (int i = 0; i < 5; i++) 
	{
		int data;
		cin >> data;
		vt.push_back(data);
	}

	vector<int>::iterator it = vt.begin();
	while (it != vt.end()) 
	{
		cout << *it << ", ";
		it++;
	}
	cout << "\n\n";

	reverse(vt.begin(), vt.end());
	it = vt.begin();
	while (it != vt.end())
	{
		cout << *it << ", ";
		it++;
	}
	cout << "\n\n";

	sort(vt.begin(), vt.end());
	it = vt.begin();
	while (it != vt.end())
	{
		cout << *it << ", ";
		it++;
	}
	cout << "\n\n";
}