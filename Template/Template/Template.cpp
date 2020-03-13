#include <iostream>

using namespace std;

// Template : 똑같은 절차가 있을때 데이터 타입이 다른 경우 사용하는 문법 >>>> 제네릭같은거

template <typename T = int>	// 여기서 T 는 타입이름을 뜻함 ----> int , float , char 같은것들.. // 기본값으로는 int로 처리
T sum(T a, T b)				// T는 
{
	return a + b;
}

template <typename T>	
void Swap(T &a, T&b)
{
	T empty = a;
	a = b;
	b = empty;
}

template <> 
void Swap<float>(float &a, float&b) // Swap 함수에서 특정한 타입은 특수하게 적용하고 싶을때 특수화를 사용하면된다!!
{
	float empty = a;
	a = b;
	b = empty;
	cout << a << endl;
}

int main()
{
	int a = 4, b = 5;
	Swap<int>(a, b);					//템플릿의 유효성 검사는 호출부에서 이뤄진다. // 호출부마다 내부적으로 함수를 만들어서 사용한다.

	float c = 4, d = 5;
	Swap<float>(c, d);	
}
