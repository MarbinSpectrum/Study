#include <iostream>

using namespace std;

class Vector3
{
public:
	float x;
	float y;
	float z;

	//가상함수로 처리했기 때문에 동적할당 해준것에 맞는 함수를 호출해줌
	virtual void Print() { printf("(%.2f, %.2f, %.2f)\n", x, y, z); }

	void Init(float ax, float ay, float az)
	{
		x = ax;
		y = ay;
		z = az;
	}

	Vector3(float ax, float ay, float az)
	{
		Init(ax, ay, az);
	}

	Vector3()
	{
		Init(0, 0, 0);
	}
};

class Vector2 : public Vector3
{
public:
	//가상함수로 처리했기 때문에 동적할당 해준것에 맞는 함수를 호출해줌
	virtual void Print() { printf("(%.2f, %.2f)\n", x, y); }

	Vector2(float ax, float ay)
	{
		Init(ax, ay, 0);
	}

	Vector2()
	{
		Init(0, 0, 0);
	}
};

int main()
{
	Vector2 vector2(1, 2);
	Vector3 vector3(3, 4, 5);
	Vector2 *pVector2;
	Vector3 *pVector3;

	pVector2 = &vector2;  //정적타입(좌변) 동적타입(우변)이 일치하므로 대입이가능
	pVector3 = &vector3;  //정적타입(좌변) 동적타입(우변)이 일치하므로 대입이가능
	pVector3 = &vector2;  //정적타입(좌변) 동적타입(우변)이 불일치하지만 정적타입이 동적타입을 상속해주는 관계이므로 대입이가능함 >>>>>> < 부모포인터는 자식포인터를 가리킬 수 있다!! >

	pVector2->Print();
	pVector3->Print();
}


///// 결합(Binding)이란 함수 호출문에 대해 실제 호출될 함수의 번지를 결정하는 것
///// 일반적인 함수는 정적타입에서 이미 함수번지가 결정되어있다. 정적할당이라고함.
///// virtual이 붙은 함수는 동적타입에서 정해진 함수번지를 찾아야한다. 실행중에 동적으로 함수번지를 결정해줘야됨. 동적할당이라고한다. >>>>>>>>> <가상함수란 동적으로 함수번지를 결정해주는 함수이다!!>

///// 가상함수를 보유한 클레스는 가상함수테이블을 가리키는 4바이트의 가상함수포인터를 가진다!! >>>>> 가상함수 테이블을 이용해서 동적할당된 함수번지를 찾기우해서이다!!