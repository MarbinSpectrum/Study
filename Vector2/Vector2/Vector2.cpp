#include"Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}
Vector2::Vector2(int ax, int ay)
{
	x = ax;
	y = ay;
}

float Vector2::magnitude()
{
	return sqrt(x * x + y * y);
}
Vector2 Vector2::normalized()
{
	return Vector2(x / magnitude(), y / magnitude());
}
float Vector2::sqrMagnitude()
{
	return x * x + y * y;
}

Vector2 Vector2::zero()
{
	return Vector2();
}
Vector2 Vector2::one()
{
	return Vector2(1, 1);
}
Vector2 Vector2::left()
{
	return Vector2(-1, 0);
}
Vector2 Vector2::right()
{
	return Vector2(+1, 0);
}
Vector2 Vector2::up()
{
	return Vector2(0, +1);
}
Vector2 Vector2::down()
{
	return Vector2(0, -1);
}

Vector2 Vector2::operator=(const Vector2 & v)
{
	x = v.x;
	y = v.y;
	return Vector2(x, y);
}
bool Vector2::operator!=(const Vector2 & v)
{
	if(x == v.x && y == v.y)
		return false;

	return true;
}
bool Vector2::operator==(const Vector2 & v)
{
	if (x == v.x && y == v.y)
		return true;

	return false;
}
Vector2 operator+(const Vector2 &v0, const Vector2 &v1)
{
	return Vector2(v0.x + v1.x, v0.y + v1.y);
}
Vector2 Vector2::operator+=(const Vector2 & v)
{
	return Vector2(x + v.x, y + v.y);
}
Vector2 operator-(const Vector2 & v0, const Vector2 & v1)
{
	return Vector2(v0.x - v1.x, v0.y - v1.y);
}
Vector2 Vector2::operator-=(const Vector2 & v)
{
	return Vector2(x - v.x, y - v.y);
}
Vector2 Vector2::operator*(float v)
{
	return Vector2(x*v, y*v);
}
Vector2 Vector2::operator/(float v)
{
	return Vector2(x / v, y / v);
}
