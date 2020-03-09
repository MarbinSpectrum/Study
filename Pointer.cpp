#include <iostream>;
using namespace std;

int main() 
{
	int a = 5;
	int* Pa = &a;

	int b = 10;
	int* Pb = &b;

	cout << "a값    : "<< a << '\n';
	cout << "Pa값   : "<< Pa << '\n';
	cout << "Pa가 가리키는것 : " << *Pa << '\n';
	cout << "b값    : " << b << '\n';
	cout << "Pb값   : " << Pb << '\n';
	cout << "Pb가 가리키는것 : " << *Pb << '\n';
	cout << "Pa에 50대입" << '\n';

	*Pa = 50;

	cout << "a값    : " << a << '\n';
	cout << "Pa값   : " << Pa << '\n';
	cout << "Pa가 가리키는것 : " << *Pa << '\n';
}