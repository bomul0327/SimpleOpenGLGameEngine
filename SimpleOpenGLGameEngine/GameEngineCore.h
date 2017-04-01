#pragma once

#include <GL\glut.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>

void SetOpenGLCallback(int argc, char ** argv, int windowSizeX = 500, int windowSizeY = 500, char* title = "SimpleOpenGLGameEngine_Play");
//OpenGL Callback Function
void Init(void);
void Reshape(int width, int height);
void Display();
void Idle();
void MousePress(GLint button, GLint state, GLint mousePosX, GLint mousePosY);
void MouseMotion(GLint mousePosX, GLint mousePosY);
void MousePassiveMotion(GLint mousePosX, GLint mousePosY);
void KeyboardPress(unsigned char key, GLint mousePosX, GLint mousePosY);

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

struct Transform {
public:
	Vector3 position;
	Vector3 rotation; //TODO: change rotation to use Quaternion (To solve Gimbal Lock problem)
	Vector3 scale;
public:
	Transform() {
		position = Vector3::zero;
		rotation = Vector3::zero;
		scale = Vector3::one;
	}
};

//GameEngine Classes

//Basic Object in the game
//You need to inherit this class to implement your object
class Actor {
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

//Time class (Singleton)
class Time { 
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

//Input class (Singleton)
//TODO: Implement keyboard Input and Mouse Input
class Input {

};
