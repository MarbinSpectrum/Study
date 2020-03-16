#pragma once

#include<iostream>
#include <math.h>

using namespace std;

class Vector2
{
public:
	float x;
	float y;
	float magnitude();
	Vector2 normalized();
	float sqrMagnitude();
public:
	Vector2();
	Vector2(int ax, int ay);
public:
	static Vector2 zero();
	static Vector2 one();
	static Vector2 left();
	static Vector2 right();
	static Vector2 up();
	static Vector2 down();

public:
	Vector2 operator=(const Vector2 &v);
	bool operator!=(const Vector2 &v);
	bool operator==(const Vector2 &v);
	friend Vector2 operator+(const Vector2 & v0, const Vector2 & v1);
	Vector2 operator+=(const Vector2 & v);
	friend Vector2 operator-(const Vector2 & v0, const Vector2 & v1);
	Vector2 operator-=(const Vector2 & v);
	Vector2 operator*(float v);
	Vector2 operator/(float v);
};