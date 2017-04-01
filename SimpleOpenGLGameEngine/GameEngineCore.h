#pragma once

#include <GL\GL.h>
#include <GL\glut.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>

//OpenGL CallBack Function

//GameEngine Structs
struct Vector3 {
public:
	float x;
	float y;
	float z;

	//basic unit
	static const Vector3 zero;
	static const Vector3 one;

	inline Vector3() {
		x = 0;
		y = 0;
		z = 0;
	}

	inline Vector3(float inX, float inY, float inZ) {
		x = inX;
		y = inY;
		z = inZ;
	}

	inline Vector3 operator+(const Vector3& v) const {
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	inline Vector3 operator-(const Vector3& v) const {
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	inline Vector3 operator*(float scale) const {
		return Vector3(x * scale, y * scale, z * scale);
	}

	inline Vector3 operator/(float scale) const {
		const float rScale = 1.f / scale;
		return Vector3(x * rScale, y * rScale, z * rScale);
	}

	inline Vector3 operator*(const Vector3& v) const {
		return Vector3(x * v.x, y * v.y, z * v.z);
	}

	inline Vector3 operator/(const Vector3& v) const {
		return Vector3(x / v.x, y / v.y, z / v.z);
	}

	inline bool operator==(const Vector3& v) const {
		return x == v.x && y == v.y && z == v.z;
	}

	inline bool operator!=(const Vector3& v) const {
		return x != v.x || y != v.y || z != v.z;
	}

	inline Vector3 operator-() const {
		return Vector3(-x, -y, -z);
	}

	inline Vector3 operator+=(const Vector3& v) {
		return Vector3(x += v.x, y += v.y, z += v.z);
	}

	inline Vector3 operator-=(const Vector3& v) {
		return Vector3(x -= v.x, y -= v.y, z -= v.z);
	}

	inline Vector3 operator*=(const Vector3& v) {
		return Vector3(x *= v.x, y *= v.y, z *= v.z);
	}

	inline Vector3 operator/=(const Vector3& v) {
		return Vector3(x /= v.x, y /= v.y, z /= v.z);
	}
};

const Vector3 Vector3::zero(0, 0, 0);
const Vector3 Vector3::one(1, 1, 1);
struct Color {
	int r;
	int g;
	int b;
	int a;

	//basic color
	static const Color red;
	static const Color green;
	static const Color blue;
	static const Color white;
	static const Color black;

	inline Color() {
		r = 0;
		g = 0;
		b = 0;
		a = 1;
	}

	inline Color(int inRed, int inGreen, int inBlue) {
		r = inRed;
		g = inGreen;
		b = inBlue;
		a = 1;
	}

	inline Color(int inRed, int inGreen, int inBlue, int inAlpha) {
		r = inRed;
		g = inGreen;
		b = inBlue;
		a = inAlpha;
	}
};

const Color Color::red(255, 0, 0);
const Color Color::green(0, 255, 0);
const Color Color::blue(0, 0, 255);
const Color Color::white(255, 255, 255);
const Color Color::black(0, 0, 0);

struct Transform {
public:
	Vector3 position;
	Vector3 rotation; //Will change this as Quaternion if possible.
	Vector3 scale;
public:
	Transform() {
		position = Vector3::zero;
		rotation = Vector3::zero;
		scale = Vector3::one;
	}
};

//GameEngine Classes
class Actor { //Basic Actor
public:
	Actor()
	{
		transform.position = Vector3::zero;
		transform.rotation = Vector3::zero;
		transform.scale = Vector3::one;
	}
	~Actor() {}
	virtual void Render() = 0;
	Transform transform;
};

class Time { //Singleton Time class
public:
	Time()
	{
		deltaTime = 0.0f;
		timeScale = 1.0f;
	}
	Time(const Time& other)
	{
		deltaTime = 0.0f;
		timeScale = 1.0f;
	}
	~Time() {}

	static Time* GetInstance();

	float deltaTime;
	float timeScale;
	void CalculateDeltaTime();

private:
	int pastTimeSinceStart = 0;

	static Time* instance;
};

Time* Time::instance = nullptr;
