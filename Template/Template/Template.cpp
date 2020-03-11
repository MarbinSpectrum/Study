#include <iostream>

using namespace std;

// Template : 똑같은 절차가 있을때 데이터 타입이 다른 경우 사용하는 문법 >>>> 제네릭같은거

template <typename T>	// 여기서 T 는 타입이름을 뜻함 ----> int , float , char 같은것들..
T sum(T a, T b)			// T는 
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

int main()
{
	int a = 4, b = 5;
	Swap<int>(a, b);					//템플릿의 유효성 검사는 호출부에서 이뤄진다. // 호출부마다 내부적으로 함수를 만들어서 사용한다.

	float c = 4, d = 5;
	Swap<float>(c, d);	
}
