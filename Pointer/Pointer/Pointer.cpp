#include <iostream>;
using namespace std;

int main() 
{
	int a = 5;
	int* Pa = &a;

	int b = 10;
	int* Pb = &b;

	cout << "a��    : "<< a << '\n';
	cout << "Pa��   : "<< Pa << '\n';
	cout << "Pa�� ����Ű�°� : " << *Pa << '\n';
	cout << "b��    : " << b << '\n';
	cout << "Pb��   : " << Pb << '\n';
	cout << "Pb�� ����Ű�°� : " << *Pb << '\n';
	cout << "Pa�� 50����" << '\n';

	*Pa = 50;

	cout << "a��    : " << a << '\n';
	cout << "Pa��   : " << Pa << '\n';
	cout << "Pa�� ����Ű�°� : " << *Pa << '\n';
}