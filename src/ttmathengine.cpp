#include "ttmathengine.hpp"

namespace TTMathEngine {
	Vector3::Vector3():x(0.0),y(0.0),z(0.0){}
	Vector3::Vector3(float iX, float iY, float iZ):x(iX), y(iY), z(iZ){}

	Vector3::~Vector3(){}
	
	Vector3::Vector3(const Vector3& v):x(v.x), y(v.y), z(v.z){}
	Vector3& Vector3::operator=(const Vector3& v) {
		this->x=v.x;
		this->y=v.y;
		this->z=v.z;
		
		return *this;
	}
	
	//Comparators
	bool Vector3::operator==(const Vector3& v) {
		if(this->x == v.x && this->y == v.y && this->z == v.z) {
			return true;
		}
		
		return false;
	}
	
	bool Vector3::operator!=(const Vector3& v) {
		if(!(this->x == v.x && this->y == v.y && this->z == v.z)) {
			return true;
		}
		
		return false;
	}
	
	//Alter and assign
	void Vector3::operator+=(const Vector3& v) {
		this->x+=v.x;
		this->y+=v.y;
		this->z+=v.z;
	}
	
	void Vector3::operator-=(const Vector3& v) {
		this->x-=v.x;
		this->y-=v.y;
		this->z-=v.z;
	}
	
	//Algebraic
	Vector3 Vector3::operator+(const Vector3& v)const {
		return Vector3(this->x+v.x;this->y+v.y;this->z+v.z);
	}
	
	Vector3 Vector3::operator-(const Vector3& v)const {
		return Vector3(this->x-v.x;this->y-v.y;this->z-v.z);
	}
	
	//The really stupid idea
	
}